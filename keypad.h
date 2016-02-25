#ifndef KEYPAD_H_
#define	KEYPAD_H_

#define KEYPAD_ROW1 LATxbits// ODC
#define KEYPAD_ROW2 LATxbits// ODC
#define KEYPAD_ROW3 LATxbits// ODC
#define KEYPAD_ROW4 LATxbits// ODC
#define KEYPAD_COL1 PORTxbits// INPUT
#define KEYPAD_COL2 PORTxbits// INPUT
#define KEYPAD_COL3 PORTxbits// INPUT

#define TRIS_OUTPUT 0
#define TRIS_INPUT 1

#define ODC_ACTIVE 1

#define CNPU_ENABLE 1

#define ODC_ENABLE 1
#define ODU_DISABLE 0

void KeyPad_Init(void);
char KeyPad_Scan(void);

#endif	/* KEYPAD_H */