#include <PS2X_lib.h>

#include "bot.h"
#include "math.h"
#include "motor.h"

Bot b;
PS2X ps2x;

int error = 0;

void setup() {
  pinMode(A1, OUTPUT);
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
	delay(2000);
  error = ps2x.config_gamepad(A4, A2, A5, A3, true, true);
  b = new_bot(10, 9, 11, 8, 7, 6);
}

void loop() {
  ps2x.read_gamepad();
  if (ps2x.ButtonPressed(PSB_PAD_LEFT)) bot_direction_change(b, LEFT);
  if (ps2x.ButtonPressed(PSB_PAD_RIGHT)) bot_direction_change(b, RIGHT);
  if (ps2x.ButtonPressed(PSB_PAD_UP)) bot_direction_change(b, FORWARD);
  if (ps2x.ButtonPressed(PSB_PAD_DOWN)) bot_direction_change(b, BACKWARD);
}
