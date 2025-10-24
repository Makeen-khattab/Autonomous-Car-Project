#include "car_motion.h" 
#include "motor.h"

/*Initializing all chips on the Car*/
void Car_Init(void)
{
    void DcMotor_Init(TIMER0);
    void DcMotor_Init(TIMER2);

}


void Car_SetDirection(CAR_Direction direction, uint8 speed)
{
    switch (direction)
    {
        case Stop:
        DcMotor_Rotate(DCMOTOR_STOP,0,TIMER0);
        DcMotor_Rotate(DCMOTOR_STOP,0,TIMER2);
        break;

        case Forward:
        DcMotor_Rotate(DCMOTOR_ACW,speed,TIMER0);
        DcMotor_Rotate(DCMOTOR_ACW,speed,TIMER2);
        break;

        case Backward:
        DcMotor_Rotate(DCMOTOR_CW,speed,TIMER0);
        DcMotor_Rotate(DCMOTOR_CW,speed,TIMER2);
        break;

        case Right:
        DcMotor_Rotate(DCMOTOR_ACW,speed,TIMER0);
        DcMotor_Rotate(DCMOTOR_STOP,speed,TIMER2);
        break;

        case Left:
        DcMotor_Rotate(DCMOTOR_STOP,speed,TIMER0);
        DcMotor_Rotate(DCMOTOR_ACW,speed,TIMER2);
        break;
        default:
        ;
    }

}

/**
 * Returns the last commanded car direction.
 * return Current direction (Forward, Backward, etc.)
 */
CAR_Direction Car_GetDirection(void)
{

}
