/*
* Keypad.h
*
* Created: 5/3/2020 8:58:24 PM
*  Author: user
*/


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "LCD.h"
#include "DIO_CFG.h"
#define Calc_MAX 8
#define KeyPad_DDR DDRD_Reg
#define KeyPad_PORT PORTD_Reg
#define KeyPad_PIN PIND_Reg

#define r1 DIO_ChannelD0
#define r2 DIO_ChannelD1
#define r3 DIO_ChannelD2
#define r4 DIO_ChannelD3

#define Calc_LED DIO_ChannelA0
#define Calc_BUZZER DIO_ChannelA1

void Check_C1();
void Check_C2();
void Check_C3();
void Check_C4();
void SHOW_RESULT(char *num1 , char *num2 , char op);
long int convertToInt(char * number);
char *convertToChar(long int number);
void free_arrays(char *arr1 , char *arr2 , char *arr3);



#endif /* KEYPAD_H_ */