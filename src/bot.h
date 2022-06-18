#include "motor.h"

#ifndef BOT_H_
#define BOT_H_

typedef MotorPowerState BotPowerState;
typedef enum _BotDirection {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
} BotDirection;
typedef struct _Bot {
  Motor left_motor;
  Motor right_motor;
  BotPowerState power_state;
  BotDirection direction;
  float speed;
	float bias_to_left_motor;
} Bot;

#endif
