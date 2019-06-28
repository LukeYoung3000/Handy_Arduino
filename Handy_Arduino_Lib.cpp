// Handy Arduino Library
// https://github.com/LukeYoung3000/Handy_Arduino
// Copyright (C) 2018 by Luke Young and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

#include <Arduino.h>
#include "Handy_Arduino_Lib.h"

//Constructor
Debounce::Debounce(int Switch_pin, int Debounce_time_ms)
{
	switch_pin = Switch_pin;
	debounce_time_ms = Debounce_time_ms;

	flag = 0;
	last_read_time = 0;
	state = 0;
	state_reset = 0;
	prev_state = 0;
}

void Debounce::main_loop(void)
{
	if (digitalRead(switch_pin) == LOW && state_reset == 0)
	{
		state_reset = 1;
		last_read_time = millis();
		flag = 1;
	}

	if (state_reset == 1)
	{

		if (millis() > (last_read_time + debounce_time_ms))
		{
			prev_state = state;
			state = digitalRead(switch_pin);
			last_read_time = millis();
		}

		if (state == 1 && prev_state == 1)
		{
			state = 0;
			prev_state = 0;
			state_reset = 0;
		}
	}
}

boolean Debounce::pressed(void)
{
	if (flag == 1)
	{
		flag = 0;
		return 1;
	}

	else
	{
		return 0;
	}
}

//Constructor
Timer_ms::Timer_ms(unsigned long Time_limit)
{
	time_limit = Time_limit;
	overflow_flag = 1;
	time_start = 0;
}

boolean Timer_ms::check_overflow()
{
	if (overflow_flag == 0)
	{
		if (millis() > (time_start + time_limit))
		{
			overflow_flag = 1;
			return 1;
		}
	}
	return 0;
}

void Timer_ms::reset_timer()
{
	time_start = millis();
	overflow_flag = 0;
}