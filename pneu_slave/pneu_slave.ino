#include "mpu.h"
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
  Serial.println("setup khatam");
}

ISR(SPI_STC_vect)
{
  if (SPDR != 135) {
    button = SPDR;
  }
  //  Serial.print("Button - "); Serial.println(button);
  resetMillis = currentMillis;
}

void loop()
{
 
  currentMillis = millis();
  if (abs(currentMillis - resetMillis) > 1000) {
    resetFunc();
  }
  stopGrabberMotor();
  switch (button)
  {
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
      bot.upRight(80);
      //      Serial.println("UR");
      break;

    case UPLEFT:
      bot.upLeft(80);
      //      Serial.println("UL");
      break;

    case DOWNRIGHT:
      bot.downRight(80);
      //      Serial.println("DR");
      break;

    case DOWNLEFT:
      bot.downLeft(80);
      //      Serial.println("DL");
      break;

    case CLOCKWISE:
      bot.clk(80, 80, 80, 80);
      //      Serial.println("clk");
      break;

    case ANTICLOCKWISE:
      bot.aclk(80, 80, 80, 80);
      break;
    //
    case L2:
      if (pwm > 110) {
        pwm -= 20;
      }
      //      Serial.println("Decrease by 20 - ");
      //      Serial.println(pwm);
      break;

    case R2:
      if (pwm < 250) {
        pwm += 20;
      }
      //      Serial.println("INcrease by 20 - ");
      //      Serial.println(pwm);
      break;

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
      Thrower.Free();
      throwerFlag = 1;
      break;

    case START:

      Grabber.Close();
      grabberAclk(100);
      bot.forward(50, 50, 50, 50);
      delay(700);
      bot.brake();

      break;

    case SELECT:

      //      GrabEnc.write(0);
      //      grabberAclk(2400);
      //      delay(1000);
      //      Thrower.Close();
      //      delay(1000);
      //      grabberAclk(2800);
      //      Grabber.Open();
      //      delay(1000);
      //      grabberAclk(3500);
      //      GrabMotor.brake();
      //      mpu6050.update();
      //      angle = mpu6050.getAngleZ();
      //      while (abs(mpu6050.getAngleZ() - angleZ) < 20) {
      //        mpu6050.update();
      //        Serial.print("Angle - ");
      //        Serial.println(abs(mpu6050.getAngleZ() - angleZ));
      //        bot.aclk(50, 50, 50, 50);
      //      }
      //      Serial.println("Bot at the position");
      //      bot.brake();
      //      bot.clk(50, 50, 50, 50);
      //      delay(70);
      //      bot.brake();
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
  //  Serial.println(mpu6050.getAngleZ());
  checkReedCount();
}
