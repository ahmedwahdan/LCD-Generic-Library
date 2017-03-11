/**************************************************
 	Generic LCD Library source code for AVR MCUs
	auther : Eng: Ahmed Wahdan 
	Email  : AWahdan@outlook.com
	17/8/2016
******************************************************************/


#include "LCD_Library.h"
#include "LCD_Library_Config.h"
#include <avr/io.h>
#include <util/delay.h>
	


/*********************************************************************************************************/
void static LCD_READ()
{
	/* Enable pulse for 1usec (500ns up to data sheet) */
	LCD_EN_PORT|=(1<<LCD_EN_PIN);        
	_delay_us(1U);
	LCD_EN_PORT&=~(1<<LCD_EN_PIN);		
}

/**********************************************/

void static LCD_Write_4bit_mode(unsigned char value)
{
	if (value&(1U<<3))  {LCD_D7_PORT|=(1U<<LCD_D7_PIN);} else {LCD_D7_PORT&=~(1U<<LCD_D7_PIN);}
	if (value&(1U<<2))  {LCD_D6_PORT|=(1U<<LCD_D6_PIN);} else {LCD_D6_PORT&=~(1U<<LCD_D6_PIN);}
	if (value&(1U<<1))  {LCD_D5_PORT|=(1U<<LCD_D5_PIN);} else {LCD_D5_PORT&=~(1U<<LCD_D5_PIN);}
	if (value&(1U<<0))  {LCD_D4_PORT|=(1U<<LCD_D4_PIN);} else {LCD_D4_PORT&=~(1U<<LCD_D4_PIN);}
	LCD_READ();									   		  								 
}
	
/**********************************************/

void LCD_Write_Command(LCD_Commands_t  command)
{
	LCD_RS_PORT &=~(1U<<LCD_RS_PIN);
	LCD_RW_PORT &=~(1U<<LCD_RW_PIN); 
	LCD_Write_4bit_mode(((char)command)>>4);
	LCD_Write_4bit_mode((char)command);
	if (command == LCD_Clear || command == LCD_Return_Home) 
	{
		_delay_ms(3);
	}
	else
	{
		_delay_us(50);
	}
	
}
	
/**********************************************/

void LCD_Go_To_X_Y(LCD_Row_t row,LCD_Column_t column)
{

	LCD_Write_Command((0x80U |((char)row<<6U))+column);

}

/**********************************************/

void LCD_Write_Character(char  character)
{
	LCD_RW_PORT &=~(1U<<LCD_RW_PIN); // write command ( not generic)
	LCD_RS_PORT |=(1U<<LCD_RS_PIN);
	LCD_Write_4bit_mode(character>>4);
	LCD_Write_4bit_mode(character);
	_delay_us(50);
}

/**********************************************/

void LCD_Write_String(char  *pointer)
{
		while(*pointer)
		{
			LCD_Write_Character(*pointer++);
		}		
}

/**********************************************/

void LCD_Write_float(float  float_value)
{
	long int vlaue = 0;
	unsigned int x,y;
	char buffer_1[5]={0};
	char buffer_2[5]={0};
	vlaue=(float_value)*100;
	y=vlaue % 100;   
	x=vlaue / 100;   
	
	itoa(x,buffer_1,10);
	itoa(y,buffer_2,10);
	LCD_Write_String(buffer_1);
	LCD_Write_Character('.');
	if (y<10)
	{
		LCD_Write_Character('0');
	}
	LCD_Write_String(buffer_2);
	
}

/**********************************************/

void LCD_Initialization(Function_Set_t func_set,Entry_Mode_t entry_mode,Display_ON_OFF_t display_state)
{
	LCD_RS_DDR |=(1U<<LCD_RS_PIN);
	LCD_RW_DDR |=(1U<<LCD_RW_PIN);
	LCD_EN_DDR |=(1U<<LCD_EN_PIN);
	LCD_D7_DDR |=(1U<<LCD_D7_PIN);
	LCD_D6_DDR |=(1U<<LCD_D6_PIN);
	LCD_D5_DDR |=(1U<<LCD_D5_PIN);
	LCD_D4_DDR |=(1U<<LCD_D4_PIN);
	
	_delay_ms(20);
	/*
		Initialization steps:
		1- Write 0x3 to the LCD
		2- Delay more than 4.1 ms (5ms)
		3- Write 0x3 to the LCD
		4- Delay more than 100 us (150 us) 
		5- Write 0x3 to the LCD
		6- Write 0x2 to the LCD
		7- Write set function value (DL - N - F)
		8- Display off
		9- Display Clear
		10-Entry Mode (cursor shift/ Display shift) 
		11-Display on
	*/
	
	/* 1- Write 0x3 to the LCD */
	LCD_Write_4bit_mode(0x3U);
	/* 2- Delay more than 4.1 ms (5ms) */
	_delay_ms(5);  
	/* 3- Write 0x3 to the LCD */
	LCD_Write_4bit_mode(0x3U);
	/* 4- Delay more than 100 us (150 us)  */
	_delay_us(150);
	/* 5- Write 0x3 to the LCD */
	LCD_Write_4bit_mode(0x3U);
	_delay_us(150);
	/* 6- Write 0x2 to the LCD */
	LCD_Write_4bit_mode(0x2U);
	_delay_us(150);
	/* 7- Write set function value (DL - N - F) */
	LCD_Write_4bit_mode(func_set>>4);
	LCD_Write_4bit_mode(func_set);
	_delay_us(50);
	/* 8- Display off */
	LCD_Write_4bit_mode(((char)Display_OFF)>>4);
	LCD_Write_4bit_mode((char)Display_OFF);
	_delay_us(50);
	/* 9- Display Clear */
	LCD_Write_4bit_mode(((char)LCD_Clear)>>4);
	LCD_Write_4bit_mode((char)LCD_Clear);
	_delay_ms(3);
	/* 10-Entry Mode (cursor shift/ Display shift) */ 
	LCD_Write_4bit_mode(((char)entry_mode)>>4);
	LCD_Write_4bit_mode((char)entry_mode);
	_delay_us(50);
	/* 11-Display on */
	LCD_Write_4bit_mode(((char)display_state)>>4);
	LCD_Write_4bit_mode((char)display_state);
	_delay_us(50);
	

}

/*************************************************************************************************************/

