#ifndef __UART__
#define __UART__
// Function prototype to initialize UART communication
void Uart_init(void);

// Function prototype to set the baud rate for UART communication
void Uart_SetBaudRate(unsigned short BuadRate);

// Function prototype to read a single character from UART
unsigned char Uart_ReadData();

// Function prototype to read a string of characters via UART
unsigned char Uart_ReadString(char Buffer[], unsigned char Size);

// Function prototypeto send a single character via UART
void Uart_SendChar (char DataString);


// Function prototype to send a string of characters via UART
void Uart_SendString(char DataString[]);

#endif
