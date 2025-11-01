#ifndef TIMER0_H_
#define TIMER0_H_

#include "Std_Types.h"


/*#define NORMALMODE							0x00
#define PWM_PHASECORRECT_MODE					0x01
#define CTC_MODE								0x02
#define FAST_PWM_MODE							0x03*/

#define OC0_DISCONNECTED						0x00
#define RESERVED								0x01
#define NONINVERTING							0x02
#define INVERTING								0x03

#define NOCLOCK									0x00
#define PRESCALER_1								0x01
#define PRESCALER_8								0x02
#define PRESCALER_64							0x03
#define PRESCALER_256							0x04
#define PRESCALER_1024							0x05
#define EXTERNALCLKFALL							0x06
#define EXTERNALCLKRISE							0x07

#define MAXCOUNT								0xFF


void PWM_Timer0_init(void);
void PWM_Timer0_Start(uint8 a_dutyCycle);


#endif /* TIMER0_H_ */
