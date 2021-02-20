// Include headers and libraries ---------------------
#include "Bot.h"
#include "Pneumatic.h"
#include <Encoder.h>
#include <MPU6050_tockn.h>
#include<Wire.h>
MPU6050 mpu6050(Wire);

// Definition of pins ---------------------------------
// Relay in order from vcc - 43, 45, 41, A12
#define ThrowP1 A12
#define ThrowP2 41
#define GrabP1 45
#define GrabP2 43

#define limitClkPin A6
#define limitAclkPin A0
#define reedPin A7

// Motor pinouts
#define Grab_pwm 4
#define Grab_in1 28
#define Grab_in2 5

#define m1d 11
#define m1p 8

#define m2d 7
#define m2p 12

#define m3d 13
#define m3p 6

#define m4d 9
#define m4p 10

// Definition of digitalReads -------------------------
#define limitClk digitalRead(limitClkPin)
#define limitAclk digitalRead(limitAclkPin)
#define reedSwitch digitalRead(reedPin)
#define readEncoder GrabEnc.read()


// Variables- -----------------------------------------
byte reedCount = 0;
byte button = 0;
float b = 0 ;
bool throwerFlag = 0;
int angle = 0;

// List of millis -------------------------

unsigned long resetMillis = 0;
unsigned long currentMillis = 0;


// Creating objects of classes-------------------------
Motor GrabMotor(Grab_pwm, Grab_in1, Grab_in2);
Encoder GrabEnc(2, 3);
Pneumatic Thrower(ThrowP1, ThrowP2);
Pneumatic Grabber(GrabP1, GrabP2);

// Base motors and Bot object ----------------------
Motor motor1(m1p, m1d);
Motor motor2(m2p, m2d);
Motor motor3(m3p, m3d);
Motor motor4(m4p, m4d);

Bot bot(motor1, motor2, motor3, motor4);

// Constants for PS ------------------------------
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define L1 5
#define L2 6
#define R1 7
#define R2 8
#define TRIANGLE 9
#define CIRCLE 10
#define CROSS 11
#define SQUARE 17
#define L3 15
#define R3 16
#define PS 12
#define START 13
#define SELECT 14
//////////////////////////
#define DISC 255
#define UPRIGHT 20
#define UPLEFT 21
#define DOWNLEFT 22
#define DOWNRIGHT 23
#define CLOCKWISE 24
#define ANTICLOCKWISE 25
#define JOYUP 26
#define JOYRIGHT 27
#define JOYDOWN 28
#define JOYLEFT 29

//#define UPTHROW 50
//#define DOWNTHROW 51
//#define LEFTTHROW 52
//#define RIGHTTHROW 53
