/*
 * MOTOR_H_
 *
 *  Created on: Feb 24, 2024
 *      Author: Dell
 */
#ifndef MOTOR_H_
#define MOTOR_H_

#include "Std_Types.h"
#define DCMOTOR1_PORTID					PORTA_ID
#define DCMOTOR1_PIN1ID					PIN0_ID
#define DCMOTOR1_PIN2ID					PIN1_ID

#define DCMOTOR2_PORTID					PORTB_ID
#define DCMOTOR2_PIN1ID					PIN0_ID
#define DCMOTOR2_PIN2ID					PIN1_ID

typedef enum {
	 TIMER0, 
	 TIMER2 
	} PWM_Timer;


typedef enum
{
	DCMOTOR_STOP,
	DCMOTOR_ACW,
	DCMOTOR_CW

}DcMotor_State;



void DcMotor_Init(void);
/*Speed ranges from 0% --> 100% */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
