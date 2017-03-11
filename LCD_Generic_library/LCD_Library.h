/**************************************************
 	Generic LCD Library header file
	auther : Eng: Ahmed Wahdan 
	Email  : AWahdan@outlook.com
	17/8/2016
******************************************************************/

#ifndef LCD_LIBRARY_H_
#define LCD_LIBRARY_H_

#include <stdlib.h>

/*****************************************************************/
typedef enum 
{
	DataBus8Bits_1Line_7dot		= 0x30U,
	DataBus8Bits_1Line_10dot	= 0x34U,
	DataBus8Bits_2Line_8dot		= 0x38U,
	DataBus4Bits_1Line_8dot     = 0x20U,
	DataBus4Bits_1Line_10dot    = 0x24U,
	DataBus4Bits_2Line_8dot     = 0x28U
	
}Function_Set_t;

typedef enum
{
	Cursor_Increment	= 0x06U,
	Cursor_Decrement	= 0x04U,
	Display_Shift_Right = 0x05U,
	Display_Shift_Left	= 0x07U
}Entry_Mode_t;

typedef enum
{
	Display_OFF						= 0x08U,
	Display_On_Cursor_OFF			= 0x0CU,
	Display_On_Curson_On_Blink_Off	= 0x0EU,
	Display_On_Cursor_On_Blink_ON	= 0x0FU
}Display_ON_OFF_t;

typedef enum
{
	LCD_Clear				= 0x01U,
	LCD_Return_Home			= 0x02U,
	LCD_Cursor_Shift_Right	= 0x14U,
	LCD_Cursor_Shift_Left   = 0x10U,
	LCD_Display_Shift_Right	= 0x1CU,
	LCD_Display_Shift_Left	= 0x18U
}LCD_Commands_t;

typedef enum
{
	LCD_Row_1 = 0x00U,
	LCD_Row_2 = 0x01U
}LCD_Row_t;
typedef enum
{
	LCD_Column_1	= 0x00U,
	LCD_Column_2	= 0x01U,
	LCD_Column_3	= 0x02U,
	LCD_Column_4	= 0x03U,
	LCD_Column_5	= 0x04U,
	LCD_Column_6	= 0x05U,
	LCD_Column_7	= 0x06U,
	LCD_Column_8	= 0x07U,
	LCD_Column_9	= 0x08U,
	LCD_Column_10	= 0x09U,
	LCD_Column_11	= 0x0AU,
	LCD_Column_12	= 0x0BU,
	LCD_Column_13	= 0x0CU,
	LCD_Column_14	= 0x0DU,
	LCD_Column_15	= 0x0EU,
	LCD_Column_16	= 0x0FU,
}LCD_Column_t;

	

/*****************************************************************/


void LCD_Initialization(Function_Set_t func_set,Entry_Mode_t entry_mode,Display_ON_OFF_t display_state);

void LCD_Write_Command(LCD_Commands_t  command);

void LCD_Go_To_X_Y(LCD_Row_t row,LCD_Column_t position);

void LCD_Write_Character(char  character);

void LCD_Write_String(char  *pointer);

void LCD_Write_float( float  float_value);

/*****************************************************************/

#endif /* LCD_LIBRARY_H_ */



