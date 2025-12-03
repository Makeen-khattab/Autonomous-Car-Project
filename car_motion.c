#include "car_motion.h" 
#include "motor.h"

static CAR_Direction last_direction;
/*Initializing all chips on the Car*/
void Car_Init(void)
{
    DcMotor_Init(TIMER0);
    DcMotor_Init(TIMER2);

}


void Car_SetDirection(CAR_Direction direction, uint8 speed)
{
    switch (direction)
    {
        case Stop:
        DcMotor_Rotate(DCMOTOR_STOP,0,TIMER0);
        DcMotor_Rotate(DCMOTOR_STOP,0,TIMER2);
        last_direction = Stop;
        break;

        case Forward:
        DcMotor_Rotate(DCMOTOR_ACW,speed,TIMER0);
        DcMotor_Rotate(DCMOTOR_CW,speed,TIMER2);
        last_direction = Forward;
        break;

        case Backward:
        DcMotor_Rotate(DCMOTOR_CW,speed,TIMER0);
        DcMotor_Rotate(DCMOTOR_ACW,speed,TIMER2);
        last_direction = Backward;
        break;

        case Right:
        DcMotor_Rotate(DCMOTOR_ACW,speed,TIMER0);
        DcMotor_Rotate(DCMOTOR_STOP,speed,TIMER2);
        last_direction = Right;
        break;

        case Left:
        DcMotor_Rotate(DCMOTOR_STOP,speed,TIMER0);
        DcMotor_Rotate(DCMOTOR_CW,speed,TIMER2);
        last_direction = Left;
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
    return last_direction;
}
