// Function definition for The Interrupt
void Interrupt_init() {
//configure external interrupt INTO on falling edge 
  EICRA|= (1<<ISC01);
  EICRA|= (1<<ISC00);

 // Enable external interrupt INT0
  EIMSK|=(1<< INT0);

 
 // Enable global interrupts to allow respond to interrupt requests
  sei(); 
}
