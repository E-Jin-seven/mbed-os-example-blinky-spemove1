//onoff制御用最新
#include "mbed.h"
#include "platform/mbed_thread.h"
#include <cstdio>
#define BLINKING_RATE_MS1                                                    10
#define VCC (3.3)

DigitalOut Digt1_R(D5);
PwmOut mypwm_R(D9);

DigitalOut Digt1_L(D2);
PwmOut mypwm_L(D1);

AnalogIn Ain1(A2);
AnalogIn Ain2(A1);
AnalogIn Ain3(A0);

int main()
{
    mypwm_R.period(0.0001f);
    Digt1_R = 0;

    mypwm_L.period(0.0001f);
    Digt1_L = 0;

    while(1){

        float norm_R = Ain1.read();
        float perc_R = norm_R * 100;

        float norm_L = Ain2.read();
        float perc_L = norm_L * 100;

        float norm_F = Ain3.read();
        float perc_F = norm_F * 100;

        if(perc_F>=70){
            if(perc_R>90){
                mypwm_R.write(0.3);
                mypwm_L.write(0.7);
            }

        }
        else{
                mypwm_R.write(0.4);
                mypwm_L.write(0.5);
            }
        }
        thread_sleep_for(BLINKING_RATE_MS1);
    }
}