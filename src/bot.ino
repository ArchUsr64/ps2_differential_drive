void bot_update(Bot bot) {
  bot.left_motor.power_state = bot.power_state;
  bot.right_motor.power_state = bot.power_state;
  Vector speed_scalar;
	speed_scalar.left = 1;
	speed_scalar.right = 1;
  if (bot.bias_to_left_motor >= 0) {
    speed_scalar.right -= bot.bias_to_left_motor;
  } else {
    speed_scalar.left += bot.bias_to_left_motor;
  }
  bot.left_motor.speed = bot.speed * speed_scalar.left;
  bot.right_motor.speed = bot.speed * speed_scalar.right;
  switch (bot.direction) {
    case FORWARD:
      bot.left_motor.direction = CCW;
      bot.right_motor.direction = CW;
      break;
    case BACKWARD:
      bot.left_motor.direction = CW;
      bot.right_motor.direction = CCW;
      break;
    case LEFT:
      bot.left_motor.direction = CW;
      bot.right_motor.direction = CW;
      break;
    case RIGHT:
      bot.left_motor.direction = CCW;
      bot.right_motor.direction = CCW;
      break;
  }
  motor_update(bot.left_motor);
  motor_update(bot.right_motor);
}

void bot_init(Bot bot) {
  motor_init(bot.left_motor);
  motor_init(bot.right_motor);
  bot_update(bot);
}

Bot new_bot(int left_motor_signal_pin_1, int left_motor_signal_pin_2,
	    int left_motor_speed_control_pin, int right_motor_signal_pin_1,
	    int right_motor_signal_pin_2, int right_motor_speed_control_pin) {
  Bot return_bot = {
      new_motor(left_motor_signal_pin_1, left_motor_signal_pin_2,
		left_motor_speed_control_pin),
      new_motor(right_motor_signal_pin_1, right_motor_signal_pin_2,
		right_motor_speed_control_pin),
  };
  return_bot.power_state = ON;
  return_bot.direction = FORWARD;
  return_bot.speed = 1;
  return_bot.bias_to_left_motor = 0;
  bot_init(return_bot);
  return return_bot;
}

void bot_power_change(Bot bot, BotPowerState power_state) {
  bot.power_state = power_state;
  bot_update(bot);
}

void bot_direction_change(Bot bot, BotDirection direction) {
  bot.direction = direction;
  bot_update(bot);
}

void bot_speed_change(Bot bot, float speed) {
  bot.speed = speed;
  bot_update(bot);
}

void bot_bias_to_left_motor_change(Bot bot, float bias) {
  bot.bias_to_left_motor = bias;
  bot_update(bot);
}
