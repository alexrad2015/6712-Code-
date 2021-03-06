#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S3,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  motorB,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  motorC,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     BR,            tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     BL,            tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     MR,            tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     ML,            tmotorNormal, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     FR,            tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     FL,            tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     motorJ,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    flipper,              tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    WS,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Local Variables////////////////////////////////////////////

int delay;
int IR;
int deg45 = (640);
int deg90 = (1275);
int deg23 = (320);
string autoRoutines[] =  { "Score", "BridgeRight", "R3", "R4", "R5", "R6"};
int   selectedAutoRoutine = -1;
string delayTimes[] =  { "0","5","10","15","20"};
int   selectedDelayTime = -1;

//Includes///////////////////////////////////////////////////

#include "JoystickDriver.c"
#include "masterdrive.h"
#include "autoHelper.h"
#include "menu.h"
#include "autoRoutines.h"

//Initialize/////////////////////////////////////////////////

void initializeRobot() {
	disableDiagnosticsDisplay();
	//Choose an auto routine.
	selectedAutoRoutine = getRouteChoice();
	eraseDisplay();
	selectedDelayTime = getDelayChoice();
	nMotorEncoder[ML] = 0;
	servo[flipper] = 0;
	servo[WS]= 165;
}

//Main Task/////////////////////////////////////////////////

task main()
{
	initializeRobot();

	eraseDisplay();
	nxtDisplayCenteredBigTextLine(2,"WAITING...");
	nxtDisplayTextLine(4,"Autonomous Mode");
	nxtDisplayTextLine(5,"Choice: %s", autoRoutines[selectedAutoRoutine]);
	nxtDisplayTextLine(6,"Delay: %i", atoi(delayTimes[selectedDelayTime]));

	waitForStart();

	nxtDisplayCenteredBigTextLine(2,"Delaying: %i sec", atoi(delayTimes[selectedDelayTime]));
	wait10Msec(atoi(delayTimes[selectedDelayTime]) * 100);

	eraseDisplay();
	nxtDisplayCenteredBigTextLine(1,"RUNNING!");
	nxtDisplayTextLine(4,"Autonomous Mode");
	nxtDisplayTextLine(5,"Choice: %s", autoRoutines[selectedAutoRoutine]);

	//START AN AUTO ROUTINE!!!!
	switch (selectedAutoRoutine + 1) {  //array index starts at 0, normalize to 1 for clarity
	case 1:
		Score();
		break;
	case 2:
		BridgeRight();
		break;
	case 3:
		R3();\
		break;
	case 4:
		R4();
		break;
	case 5:
		R5();
		break;
	case 6:
		R6();
		break;
	default:
		//no autonomous routine was chosen, run a default one.
		break;
	}
}
