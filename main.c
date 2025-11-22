#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include "car_motion.h"
#include "uart.h"
#include "timer0.h"
#include "timer2.h"

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
int main()
{
	init();
	CAR_Direction a_carDirection;


	/*Infinite Loop*/
	while(1)
	{
		a_carDirection = UART_recieveByte();
				switch (a_carDirection)
				{
				case Forward:
					Car_SetDirection(Forward, FULLSPEED);

					break;
				case Backward:
					Car_SetDirection(Backward, FULLSPEED);
					break;
				case Right:
					Car_SetDirection(Right, FULLSPEED);
					break;
				case Left :
					Car_SetDirection(Left, FULLSPEED);
					break;

				default :
					Car_SetDirection(Stop, 0);
					;

				}





	}





}
