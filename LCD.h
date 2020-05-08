
#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO_CFG.h"

#define LCD_Data_Port DIO_PORTA
#define LCD_Data_Dir DDRA_Reg

#define LCD_Control_Port DIO_PORTB
#define LCD_Control_Dir DDRB_Reg

#define LCD_RS DIO_ChannelB1
#define LCD_RW DIO_ChannelB2
#define LCD_E DIO_ChannelB3

void LCD_INIT(void);
void LCD_COMMAND(uint8 cmd);
void LCD_Char(uint8 data);
void LCD_STRING(char * string);
void LCD_CharPos(uint8 line , uint8 pos , uint8 data);
void LCD_StringPos(uint8 line , uint8 pos , char * string);
void LCD_SPChar(uint8 loc , char * msg);

#endif /* LCD_H_ */