#ifndef CAR_MOTION_H_
#define CAR_MOTION_H_
#include "motor.h" 
#include "Std_Types.h"

typedef enum{
    Stop='S',
	Forward='F',
	Backward='B',
	Right='R',
	Left='L',
}CAR_Direction;


void Car_Init(void);


/**
 * Sets the car direction and speed.
 * direction Desired car motion (Forward, Backward, Right, Left, Stop)
 * Speed value (0–100)
 */
void Car_SetDirection(CAR_Direction direction, uint8 speed);

/**
 * Returns the last commanded car direction.
 * return Current direction (Forward, Backward, etc.)
 */
CAR_Direction Car_GetDirection(void);

#endif /* CAR_MOTION_H_ */