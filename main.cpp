#include "mbed.h"

PwmOut PWM1(D6);
AnalogIn Ain(A0);

int main()
{
    float width[20] = {0.2f, 0.4f, 0.6f , 0.8f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f , 1.0f, 0.8f, 0.6f, 0.4f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    
    while (1) {
        PWM1.period_ms(5);
        PWM1 = Ain;
        
        for (int i = 0; i <= 19; i++) {
            PWM1.pulsewidth_ms(5 * width[i]);
            ThisThread::sleep_for(50ms);
            printf("%f\n\r", PWM1.read());
        }
        
    } 
}
