/*
* KeyPad_LCD.c
*
* Created: 5/5/2020 11:19:10 AM
* Author : user
*/

#include "Keypad.h"


int main(void)
{
	LCD_INIT();  // LCD and DIO

	while (1)
	{
		Check_C1();
		Check_C2();
		Check_C3();
		Check_C4();
	}
}

