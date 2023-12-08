// Initialize UART
void Uart_SetBaudRate(unsigned short BuadRate)
{
    unsigned short UBBR = ( (F_CPU / 16) /  BuadRate ) - 1; //calculate buad rate
    UBRR0L = (UBBR & 0xFF); // set the 8 least significant bits of Uart buad rate
    UBRR0H = (( UBBR >> 8 ) & 0xFF); //shift 8 bits to set the most significant bits
}
void Uart_init(void) {

    Uart_SetBaudRate(9600); // Set UART baud rate

    /* Enable USART transmitter/receiver */
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    /* 8 data bits, 1 stop bit */
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

// Send a single character via UART
void Uart_SendChar (char DataString)
{
 
    // Wait until Write buffer is empty
    while ( ! (UCSR0A & ( 1 << UDRE0)) ); //check if the buffer is empty
    UDR0 = DataString;  //save character in the buffer
}
// Send a string of characters from UART
void Uart_SendString(char DataString[]) {
  int i;
  //send charaters 1 by 1 until last character
    for(i=0; DataString[i];i++)
  {
     Uart_SendChar(DataString[i]);
  }
}
// Read a single character from UART
unsigned char Uart_ReadData(void) {
  
    while ( ! (UCSR0A & ( 1 << RXC0)) ); //check if the character is recieved
    return UDR0; //return character
}
// Read a string of characters from UART
unsigned char Uart_ReadString(char Buffer[], unsigned char Size) {
    int i;//read charaters 1 by 1 until last character
    for (i = 0; i < Size; i++) {
       
        while (!(UCSR0A & (1 << RXC0))); //check if the characters are fully recieved
        Buffer[i] = UDR0; //store character in the buffer 

        // Check for a newline or null terminator to stop reading
        if (Buffer[i] == '\n' || Buffer[i] == '\0') {
            break;
        }
    }
     Buffer[i] = '\0';  // Null-terminate the string
}
