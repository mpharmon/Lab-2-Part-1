#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "keypad.h"
#include "lcd.h"
#include "timer.h"

typedef enum enumState{
  ENTER,
  WAITING_RELEASE,
  WAIT
}STATE;

volatile STATE state = WAIT;

void main(void){
  SYSTEMConfigPerformance(10000000);
  enableInterrupts();
  TRISDbits.TRISD0 = 0;
  TRISDbits.TRISD1 = 0;
  TRISDbits.TRISD2 = 0;
  unsigned LCD_Line = 1;// Used to track what line the cursor is on
  unsigned LCD_Character = 1;// Used to track what character in the line the cursor is on
  LCD_Init();
  KeyPad_Init();
  //char buttonPressed = '';
  while(1){
    switch(state){
      case ENTER:
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0;
        LCD_PrintChar(KeyPad_Scan());
        if(LCD_Character == 16){// If we are at the end of the line
          LCD_Character = 1;//Reset Character back to the beginning
          if(LCD_Line == 1)LCD_Line = 2;//If we are on line 1 go to line 2
          else LCD_Line = 1;//if we are on line 2 go to line 1
          LCD_MoveCursor(LCD_Character,LCD_Line);// Print Character on Screen
        }else{
          LCD_Character++;// Advance Character Counter
        }
        state = WAITING_RELEASE;
        //state = WAITING_RELEASE;//Set state back to waiting
        break;
      case WAITING_RELEASE:
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 0;
        break;
      case WAIT:
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 1;
        break;
    }
  }
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNInterrupt(void){
  PORTE;
  IFS1bits.CNEIF = 0;
  if(state == WAIT)state = ENTER;
  else if(state == WAITING_RELEASE)state = WAIT;
}