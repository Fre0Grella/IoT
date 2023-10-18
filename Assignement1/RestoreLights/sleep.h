
enum SleepState { createInt, sleeping};

SleepState sl = createInt;

// Manage the sleep mode phase 
void sleepMode();

// Attach the interrupts to the B4 button and set up the wake up
void attInterrupts();

// Send the system in deep sleep
void goSleep();

// wake up the system from the deep sleep and detach the Interrupt
void wakeUp();