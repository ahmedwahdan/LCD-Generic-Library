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

	LCD_Initialization();
	LCD_Write_String("Embedded");
	LCD_Go_To_X_Y(LCD_ROW_2,LCD_POSITION_3);
	LCD_Write_String("Systems");
	_delay_ms(1000);
	LCD_Write_Command(LCD_SHIFT_RIGHT_CMD);
	_delay_ms(1000);
	LCD_Write_Command(LCD_SHIFT_RIGHT_CMD);
	_delay_ms(1000);
	LCD_Write_Command(LCD_CLEAR_CMD);
	while(1)
	{
		
	}	

}


