#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftM,         tmotorTetrix, PIDControl, reversed, driveLeft, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     rightM,        tmotorTetrix, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
setMultipleMotors(100,leftM,rightM);
wait1Msec(6000)
}
