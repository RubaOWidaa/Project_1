// Function prototype for initializing Input & Output
void DIO_init();

// Function prototype for setting pin direction
void DIO_SetPinDirection(unsigned char port, int pin, unsigned char direction);

// Function prototype for setting pin value
void DIO_SetPinState(unsigned char port, int pin, unsigned char state);

// Function prototype for getting pin value
int DIO_GetPinValue(unsigned char port , int Pin);
