
#include "LCD.h"


void LCD_INIT(void){
	DIO_Init();
	DIO_WriteChannel(LCD_RW,STD_Low);
	
	_delay_ms(20);
	LCD_COMMAND(0x33);
	LCD_COMMAND(0x32);
	LCD_COMMAND(0x28); //function set
	LCD_COMMAND(0x06); //entry mode
	LCD_COMMAND(0x0C); //Display on/off
	LCD_COMMAND(0x01); //Clear Screen
	_delay_ms(2);
}

void LCD_COMMAND(uint8 cmd){
	
	uint8 Send_Command = 0;
	Send_Command = (PORTA_Reg & 0x0F) | (cmd & 0xF0); //to send high nipple
	DIO_WritePort(LCD_Data_Port,Send_Command);
	DIO_WriteChannel(LCD_RS,STD_Low);//set RS to zero
	DIO_WriteChannel(LCD_E,STD_Higt);
	_delay_us(20);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_ms(2);
	
	Send_Command = (PORTA_Reg & 0x0F) | (cmd<<4);//to send the Low nipple
	DIO_WritePort(LCD_Data_Port,Send_Command);
	DIO_WriteChannel(LCD_RS,STD_Low);//set RS to zero
	DIO_WriteChannel(LCD_E,STD_Higt);
	_delay_us(20);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_ms(2);
	
}

void LCD_Char(uint8 data){
	
	uint8 Send_Command = 0;
	Send_Command = (PORTA_Reg & 0x0F) | (data & 0xF0); //to send high nipple
	DIO_WritePort(LCD_Data_Port,Send_Command);
	DIO_WriteChannel(LCD_RS,STD_Higt);//set RS to zero
	DIO_WriteChannel(LCD_E,STD_Higt);
	_delay_us(20);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_ms(2);
	
	Send_Command = (PORTA_Reg & 0x0F) | (data<<4);//to send the Low nipple
	DIO_WritePort(LCD_Data_Port,Send_Command);
	DIO_WriteChannel(LCD_RS,STD_Higt);//set RS to zero
	DIO_WriteChannel(LCD_E,STD_Higt);
	_delay_us(20);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_ms(2);
	
}

void LCD_STRING(char * string){
	uint8 i = 0;
	while(string[i] != '\0'){
		LCD_Char(string[i]);
		i++;
	}
}

void LCD_CharPos(uint8 line , uint8 pos , uint8 data){
	
	switch(line){
		case 1:
		if(pos < 16){
			LCD_COMMAND(0x80 | (pos & 0x0F));  // Line Num One
			LCD_Char(data);
		}
		break;
		
		case 2:
		if(pos < 16){
			LCD_COMMAND(0xC0 | (pos & 0x0F));  // Line Num One
			LCD_Char(data);
		}
		break;
	}
	
}

void LCD_StringPos(uint8 line , uint8 pos , char * string){
	
	switch(line){
		case 1:
		LCD_COMMAND(0x80 | (pos & 0x0F));  // Line Num One
		LCD_STRING(string);
		break;
		
		case 2:
		LCD_COMMAND(0xC0 | (pos & 0x0F));  // Line Num One
		LCD_STRING(string);
		break;
	}
	
}

void LCD_SPChar(uint8 loc , char * msg){
	
	uint8 i = 0;
	if(loc < 8){
		LCD_COMMAND(0x40 + (loc*8));
		for (i ; i < 8 ; i++)
		{
			LCD_Char(msg[i]);
		}
	}
	
}