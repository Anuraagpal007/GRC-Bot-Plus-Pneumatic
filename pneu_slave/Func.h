#include "Config.h"

void checkReedCount() {
//  Serial.print("Reed Count = ");
//  Serial.println(reedCount);
//  Serial.print("Reed Status = ");
//  Serial.println(reedSwitch);
  if (throwerFlag == 1) {
    if (reedSwitch == 0) {
      reedCount++;
    }
    if (reedCount > 2) {
      Thrower.Open();
      reedCount = 0 ;
      throwerFlag = 0;
    }
  }
}

void pinModes()
{
  pinMode(GrabP1, OUTPUT);
  pinMode(GrabP2, OUTPUT);
  pinMode(ThrowP1, OUTPUT);
  pinMode(ThrowP2, OUTPUT);
  pinMode(reedPin, INPUT_PULLUP);
  pinMode(limitClkPin, INPUT_PULLUP);
  pinMode(limitAclkPin, INPUT_PULLUP);
  pinMode(MISO, OUTPUT);
}

void relaysOff()
{
  digitalWrite(GrabP1, HIGH);
  digitalWrite(GrabP2, HIGH);
  digitalWrite(ThrowP1, HIGH);
  digitalWrite(ThrowP2, HIGH);
}

void mpuSetup() {
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void grabberAclk(int pulses)
{
  while (readEncoder < pulses)
  {
    GrabMotor.aclk(50);
    //    Serial.println(GrabEnc.read());
  }
  GrabMotor.brake();
}

void grabberClk(int pulses)
{
  while (readEncoder > -pulses)
  {
    GrabMotor.clk(50);
    //    Serial.println(GrabEnc.read());
  }
  GrabMotor.brake();
}

void stopGrabberMotor()
{
  if (limitClk == LOW || limitAclk == LOW)
  {
    GrabMotor.brake();
    GrabEnc.write(0);
    if (limitClk == LOW && limitAclk == HIGH)
    {
      grabberAclk(30);
      GrabEnc.write(0);
    }
    else if (limitAclk == LOW && limitClk == HIGH)
    {
      grabberClk(30);
      GrabEnc.write(0);
    }
  }
}

void (*resetFunc)(void) = 0;
