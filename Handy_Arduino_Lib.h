// Handy Arduino Library
// https://github.com/LukeYoung3000/Handy_Arduino
// Copyright (C) 2018 by Luke Young and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

#ifndef Handy_Arduino_Lib_INCLUDED
#define Handy_Arduino_Lib_INCLUDED

#include <Arduino.h>

class Debounce
{
public:
  //Constructor
  Debounce(int Switch_pin, int Debounce_time_ms);

  void main_loop(void);

  boolean pressed(void);

private:
  // Variables
  unsigned long last_read_time;
  boolean state;
  boolean state_reset;
  boolean prev_state;
  int switch_pin;
  int debounce_time_ms;
  boolean flag;
};

class Timer_ms
{
private:
  // Variables
  unsigned long time_limit;
  unsigned long time_start;
  boolean overflow_flag;

public:
  //Constructor
  Timer_ms(unsigned long Time_limit);

  boolean check_overflow();

  void reset_timer();
};

#endif
