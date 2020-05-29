/*
* Keypad.c
*
* Created: 5/3/2020 8:58:41 PM
*  Author: user
*/

#include "Keypad.h"
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>

int count = 0;
char first_num[Calc_MAX];
char second_num[Calc_MAX];
char result[Calc_MAX];
int stage = 0;
char operator = '+';

//--------------------------------
void Check_C1(){
	KeyPad_PORT = 0xEF;
	if (DIO_ReadChannel(r1) == STD_Low){
		LCD_Char('7');
		if(stage == 0){ // Check if still in first numb or not
			first_num[count] = '7';
			count++;
			}else{
			second_num[count] = '7';
			count++;
		}
		DIO_WriteChannel(Calc_LED , STD_Higt);
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		while(DIO_ReadChannel(r1) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//-------------------------------------------------------------
	else if (DIO_ReadChannel(r2) == STD_Low){
		LCD_Char('4');
		if(stage == 0){ // Check if still in first num or not
			first_num[count] = '4';
			count++;
			}else{
			second_num[count] = '4';
			count++;
		}
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r2) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//----------------------------------------------------------------
	else if (DIO_ReadChannel(r3) == STD_Low){
		LCD_Char('1');
		if(stage == 0){ // Check if still in first num or not
			first_num[count] = '1';
			count++;
			}else{
			second_num[count] = '1';
			count++;
		}
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r3) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//----------------------------------------------------------
	else if (DIO_ReadChannel(r4) == STD_Low){
		LCD_INIT();
		count = 0 ; stage = 0;
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r4) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
}
//--------------------------------
void Check_C2(){
	KeyPad_PORT = 0xDF;
	if (DIO_ReadChannel(r1) == STD_Low){
		LCD_Char('8');
		if(stage == 0){ // Check if still in first num or not
			first_num[count] = '8';
			count++;
			}else{
			second_num[count] = '8';
			count++;
		}
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r1) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//----------------------------------------------------------
	else if (DIO_ReadChannel(r2) == STD_Low){
		LCD_Char('5');
		if(stage == 0){ // Check if still in first num or not
			first_num[count] = '5';
			count++;
			}else{
			second_num[count] = '5';
			count++;
		}
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r2) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//-------------------------------------------------------------
	else if (DIO_ReadChannel(r3) == STD_Low){
		LCD_Char('2');
		if(stage == 0){ // Check if still in first num or not
			first_num[count] = '2';
			count++;
			}else{
			second_num[count] = '2';
			count++;
		}
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r3) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//----------------------------------------------------------------	
	else if (DIO_ReadChannel(r4) == STD_Low){
		LCD_Char('0');
		if(stage == 0){ // Check if still in first num or not
			first_num[count] = '0';
			count++;
			}else{
			second_num[count] = '0';
			count++;
		}
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r4) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
}
//--------------------------------
void Check_C3(){
	KeyPad_PORT = 0xBF;
	if (DIO_ReadChannel(r1) == STD_Low){
		LCD_Char('9');
		if(stage == 0){ // Check if still in first num or not
			first_num[count] = '9';
			count++;
			}else{
			second_num[count] = '9';
			count++;
		}
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r1) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//------------------------------------------------------
	else if (DIO_ReadChannel(r2) == STD_Low){
		LCD_Char('6');
		if(stage == 0){ // Check if still in first num or not
			first_num[count] = '6';
			count++;
			}else{
			second_num[count] = '6';
			count++;
		}
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r2) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//-----------------------------------------------------------
	else if (DIO_ReadChannel(r3) == STD_Low){
		LCD_Char('3');
		if(stage == 0){ // Check if still in first num or not
			first_num[count] = '3';
			count++;
			}else{
			second_num[count] = '3';
			count++;
		}
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r3) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//------------------------------------------------------------------
	else if (DIO_ReadChannel(r4) == STD_Low){
		
		LCD_Char('=');
		stage = 0;
		count = 0;
		SHOW_RESULT(first_num , second_num , operator);
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r4) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
}
//--------------------------------
// Operators
void Check_C4(){
	KeyPad_PORT = 0x7F;
	if (DIO_ReadChannel(r1) == STD_Low){
		stage = 1;
		count = 0;
		LCD_Char('/');
		operator = '/';
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r1) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//------------------------------------------------------------------------
	else if (DIO_ReadChannel(r2) == STD_Low){
		LCD_Char('*');
		stage = 1;
		count = 0;
		operator = '*';
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r2) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//-------------------------------------------------------------------------
	else if (DIO_ReadChannel(r3) == STD_Low){
		LCD_Char('-');
		stage = 1;
		count = 0;
		operator = '-';
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r3) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
	//---------------------------------------------------------------------------
	else if (DIO_ReadChannel(r4) == STD_Low){
		LCD_Char('+');
		count = 0;
		stage = 1;
		operator = '+';
		DIO_WriteChannel(Calc_BUZZER , STD_Higt);
		DIO_WriteChannel(Calc_LED , STD_Higt);
		while(DIO_ReadChannel(r4) == STD_Low);
		DIO_WriteChannel(Calc_LED , STD_Low);
		DIO_WriteChannel(Calc_BUZZER , STD_Low);
	}
}
//--------------------------------

void SHOW_RESULT(char *num1 , char *num2 , char op){
	long int resultOP = 0;

	switch(op){
		case '+':
		resultOP = convertToInt(num1) + convertToInt(num2);
		LCD_StringPos(2,0, "Result:");
		LCD_STRING(convertToChar(resultOP));
		resultOP = 0;
		free_arrays(result , first_num , second_num);
		break;
		//----------------------------------------------------------------------------
		case '-':
		resultOP = convertToInt(num1) - convertToInt(num2);
		LCD_StringPos(2,0, "Result:");
		LCD_STRING(convertToChar(resultOP));
		resultOP = 0;
		free_arrays(result , first_num , second_num);
		break;
		//----------------------------------------------------------------------------
		case '/':
		resultOP = convertToInt(num1) / convertToInt(num2);
		LCD_StringPos(2,0, "Result:");
		LCD_STRING(convertToChar(resultOP));
		resultOP = 0;
		free_arrays(result , first_num , second_num);
		break;
		//----------------------------------------------------------------------------
		case '*':
		resultOP = convertToInt(num1) * convertToInt(num2);
		LCD_StringPos(2,0, "Result:");
		LCD_STRING(convertToChar(resultOP));
		resultOP = 0;
		free_arrays(result , first_num , second_num);
		break;
	}
}

long int convertToInt(char * number){
	return atoi(number);
}

char *convertToChar(long int number){
	itoa(number,result,10);
	return result;

}

void free_arrays(char *arr1 , char *arr2 , char *arr3){
	int i = 0 ;
	for (i ; i < Calc_MAX ; i++)
	{
		*arr1[i] = NULL;
		arr2[i] = NULL;
		arr3[i] = NULL;

	}
}