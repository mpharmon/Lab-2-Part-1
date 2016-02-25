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

void main(){
  unsigned LCD_Line = 1;// Used to track what line the cursor is on
  unsigned LCD_Character = 1;// Used to track what character in the line the cursor is on
  LCD_Init();
  KeyPad_Init();
  while(1){
    switch(state){
      case ENTER:
        if(LCD_Character == 16){// If we are at the end of the line
          LCD_Character = 1;//Reset Character back to the beginning
          if(LCD_Line = 1)LCD_Line = 2;//If we are on line 1 go to line 2
          else LCD_Line = 1;//if we are on line 2 go to line 1
          LCD_MoveCursor(LCD_Character,LCD_Line);// Print Character on Screen
        }else{
          LCD_PrintChar(KeyPad_Scan());// Print Character on Screen
          LCD_Character++;// Advance Character Counter
        }
        state = WAIT;//Set state back to waiting
        break;
      case WAIT:
        break;
    }
  }
}

void __ISR(_CHANGE_NOTICE_VECTOR,IPL7SRS) _CNInterrupt{
  PORTx;
  IFS1bits.CNxIF = 0;// Put Flag Down
  state = ENTER;
}