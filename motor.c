#include "motor.h"
#include "gpio.h"
#include "timer0.h"

void DcMotor_Init(PWM_Timer timer)
{
	if(timer == TIMER0)
	{
		GPIO_setupPinDirection(DCMOTOR1_PORTID	,DCMOTOR1_PIN1ID, PIN_OUTPUT);
		GPIO_setupPinDirection(DCMOTOR1_PORTID	,DCMOTOR1_PIN2ID, PIN_OUTPUT);
	}
	else if (timer == TIMER2)
	{
		GPIO_setupPinDirection(DCMOTOR2_PORTID	,DCMOTOR2_PIN1ID, PIN_OUTPUT);
		GPIO_setupPinDirection(DCMOTOR2_PORTID	,DCMOTOR2_PIN2ID, PIN_OUTPUT);
	}

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed,PWM_Timer timer)
{
	switch (state)
	{
	case DCMOTOR_STOP :
		if(timer == TIMER0)
		{
			GPIO_writePin(DCMOTOR1_PORTID,DCMOTOR1_PIN1ID, LOGIC_LOW);
			GPIO_writePin(DCMOTOR1_PORTID,DCMOTOR1_PIN2ID, LOGIC_LOW);
			PWM_Timer0_deInit();
		}	
		else if(timer == TIMER2)
		{
			GPIO_writePin(DCMOTOR2_PORTID,DCMOTOR2_PIN1ID, LOGIC_LOW);
			GPIO_writePin(DCMOTOR2_PORTID,DCMOTOR2_PIN2ID, LOGIC_LOW);
			PWM_Timer2_deInit();
		}

		break;
	case DCMOTOR_ACW :
		if(timer == TIMER0)
		{
			GPIO_writePin(DCMOTOR1_PORTID,DCMOTOR1_PIN1ID, LOGIC_LOW);
			GPIO_writePin(DCMOTOR1_PORTID,DCMOTOR1_PIN2ID, LOGIC_HIGH);
			
		}	
		else if(timer == TIMER2)
		{
			GPIO_writePin(DCMOTOR2_PORTID,DCMOTOR2_PIN1ID, LOGIC_LOW);
			GPIO_writePin(DCMOTOR2_PORTID,DCMOTOR2_PIN2ID, LOGIC_HIGH);
			
		}
		break;		
	case DCMOTOR_CW :
		if(timer == TIMER0)
		{
			GPIO_writePin(DCMOTOR1_PORTID,DCMOTOR1_PIN1ID, LOGIC_HIGH);
			GPIO_writePin(DCMOTOR1_PORTID,DCMOTOR1_PIN2ID, LOGIC_LOW);
			
		}	
		else if(timer == TIMER2)
		{
			GPIO_writePin(DCMOTOR2_PORTID,DCMOTOR2_PIN1ID, LOGIC_HIGH);
			GPIO_writePin(DCMOTOR2_PORTID,DCMOTOR2_PIN2ID, LOGIC_LOW);
			
		}
		break;
	default:
		;
	}
	if(timer == TIMER0 && state != DCMOTOR_STOP)
	{
		PWM_Timer0_Start(speed);
	}
	else if(timer == TIMER2 && state != DCMOTOR_STOP)
	{
		PWM_Timer2_Start(speed);
	}

}


