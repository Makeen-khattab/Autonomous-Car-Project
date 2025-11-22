#include"timer0.h"
#include "avr/io.h"
#include"gpio.h"
#include "Common_Macros.h"
void PWM_Timer0_init(void)
{
	CLEAR_BIT(TCCR0,FOC0);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
	/*Using Non-inverting Mode*/
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TIMSK,TOIE0);
GPIO_setupPinDirection(PORTB_ID,PIN3_ID, PIN_OUTPUT);
}

void PWM_Timer0_Start(uint8 a_dutyCycle)
{

if( a_dutyCycle==0)
{
	TCCR0=(TCCR0&0xF8) |((NOCLOCK)& 0x07);


}
else
{
TCCR0=(TCCR0&0xF8) |((PRESCALER_1)& 0x07);

TCNT0 =0;

OCR0= (uint16)(a_dutyCycle * MAXCOUNT) /100;
}

}

void PWM_Timer0_deInit(void)
{
	TCNT0 =0;
	TCCR0=0;
	OCR0=0;
}

