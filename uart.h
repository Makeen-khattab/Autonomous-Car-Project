#ifndef UART_H_
#define UART_H_

#include "Std_Types.h"

#define UART_INTERRUPTMODE 						   0
#define UART_POLLINGMODE						   1

#if (UART_INTERRUPTMODE == 1)
extern uint8 g_UART_firstStringFinished;
#define UART_MAXSIZEOFSTRING					  20
#endif

#define UART_DOUBLESPEEDMODE					  1
#define UART_NORMALMODE							  0

typedef enum
{
	UART_FIVEBITMODE,
	UART_SIXBITMODE,
	UART_SEVENBITMODE,
	UART_EIGHTBITMODE,
	UART_NINEBITMODE=0x07
}UART_BitData;

typedef enum
{
	UART_BAUDRATE1200=1200,
	UART_BAUDRATE2400=2400,
	UART_BAUDRATE4800=4800,
	UART_BAUDRATE9600=9600,
	UART_BAUDRATE19200=19200,
	UART_BAUDRATE38400=38400,
	UART_BAUDRATE57600=57600,
	UART_BAUDRATE115200=115200 ,
	UART_BAUDRATE250000=250000
}UART_BaudRate;

typedef enum
{
	UART_PARITYDISABLED,
	UART_PARITYENABLED,
	UART_PARITYEVEN,
	UART_PARITYODD
} UART_Parity;


typedef enum
{
	UART_ONESTOP,
	UART_TWOSTOP,
}UART_StopBit;







typedef struct
{
	 UART_BitData bit_data;
	 UART_Parity parity;
	 UART_StopBit stop_bit;
	 UART_BaudRate baud_rate;
}UART_ConfigType;



#define UART_HANDSHAKING						'#'
void UART_init(UART_ConfigType*config_ptr);
void UART_sendByte(const uint8 a_data);
#if (UART_INTERRUPTMODE == 1)
void UART_setCallBack(void (setCallBack_Ptr)(void));
#endif
uint8 UART_recieveByte(void);
void UART_sendString(const uint8*str);
void UART_recieveString(uint8*str);


#endif /* UART_H_ */
