/*
 * LCD_Generic_library.c
 *
 * Created: 8/17/2016 10:48:30 AM
 * Author : AWahdan@outlook.com
 */ 


#define F_CPU (8000000UL)
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_Library.h"
int main(void)
{

	LCD_Initialization(DataBus4Bits_2Line_8dot, Cursor_Increment,Display_On_Cursor_OFF);
	LCD_Write_String("Embedded");
	LCD_Go_To_X_Y(LCD_Row_2, LCD_Column_3);
	LCD_Write_String("Systems");
	_delay_ms(1000);
	LCD_Write_Command(LCD_Display_Shift_Right);
	_delay_ms(1000);
	LCD_Write_Command(LCD_Display_Shift_Left);
	_delay_ms(1000);
	LCD_Write_Command(LCD_Clear);
	LCD_Write_String("Embedded");
	while(1)
	{
		
	}	

}


