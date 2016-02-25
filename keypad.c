#include <xc.h>
#include "keypad.h"

void KeyPad_Init(void){
  // Configure Row Pins as ODC's
  KEYPAD_ROW1_TRIS = TRIS_OUTPUT;// Set Output
  KEYPAD_ROW1_ODC = ODC_ACTIVE;
  
  KEYPAD_ROW2_TRIS = TRIS_OUTPUT;// Set Output
  KEYPAD_ROW2_ODC = ODC_ACTIVE;
  
  KEYPAD_ROW3_TRIS = TRIS_OUTPUT;// Set Output
  KEYPAD_ROW3_ODC = ODC_ACTIVE;
  
  KEYPAD_ROW4_TRIS = TRIS_OUTPUT;// Set Output
  KEYPAD_ROW4_ODC = ODC_ACTIVE;
  
  //Configure Column Pins as Inputs w/Pull-ups
  KEYPAD_COL1_TRIS = TRIS_INPUT;// Set Input
  KEYPAD_COL1_CNPU = CNPU_ENABLE;// Enable Pull Up Resistor
  
  KEYPAD_COL2_TRIS = TRIS_INPUT;// Set Input
  KEYPAD_COL2_CNPU = CNPU_ENABLE;
  
  KEYPAD_COL3_TRIS = TRIS_INPUT;// Set Input
  KEYPAD_COL3_CNPU = CNPU_ENABLE;
}
char KeyPad_Scan(void){
  //Scan First Row
  KEYPAD_ROW1 = ODC_ENABLE;// Enable ODC on Row 1
  if(KEYPAD_COL1 = 0)return '1';
  if(KEYPAD_COL2 = 0)return '2';
  if(KEYPAD_COL3 = 0)return '3';
  KEYPAD_ROW1 = ODU_DISABLE;// Disable ODC on Row 1
  //Scan Second Row
  KEYPAD_ROW2 = ODC_ENABLE;// Enable ODC on Row 2
  if(KEYPAD_COL1 = 0)return '4';
  if(KEYPAD_COL2 = 0)return '5';
  if(KEYPAD_COL3 = 0)return '6';
  KEYPAD_ROW2 = ODU_DISABLE;// Disable ODC on Row 2
  
  //Scan Third Row
  KEYPAD_ROW3 = ODC_ENABLE;// Enable ODC on Row 3
  if(KEYPAD_COL1 = 0)return '7';
  if(KEYPAD_COL2 = 0)return '8';
  if(KEYPAD_COL3 = 0)return '9';
  KEYPAD_ROW3 = ODU_DISABLE;// Disable ODC on Row 3
  
  //Scan Fourth Row
  KEYPAD_ROW4 = ODC_ENABLE;// Enable ODC on Row 4
  if(KEYPAD_COL1 = 0)return '*';
  if(KEYPAD_COL2 = 0)return '0';
  if(KEYPAD_COL3 = 0)return '#';
  KEYPAD_ROW4 = ODU_DISABLE;// Disable ODC on Row 4
  
  return NULL;
}