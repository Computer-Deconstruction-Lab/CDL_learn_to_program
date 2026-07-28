/*
  LED & Servo Learn-to-Program Lab
  Raspberry Pi Pico W, Arduino IDE
  ----------------------------------------------------------------------------
  Implements the FSD: led-servo-learn-to-program-lab-fsd_V1.md / .pdf

  Behavior:
    - 4 LEDs (red, green, yellow, blue) light in a repeating chase sequence,
      one at a time (REQ-001, REQ-002, REQ-003).
    - A servo sweeps back and forth between 0 deg and 180 deg in 1-degree
      steps (REQ-004). Each one-way leg takes ~10 seconds when "slow" or
      ~2 seconds when "fast" (REQ-005); the first leg is slow (REQ-006) and
      speed alternates every leg thereafter, forever (REQ-007).
    - Both behaviors run at the same time using millis()-based timing instead
      of delay(), so neither one blocks the other (REQ-011).

  Wiring (see FSD Section 4.1 / Figure 1):
    GP2  -- 330 ohm resistor -- Red LED    -- GND
    GP3  -- 330 ohm resistor -- Green LED  -- GND
    GP4  -- 330 ohm resistor -- Yellow LED -- GND
    GP5  -- 330 ohm resistor -- Blue LED   -- GND
    GP15 -- Servo signal (orange wire)
    VBUS -- Servo power (red wire, 5V from laptop USB)
    GND  -- Servo ground (black wire)

  Board package : "Raspberry Pi Pico/RP2040" by Earle Philhower
  Board selected: Raspberry Pi Pico W
  Upload        : hold BOOTSEL while plugging in USB the first time, then
                  use the IDE's Upload button (see FSD Section 3).
*/

#include <Servo.h>

// ---------------------------------------------------------------------------
// Named constants (snake_case) — REQ-010: no magic numbers for pins/timing
// ---------------------------------------------------------------------------
const int led_pins[4] = {2, 3, 4, 5};   // GP2, GP3, GP4, GP5: red, green, yellow, blue
const int servo_pin   = 15;             // GP15

const unsigned long led_on_time_ms = 300;   // REQ-003: dwell time per LED

const int min_angle_deg  = 0;     // REQ-004
const int max_angle_deg  = 180;   // REQ-004
const int servo_step_deg = 1;     // REQ-004: degrees per step

// REQ-005: total time for one full leg (0->180 or 180->0)
const long sweep_time_slow_ms = 10000;   // ~10 s when slow
const long sweep_time_fast_ms = 2000;    // ~2 s when fast

// Per-step delay = total leg time / number of steps (180 steps per leg at 1 deg/step)
const int step_delay_slow_ms = 56;   // 56 ms * 180 steps ~= 10.08 s
const int step_delay_fast_ms = 11;   // 11 ms * 180 steps ~= 1.98 s

// ---------------------------------------------------------------------------
// Global state
// ---------------------------------------------------------------------------
Servo pico_servo;

int           current_led_index  = 0;
unsigned long led_last_change_ms = 0;

int           servo_current_angle_deg = 0;             // starts at min_angle_deg
int           servo_direction_deg     = 1;              // +1 or -1, in units of servo_step_deg
bool          sweep_is_slow_leg       = true;           // REQ-006: first leg is slow
unsigned long servo_last_step_ms      = 0;

void setup() {
  setup_leds();
  setup_servo();
}

void loop() {
  run_led_sequence();
  update_servo_sweep();
}

// ---------------------------------------------------------------------------
// LED sequence (REQ-001, REQ-002, REQ-003)
// ---------------------------------------------------------------------------
void setup_leds() {
  for (int i = 0; i < 4; i++) {
    pinMode(led_pins[i], OUTPUT);
    digitalWrite(led_pins[i], LOW);
  }
  digitalWrite(led_pins[current_led_index], HIGH);   // light the first LED
  led_last_change_ms = millis();
}

void run_led_sequence() {
  if (millis() - led_last_change_ms >= led_on_time_ms) {
    digitalWrite(led_pins[current_led_index], LOW);          // REQ-002: off before next on
    current_led_index = (current_led_index + 1) % 4;
    digitalWrite(led_pins[current_led_index], HIGH);
    led_last_change_ms = millis();
  }
}

// ---------------------------------------------------------------------------
// Servo sweep (REQ-004, REQ-005, REQ-006, REQ-007)
// ---------------------------------------------------------------------------
void setup_servo() {
  pico_servo.attach(servo_pin);
  servo_current_angle_deg = min_angle_deg;
  servo_direction_deg = servo_step_deg;
  pico_servo.write(servo_current_angle_deg);
  servo_last_step_ms = millis();
}

int current_step_delay_ms() {
  return sweep_is_slow_leg ? step_delay_slow_ms : step_delay_fast_ms;
}

void update_servo_sweep() {
  if (millis() - servo_last_step_ms < (unsigned long)current_step_delay_ms()) {
    return;   // not time for the next 1-degree step yet
  }
  servo_last_step_ms = millis();

  servo_current_angle_deg += servo_direction_deg;
  pico_servo.write(servo_current_angle_deg);

  bool reached_end = (servo_current_angle_deg >= max_angle_deg) ||
                      (servo_current_angle_deg <= min_angle_deg);
  if (reached_end) {
    servo_current_angle_deg = constrain(servo_current_angle_deg, min_angle_deg, max_angle_deg);
    servo_direction_deg = -servo_direction_deg;   // reverse direction (ping-pong, REQ-004)
    sweep_is_slow_leg = !sweep_is_slow_leg;        // REQ-007: alternate speed every leg
  }
}

/*
  ----------------------------------------------------------------------------
  Suggested modifications (REQ-009) — try these to make the project your own:

  1. Add a 5th LED: add its GPIO pin to led_pins[], and change every
     hardcoded "4" in setup_leds()/run_led_sequence() to a named constant
     like num_leds = 5.
  2. Reverse the servo's starting direction: change servo_direction_deg's
     initial value in setup_servo() from servo_step_deg to -servo_step_deg.
  3. Change the speed thresholds: edit sweep_time_slow_ms / sweep_time_fast_ms,
     then recompute step_delay_slow_ms / step_delay_fast_ms as
     (total_ms / (180 / servo_step_deg)).
  4. Narrow the servo's range: change min_angle_deg / max_angle_deg to, say,
     45 and 135, for a smaller sweep.
  5. Make the LED sequence "bounce" instead of loop: have current_led_index
     count up to 3 then back down to 0, instead of wrapping with %.
  ----------------------------------------------------------------------------
*/
