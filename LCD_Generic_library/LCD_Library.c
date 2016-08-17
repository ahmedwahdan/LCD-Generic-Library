/**************************************************
 	Generic LCD Library source code
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
	LCD_EN_PORT|=(1<<LCD_EN_PIN);        // set enable high to read
	_delay_us(100);
	LCD_EN_PORT&=~(1<<LCD_EN_PIN);		// reset enable
	_delay_ms(5);     			// delay 5 ms 
}

/**********************************************/

void static LCD_Write_4bit_mode(char value)
{
	if (value&0x80)  LCD_D7_PORT|=(1<<LCD_D7_PIN); else LCD_D7_PORT&=~(1<<LCD_D7_PIN);
	if (value&0x40)  LCD_D6_PORT|=(1<<LCD_D6_PIN); else LCD_D6_PORT&=~(1<<LCD_D6_PIN);
	if (value&0x20)  LCD_D5_PORT|=(1<<LCD_D5_PIN); else LCD_D5_PORT&=~(1<<LCD_D5_PIN);
	if (value&0x10)  LCD_D4_PORT|=(1<<LCD_D4_PIN); else LCD_D4_PORT&=~(1<<LCD_D4_PIN);
	LCD_READ();		
	if (value&0x08)  LCD_D7_PORT|=(1<<LCD_D7_PIN); else LCD_D7_PORT&=~(1<<LCD_D7_PIN);
	if (value&0x04)  LCD_D6_PORT|=(1<<LCD_D6_PIN); else LCD_D6_PORT&=~(1<<LCD_D6_PIN);
	if (value&0x02)  LCD_D5_PORT|=(1<<LCD_D5_PIN); else LCD_D5_PORT&=~(1<<LCD_D5_PIN);
	if (value&0x01)  LCD_D4_PORT|=(1<<LCD_D4_PIN); else LCD_D4_PORT&=~(1<<LCD_D4_PIN);
	LCD_READ();
}
	
/**********************************************/

void LCD_Write_Command(char command)
{
	LCD_RS_PORT &=~(1<<LCD_RS_PIN);
	LCD_RW_PORT &=~(1<<LCD_RW_PIN); // write command ( not generic)
	LCD_Write_4bit_mode(command);
}
	
/**********************************************/

void LCD_Go_To_X_Y(unsigned char row,unsigned char position)
{

	LCD_Write_Command((0x80 |(row<<6))+position);

}

/**********************************************/

void LCD_Write_Character(char  character)
{
	LCD_RW_PORT &=~(1<<LCD_RW_PIN); // write command ( not generic)
	LCD_RS_PORT |=(1<<LCD_RS_PIN);
	LCD_Write_4bit_mode(character);
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

void LCD_Write_float( float  float_value)
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

void LCD_Initialization(void)
{
	_delay_ms(15);
	LCD_RS_DDR |=(1U<<LCD_RS_PIN);
	LCD_RW_DDR |=(1U<<LCD_RW_PIN);
	LCD_EN_DDR |=(1U<<LCD_EN_PIN);
	LCD_D7_DDR |=(1U<<LCD_D7_PIN);
	LCD_D6_DDR |=(1U<<LCD_D6_PIN);
	LCD_D5_DDR |=(1U<<LCD_D5_PIN);
	LCD_D4_DDR |=(1U<<LCD_D4_PIN);
	
	LCD_Write_4bit_mode(0x33);  /* Initialization */
	LCD_Write_4bit_mode(0x32);	/* Initialization */							
	LCD_Write_4bit_mode(0x28);	/* Function Set: 4-bit, 2 Line, 5x7 Dots */
	LCD_Write_4bit_mode(0x0c);	/* Display on ,cursor off */	
	LCD_Write_4bit_mode(0x06);	/* Entry mode (advanced cursor) */
	LCD_Write_4bit_mode(0x01);  /* Clear display , Cursor home */	
}

/*************************************************************************************************************/

