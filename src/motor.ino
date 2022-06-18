void motor_update(Motor motor) {
  switch (motor.power_state) {
    case ON:
      switch (motor.direction) {
	case CW:
	  digitalWrite(motor.signal_pin_1, HIGH);
	  digitalWrite(motor.signal_pin_2, LOW);
	  break;
	case CCW:
	  digitalWrite(motor.signal_pin_1, LOW);
	  digitalWrite(motor.signal_pin_2, HIGH);
	  break;
      }
      break;
    case OFF:
      digitalWrite(motor.signal_pin_1, HIGH);
      digitalWrite(motor.signal_pin_2, HIGH);
      break;
  }
  int speed_mapped = int(motor.speed * 255.0);
  analogWrite(motor.speed_control_pin, speed_mapped);
}

void motor_init(Motor motor) {
  pinMode(motor.signal_pin_1, OUTPUT);
  pinMode(motor.signal_pin_2, OUTPUT);
  pinMode(motor.speed_control_pin, OUTPUT);
  motor_update(motor);
}

Motor new_motor(int signal_pin_1, int signal_pin_2, int speed_control_pin) {
  Motor return_motor = {.signal_pin_1 = signal_pin_1,
			.signal_pin_2 = signal_pin_2,
			.speed_control_pin = speed_control_pin};
  return_motor.speed = 1;
  return_motor.direction = CW;
  return_motor.power_state = OFF;
  motor_init(return_motor);
  return return_motor;
}

void motor_speed_change(Motor motor, float speed) {
	Serial.print("Motor speed changed: ");
	Serial.print(motor.speed);
	Serial.print("To ");
	Serial.println(speed);
  motor.speed = speed;
  motor_update(motor);
}

void motor_direction_change(Motor motor, MotorSpinDirection direction) {
  motor.direction = direction;
  motor_update(motor);
}

void motor_power_change(Motor motor, MotorPowerState power_state) {
  motor.power_state = power_state;
  motor_update(motor);
}
