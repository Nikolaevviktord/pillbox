#pragma once

#include <datatypes.h>
#include <utils.h>
#include <FastBot.h>

#include <GyverTM1637.h>

#include <EEPROM.h>

#include "/home/projects/pillbox/src/libs/bot.h"
#include "/home/projects/pillbox/src/libs/button.h"
#include "/home/projects/pillbox/src/libs/motor.h"
#include "/home/projects/pillbox/src/libs/speaker.h"
#include "/home/projects/pillbox/src/libs/time.h"

struct display_info {
	int _clk;
	int _dio;
};

byte stob(String _s) {
  byte res = _s[1] - '0';
  res += 10 * (_s[0] - '0');
  return res;
}
