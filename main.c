#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include "car_motion.h"
#include "uart.h"
#include "timer0.h"
#include "gpio.h"
#include "timer2.h"

typedef enum{
    Normal_Mode = 'N',
	Lane_Detection_Mode = 'D',
	GetOut_Mode = 'G'
}CAR_Modes;

void init()
{
	/*Has the Motors initialization inside*/
	Car_Init();
	/*Initializing timers for duty cycle control*/
	PWM_Timer0_init();
	PWM_Timer2_init();
	/*Initializing UART for Bluetooth connection*/
	UART_ConfigType UART_attributes ={UART_EIGHTBITMODE,UART_PARITYDISABLED,UART_ONESTOP,UART_BAUDRATE9600};
	UART_init(&UART_attributes);

}

void Car_Normal_Mode()
{
	uint8 a_carDirection;
	while(1)
	{


	/*Receiving the car direction from the mobile application*/
		a_carDirection = UART_recieveByte();

			switch (a_carDirection)
			{
			case 'F':
				Car_SetDirection(Forward, FULLSPEED);

				break;
			case 'B':
				Car_SetDirection(Backward, FULLSPEED);
				break;
			case 'R':
				Car_SetDirection(Right, FULLSPEED);
				break;
			case 'L' :
				Car_SetDirection(Left, FULLSPEED);
				break;
			default :
				Car_SetDirection(Stop, 0);
			}

			if(a_carDirection == Lane_Detection_Mode || a_carDirection == GetOut_Mode)
			{
				break;
			}

	}

}

void Car_Lane_Detection_Mode()
{
	uint8 speed = 100; //full speed
		uint16 ir1_out;
		uint16 ir2_out;

		/*IR Sensors*/
		//GPIO_setupPinDirection(PORTC_ID,PIN5_ID,PIN_INPUT);  /* PC5 Input Pin */
		//GPIO_setupPinDirection(PORTC_ID,PIN6_ID,PIN_INPUT);  /* PC6 Input Pin */

		/*Init*/
		ADC_init();
		Car_Init();

		/* Turn off the car to initialize*/
		Car_SetDirection(Stop, speed);

		while(1)
		{
			/*reading adc channe*/
			ir1_out = ADC_readChannel(1);
			ir2_out = ADC_readChannel(2);

			/* Read PA0 Pin Value */
			if((ir1_out > 700) && (ir2_out > 700))
			{
				Car_SetDirection(Forward, speed);
			}
			/* Read PA1 Pin Value */
			else if((ir1_out > 700) && (ir2_out < 300))
			{
				Car_SetDirection(Left, speed);
			}
			else if((ir1_out < 300) && (ir2_out > 700))
			{
				Car_SetDirection(Right, speed);
			}
			else if((ir1_out < 300) && (ir2_out < 300))
			{
				Car_SetDirection(Stop, speed);
			}
		}




}



int main()
{
	/*Initializing cars hardware resources*/
	init();
	uint8 a_carMode;


	/*Infinite Loop*/
	while(1)
	{
		/*Receiving the Mode from the Mobile Application*/
		a_carMode = UART_recieveByte();

		/*Switching to the selected mode*/
				switch (a_carMode)
				{
				case Normal_Mode:
					 Car_Normal_Mode();
					break;
				case Lane_Detection_Mode:
					Car_Lane_Detection_Mode();
					break;
				default :
					;

				}

	}

}






