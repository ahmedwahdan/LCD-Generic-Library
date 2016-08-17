
/**************************************************
 	Generic LCD Library configuration file
	auther : Eng: Ahmed Wahdan 
	Email  : AWahdan@outlook.com.com
	17/8/2016
******************************************************************/
#ifndef LCD_LIBRARY_CONFIG_H_
#define LCD_LIBRARY_CONFIG_H_

/*************** MCU Clock definition for LCD delay function ***********/

#define  F_CPU		(8000000UL)


/**************** LCD Control pins ************************/
#define LCD_RS_DDR		DDRB
#define LCD_RS_PORT		PORTB
#define LCD_RS_PIN		PB0


#define LCD_RW_DDR		DDRB
#define LCD_RW_PORT		PORTB
#define LCD_RW_PIN		PB1

#define LCD_EN_DDR		DDRB
#define LCD_EN_PORT		PORTB
#define LCD_EN_PIN		PB2

/**************** LCD DATA pins ********************/
#define LCD_D4_DDR		DDRB
#define LCD_D4_PORT		PORTB
#define LCD_D4_PIN		PB4

#define LCD_D5_DDR		DDRB
#define LCD_D5_PORT		PORTB
#define LCD_D5_PIN		PB5

#define LCD_D6_DDR		DDRB
#define LCD_D6_PORT		PORTB
#define LCD_D6_PIN		PB6

#define LCD_D7_DDR		DDRB
#define LCD_D7_PORT		PORTB
#define LCD_D7_PIN		PB7

/**********************************************************************/





/***************************************************/

#endif /* LCD_LIBRARY_CONFIG_H_ */

