#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>

// Blink the LED to show we're on
tBoolean blink_on = true;

void blink(void) {
    //f1 is red
    //f2 is blue
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}


// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
    CallEvery(blink, 0, .125);
    
    while (1) {
        // Runtime code can go here
        Printf("Hello World!\n");
        
    }
}
