#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S2,     light1,         sensorLightActive)
#pragma config(Sensor, S3,     light2,         sensorLightActive)
#pragma config(Sensor, S4,     inferred,       sensorNone)
#pragma config(Motor,  mtr_S1_C2_1,     sissorliftRight, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     sissorliftLeft, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     frontRight,    tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C1_1,    frontGate,            tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    backGrab,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    dump,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
	// Place code here to sinitialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void allForward()
{
	motor[frontLeft] = 100;
	motor[frontRight] = 100;
}

void turnRight()
{
	motor[frontLeft] = 100;
	motor[frontRight] = -100;
}

void turnLeft()
{
	motor[frontLeft] = -100;
	motor[frontRight] = 100;
}

void allBackwards()
{
	motor[frontLeft] = -100;
	motor[frontRight] = -100;
}
void allStop()
{
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
}

void wait30()
{
	wait10Msec(100);
	wait10Msec(100);
	wait10Msec(100);
}

void wait50()
{
	wait10Msec(100);
	wait10Msec(100);
	wait10Msec(100);
	wait10Msec(100);
	wait10Msec(100);
}


void Sensor()
{
	if (SensorValue[light1] >= 40 || SensorValue[light1] <= 72)
	{
		while (SensorValue[light2] <= 40 || SensorValue[light2] >= 72)
		{
			turnRight();
		}

		if (SensorValue[light2] >= 40 || SensorValue[light2] <= 72)
		{
			allStop();
			servo[backGrab]= 90;
			wait10Msec(100);
			allBackwards();
			allStop();
			servo[backGrab]= 0;
		}
	}
	else if (SensorValue[light1] <= 40 || SensorValue[light2] >= 72)
		allForward();

}

task main()
{
	initializeRobot();

	waitForStart(); // Wait for the beginning of autonomous phase.


	while (true)
	{

  }
}
