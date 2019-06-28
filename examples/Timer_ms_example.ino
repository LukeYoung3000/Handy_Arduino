/*
The following code blinks the Arduino UNOs pin 13 LED at peroid of 500 milli
seconds useing the Timer_ms class.
*/

#define LED 13
#include <Handy_Arduino_Lib.h>

Timer_ms timer(500);

void setup()
{
    pinMode(LED, OUTPUT);
    timer.reset_timer();
}

void loop()
{
    if (timer.check_overflow())
    {
        digitalWrite(LED, !digitalRead(LED));
        timer.reset_timer();
    }
}