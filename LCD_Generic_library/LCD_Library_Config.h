
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
#define LCD_RS_DDR		(DDRB)
#define LCD_RS_PORT		(PORTB)
#define LCD_RS_PIN		(PB1)


#define LCD_RW_DDR		(DDRB)
#define LCD_RW_PORT		(PORTB)
#define LCD_RW_PIN		(PB2)

#define LCD_EN_DDR		(DDRB)
#define LCD_EN_PORT		(PORTB)
#define LCD_EN_PIN		(PB3)

/**************** LCD DATA pins ********************/
#define LCD_D4_DDR		(DDRA)
#define LCD_D4_PORT		(PORTA)
#define LCD_D4_PIN		(PA4)

#define LCD_D5_DDR		(DDRA)
#define LCD_D5_PORT		(PORTA)
#define LCD_D5_PIN		(PA5)

#define LCD_D6_DDR		(DDRA)
#define LCD_D6_PORT		(PORTA)
#define LCD_D6_PIN		(PA6)

#define LCD_D7_DDR		(DDRA)
#define LCD_D7_PORT		(PORTA)
#define LCD_D7_PIN		(PB7)

/**********************************************************************/





/***************************************************/

#endif /* LCD_LIBRARY_CONFIG_H_ */

