#include"timer2.h"
#include "avr/io.h"
#include"gpio.h"
#include "Common_Macros.h"
void PWM_Timer2_init(void)
{
	CLEAR_BIT(TCCR2,FOC2);
	SET_BIT(TCCR2,WGM21);
	SET_BIT(TCCR2,WGM20);
	/*Using Non-inverting Mode*/
	CLEAR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	CLEAR_BIT(TIMSK,TOIE2);
GPIO_setupPinDirection(PORTD_ID,PIN7_ID, PIN_OUTPUT);
}

void PWM_Timer2_Start(uint8 a_dutyCycle)
{

if( a_dutyCycle==0)
{
	TCCR2=(TCCR2&0xF8) |((NOCLOCK)& 0x07);


}
else
{
TCCR2=(TCCR2&0xF8) |((PRESCALER_1)& 0x07);

TCNT2 =0;

OCR2= (uint16)(a_dutyCycle * MAXCOUNT) /100;
}

}

void PWM_Timer2_deInit(void)
{
	TCNT2 =0;
	TCCR2=0;
	OCR2=0;
}

