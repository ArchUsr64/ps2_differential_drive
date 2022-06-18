#ifndef MOTOR_H_
#define MOTOR_H_

typedef enum _MotorSpinDirection {
  CW,
  CCW,
} MotorSpinDirection;
typedef enum _MotorPowerState {
  ON,
  OFF,
} MotorPowerState;
typedef struct _Motor {
  int signal_pin_1;
  int signal_pin_2;
  int speed_control_pin;
  float speed;
  MotorSpinDirection direction;
  MotorPowerState power_state;
} Motor;

#endif
