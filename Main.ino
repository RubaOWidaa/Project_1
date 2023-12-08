//include the header files
#include "Dio.h"
#include "Uart.h"
#include "Interrupt.h"
#include <util/delay.h>

// Define constants for LED and push button pins
const int LED = 6;
const int PUSH_BUTTON = 2;

//PUSHBUTTON
// Interrupt service routine for external interrupt INT0
ISR(INT0_vect) {
  //debouncing push button
  int lastButtonState = 0; // Variable to store the last button state
  //track button state
  if (lastButtonState != (DIO_GetPinValue('D',PUSH_BUTTON))) 
     {   // Update the last button state
        lastButtonState = (DIO_GetPinValue('D',PUSH_BUTTON)) ; 
        
        
      if (lastButtonState) // If the button is currently pressed 
          {
            // Define Push button state
            char* buttonState = "PUSH BUTTON PRESSED \n" ; 
           //Send Push button state
            Uart_SendString(buttonState);               
            
            _delay_ms(1000); 
          }
      } 
   }

 
int main() {
  // Initialize UART, Digital I/O ,Inturrept
    Uart_init(); // Initialize Uart
    DIO_init(); // Initialize Digital input and output
    Interrupt_init(); // Initialize the interrupt
      while(1){
          //LED
        char receivedData[20];
        Uart_ReadString( receivedData,20);
            if (strcasecmp( receivedData, "LED_ON") == 0)  
            // Check if the received data corresponds to turning the LED on
                { DIO_SetPinState('D', LED, 'h');   
                // Turn LED on
                   }
            if (strcasecmp( receivedData, "LED_OFF") == 0)         
            // Check if the received data corresponds to turning the LED off
                { DIO_SetPinState('D', LED, 'l');   
                // Turn LED off
                    }
            _delay_ms(1000);
                }
        return 0;
              }


         
