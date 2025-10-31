/*
 * main.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Sohaila Ahmed
 */

#include "gpio.h"
#include "car_motion.h"
#include "motor.h"

int main(void)
{
	uint8 speed = 150; //just a test number

	//IR Sensors
	GPIO_setupPinDirection(PORTC_ID,PIN0_ID,PIN_INPUT);  /* PC0 Input Pin */
	GPIO_setupPinDirection(PORTC_ID,PIN1_ID,PIN_INPUT);  /* PC1 Input Pin */

	//Init
	Car_Init();
	PWM_Timer0_init();
	PWM_Timer2_init();

	/* Turn off the motor */
	DcMotor_Rotate(DCMOTOR_STOP, speed, TIMER0);
	DcMotor_Rotate(DCMOTOR_STOP, speed, TIMER2);

	while(1)
	{
		/* Read PA0 Pin Value */
		if((GPIO_readPin(PORTC_ID,PIN0_ID) == LOGIC_HIGH) && (GPIO_readPin(PORTC_ID,PIN1_ID) == LOGIC_HIGH))
		{
			Car_SetDirection(Forward, speed);
		}
		/* Read PA1 Pin Value */
		else if((GPIO_readPin(PORTC_ID,PIN0_ID) == LOGIC_HIGH) && (GPIO_readPin(PORTC_ID,PIN1_ID) == LOGIC_LOW))
		{
			Car_SetDirection(Left, speed);
		}
		else if((GPIO_readPin(PORTC_ID,PIN0_ID) == LOGIC_LOW) && (GPIO_readPin(PORTC_ID,PIN1_ID) == LOGIC_HIGH))
		{
			Car_SetDirection(Right, speed);
		}
		else if((GPIO_readPin(PORTC_ID,PIN0_ID) == LOGIC_LOW) && (GPIO_readPin(PORTC_ID,PIN1_ID) == LOGIC_LOW))
		{
			Car_SetDirection(Stop, speed);
		}
	}
	return 0;
}



