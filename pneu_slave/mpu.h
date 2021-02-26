//  M4-----F-----M1
//  |      |      |
//  |      |      |
//  L------X------R   --- NEGATIVE MPU VALUE THIS SIDE
//  |      |      |
//  |      |      |
//  M3-----B-----M2

#include "Func.h"

//byte pwm = 50;
byte offset = 20;

void forward(byte pwm = 100) {
  mpu6050.update();

  b =  mpu6050.getAngleZ();
  //  Serial.println(a);
  if (b < 3 && b > -3)
  {

    bot.forward(pwm, pwm, pwm, pwm);
  }
  if (b > 3) //WHEN GOING LEFT SIDE
  {
    bot.forward(pwm, pwm, pwm + offset, pwm + offset);
  }
  if (b < -3) //WHEN GOING RIGHT
  {
    bot.forward(pwm + offset, pwm + offset, pwm, pwm);
  }
}

void backward(byte pwm = 100) {
  mpu6050.update();
  b = mpu6050.getAngleZ();
  //  Serial.println(a);
  if (b < 3 && b > -3)
  {
    bot.backward(pwm, pwm, pwm, pwm);
  }
  if (b > 3)
  {
    bot.backward(pwm + offset, pwm + offset, pwm, pwm);
  }
  if (b < -3)
  {
    bot.backward(pwm, pwm, pwm + offset, pwm + offset);
  }
}

void left(byte pwm = 100) {
  mpu6050.update();
  b = mpu6050.getAngleZ();
  if (b < 3 && b > -3)
  {
    bot.left(pwm, pwm, pwm, pwm);
    //    Serial.println("Left...");
  }
  else if (b > 3)
  {
    bot.left(pwm, pwm + offset, pwm + offset, pwm);
    //    Serial.println("Goes Backward bt then goes Leftward");
  }
  else if (b < -3)
  {
    bot.left(pwm + offset, pwm, pwm, pwm + offset);
    //    Serial.println("Goes Forward bt then goes Leftward");
  }
}


void right(byte pwm = 100) {
  mpu6050.update();
  b = mpu6050.getAngleZ();
  if (b < 3 && b > -3)
  {
    bot.right(pwm, pwm, pwm, pwm);
    //    Serial.println("Right...");
  }
  else if (b > 3)
  {
    bot.right(pwm + offset, pwm, pwm, pwm + offset);
    //    Serial.println("Goes Forward bt then goes Rightward");
  }
  else if (b < -3 )
  {
    bot.right(pwm, pwm + offset, pwm + offset, pwm);
    //    Serial.println("Goes Backward bt then goes Rightward");
  }
}


//void ftbreak()
//{
//  while (a <= 1)
//  {
//
//    mpu6050.update();
//    a = mpu6050.getangleZ();
//    bot.anticlockwise(40, 40, offset, offset);
//    Serial.println("Anticlockwise for 15 degrees only...");
//    //          Serial.println(mpu6050.getangleZ());
//  }
//}
//
//    //===================================Clockwise 15 degree break======================
//
//    void Negftbreak()
//    {
//      while (angleZ >= -75)
//      {
//        mpu6050.update();
//        angleZ = mpu6050.getangleZ();
//        bot.clockwise(40, 40, offset, offset);
//        Serial.println("Clockwise for 15 degrees only...");
//        //          Serial.println(mpu6050.getangleZ());
//      }
//    }

//==================================================================================
