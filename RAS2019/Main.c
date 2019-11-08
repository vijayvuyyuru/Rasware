#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>

// Blink the LED to show we're on
tBoolean blink_on = true;

void blink(void) {
    //f1 is red
    //f2 is blue
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}

static tMotor *Motors[2];
static tBoolean initialized = false;

void initMotors(void) {
    if (!initialized) {
      initialized = true;
  
    }
}


// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
    //CallEvery(blink, 0, .125);
    initMotors();
    tMotor *left = InitializeServoMotor(PIN_B6, true);
	tMotor *right = InitializeServoMotor(PIN_B7, false);	
    SetMotor(left, 1.0);
	SetMotor(right, -1.0);
	Wait(5.0);
	SetMotor(left, 0);
	SetMotor(right, 0);

    // while (1) {
    //     // Runtime code can go here
    //     Printf("Hello World!\n");
        
    // }
}
