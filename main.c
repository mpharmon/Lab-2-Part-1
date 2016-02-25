#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "keypad.h"
#include "lcd.h"
#include "timer.h"

typedef enum enumState{
  ENTER,
  WAIT
}STATE;

volatile STATE state = ENTER;
volatile char lastCharacter = NULL;

void main(){
  int LCD_Line = 1;
  int LCD_Character = NULL;
  LCD_Init();
  KeyPad_Init();
  while(1){
    switch(state){
      case ENTER:
        if(LCD_Character == 16){
          LCD_Character = 1;
          if(LCD_Line = 1)LCD_Line = 2;
          else LCD_Line = 1;
          LCD_MoveCursor(LCD_Character,LCD_Line);
        }else{
          LCD_PrintChar(KeyPad_Scan());
          LCD_Character++;
        }
        state = WAIT;
        break;
      case WAIT:
        break;
    }
  }
}

void __ISR(_CHANGE_NOTICE_VECTOR,IPL7SRS) _CNInterrupt{
  PORTx;
  IFS1bits.CNxIF = 0;// Put Flag Down
  if()
}