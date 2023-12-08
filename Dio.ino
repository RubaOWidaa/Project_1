void DIO_init(){
// Initialaize pins: PD6 as output(LED) and PD2 as input (PUSHBUTTON) 
  DIO_SetPinDirection('D', 6, 'o');//set pin PD6 as output
  DIO_SetPinDirection('D', 2, 'i');//set pin PD2 as input
}
// Function definition for setting pin direction
void DIO_SetPinDirection(unsigned char port, int pin, unsigned char direction){ //
 if (port == 'D' && pin <= 7 & pin >= 0){ // pin must be from 0-7
    if(direction == 'o'){
      DDRD = DDRD|(1<<pin); //bit set to 1 for output
    }else if(direction == 'i'){
      DDRD = DDRD&!(1<<pin); //bit cleared to 0 for input
    }
  }
}
// Function definition for Setting pin state
void DIO_SetPinState(unsigned char port, int pin, unsigned char state){
  if (port == 'D' && pin <= 7 & pin >= 0){ // pin must be from 0-7
    if(state == 'h'){
      PORTD = PORTD|(1<<pin); //pin is set to 1 for high
    }else if(state == 'l'){
    PORTD =  PORTD &!(1<<pin); //pin is cleared to 0 for low
    }
   }
 }

// Function definition for getting pin value
int DIO_GetPinValue(unsigned char port, int pin) {
     int Result;

     if (port == 'D' && pin <= 7 & pin >= 0) { // pin must be from 0-7
        Result = ((PIND >> pin) & 1);
    }

    return Result; 
    
}
     
