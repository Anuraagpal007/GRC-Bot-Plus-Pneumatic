#include "Auto.h"
#include <SPI.h>
void setup()
{
  Serial.begin(115200);
  Serial.println("Mega restarted");
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  pinModes();
  relaysOff();
  mpuSetup();
  tfMiniSetup();
  Serial.println("setup khatam");
}

ISR(SPI_STC_vect)
{
  if (SPDR != 135) {
    button = SPDR;
  }
  Serial.print("Button - "); Serial.println(button);
  resetMillis = currentMillis;
}

void loop()
{
  //  while (1) {
  //  Serial.println(limitAclk);
  //  Serial.print(tfmini2.getDistance());
  //  Serial.print(" - ");
  //  Serial.println(tfmini1.getDistance());
  //  delay(25);
  //  }

  currentMillis = millis();
  if (abs(currentMillis - resetMillis) > 500) {
    resetFunc();
  }

  stopGrabberMotor();
  switch (button)
  {
    case R3:
      autoTask();

    case UP:
      forward();
      checkReedCount();
      //      Serial.println("Forward");
      break;

    case DOWN:
      backward();
      checkReedCount();
      //      Serial.println("Back");
      break;

    case LEFT:
      left();
      checkReedCount();
      //      Serial.println("Left");
      break;

    case RIGHT:
      right();
      checkReedCount();
      //      Serial.println("Right");
      break;

    case UPRIGHT:
      bot.upRight(100);
      //      Serial.println("UR");
      break;

    case UPLEFT:
      bot.upLeft(100);
      //      Serial.println("UL");
      break;

    case DOWNRIGHT:
      bot.downRight(100);
      //      Serial.println("DR");
      break;

    case DOWNLEFT:
      bot.downLeft(100);
      //      Serial.println("DL");
      break;

    case CLOCKWISE:
      bot.clk(50);
      mpuSetup();
      //      Serial.println("clk");
      break;

    case ANTICLOCKWISE:
      bot.aclk(50);
      mpuSetup();
      break;
    //
    //    case L2:
    //      if (pwm > 110) {
    //        pwm -= 20;
    //      }
    //      //      Serial.println("Decrease by 20 - ");
    //      //      Serial.println(pwm);
    //      break;
    //
    //    case R2:
    //      if (pwm < 250) {
    //        pwm += 20;
    //      }
    //      //      Serial.println("INcrease by 20 - ");
    //      //      Serial.println(pwm);
    //      break;

    case JOYRIGHT:
      GrabMotor.clk(100);
      Serial.print("Encoder - ");
      Serial.println(readEncoder);
      break;

    case JOYLEFT:
      GrabMotor.aclk(100);
      Serial.print("Encoder - ");
      Serial.println(readEncoder);
      break;

    case SQUARE:
      Grabber.Close();
      Serial.println("Open the grabber");
      break;

    case CIRCLE:
      Grabber.Open();
      Serial.println("Grab the arrow");
      break;

    case CROSS:
      Thrower.Close();
      Serial.println("Thrower Down");
      throwerFlag = 0;
      break;

    case TRIANGLE:
      Serial.println("Thrower Up");
      //      Thrower.Open();
      //      delayMicroseconds(410);
      Thrower.Free();
      throwerFlag = 1;
      break;

    case START:

      Grabber.Close();
      delay(200);
      grabberAclk(100);
      bot.forward(50, 50, 50, 50);
      delay(800);
      bot.brake();

      break;

    case SELECT:
      Thrower.Free();
      GrabEnc.write(0);
      grabberAclk(2400);
      delay(1000);
      Thrower.Close();
      delay(300);
      Thrower.Free();
      throwerFlag = 1;
      delay(1000);
      grabberAclk(3200);
      Grabber.Open();
      delay(1000);
      grabberAclk(3500);
      GrabMotor.brake();

      // Code for alignment with MPU, don't uncomment if not asked to
      //
      //      mpu6050.update();
      //      angle = mpu6050.getAngleZ();
      //      while (abs(mpu6050.getAngleZ() - angle) < 20) {
      //        mpu6050.update();
      //        Serial.print("Angle - ");
      //        Serial.println(abs(mpu6050.getAngleZ() - angle));
      //        bot.aclk(50, 50, 50, 50);
      //      }
      //      Serial.println("Bot at the position");
      //      bot.brake();
      //      bot.clk(50, 50, 50, 50);
      //      delay(70);
      //      Thrower.Free();
      //      throwerFlag = 1;
      break;

    case PS:
      Serial.println("Reset");
      resetFunc();
      break;

    default:
      bot.brake();
      GrabMotor.brake();
      break;
  }
  Serial.println(mpu6050.getAngleZ());
  //  Serial.println(tfmini2.getDistance());
  //  checkReedCount();
  //  Serial.println(readEncoder);

}
