#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/adc.h>

double blackThreshold = .65;
double newMotorVal = .35;
double defaultMotorVal = .25;

// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
    tMotor *left = InitializeServoMotor(PIN_B7, true);
	tMotor *right = InitializeServoMotor(PIN_B6, false);

	tLineSensor *line = InitializeGPIOLineSensor(PIN_D3, PIN_D7, PIN_D7, PIN_D2, PIN_D7, PIN_D7, PIN_D7, PIN_D1); 

	tADC *dist = InitializeADC(PIN_E1);
   
    float linevals[8];

    float distval;

    SetMotor(left, .25);
    SetMotor(right,.25);

    while(1){
    	Wait(.25);
    	LineSensorReadArray(line, linevals);
    	Printf("Line Sensor: \n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n", linevals[0], linevals[1], linevals[2], 
  		linevals[3], linevals[4], linevals[5], linevals[6], linevals[7]);

    	if(linevals[6]>blackThreshold){
    		SetMotor(left, newMotorVal);
    	}else if(linevals[6]<blackThreshold){
    		SetMotor(left, defaultMotorVal);
    	}

    	if(linevals[3]>blackThreshold){
    		SetMotor(right, newMotorVal);
    	}else if(linevals[3]<blackThreshold){
    		SetMotor(right, defaultMotorVal);
    	}

    	distval = ADCRead(dist);
  		Printf("\n\nDistance Sensor: %f\n\n\n", distval);
    }
}
