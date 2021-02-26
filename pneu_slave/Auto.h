#include "MPU.h"

//  while (1) {
//    unsigned long millis1 = millis();
//    unsigned long millis2 = 0;
//    Serial.println(abs(millis2 - millis1));
//    while (abs(millis2 - millis1) < 2000) {
//      if (tfmini2.getDistance() >= 62 && tfmini2.getDistance() <= 64) {
//        bot.brake();
//        Serial.print("Brake - ");
//        Serial.println(tfmini2.getDistance());
//      } else if (tfmini2.getDistance() < 62) {
//        forward(40);
//        Serial.print("Forward - ");
//        Serial.println(tfmini1.getDistance());
//        millis2 = millis1;
//      } else if (tfmini2.getDistance() > 64) {
//        backward(40);
//        Serial.print("Backward - ");
//        Serial.println(tfmini1.getDistance());
//        millis2 = millis1;
//      }
//    }
//  }

//  while (tfmini1.getDistance() >= 38 && tfmini1.getDistance() <= 40) {
//    if (tfmini2.getDistance() >= 62 && tfmini2.getDistance() <= 64) {
//      bot.brake();
//      Serial.print("Brake - ");
//      Serial.println(tfmini2.getDistance());
//    } else if (tfmini2.getDistance() < 62) {
//      forward(40);
//      Serial.print("Forward - ");
//      Serial.println(tfmini1.getDistance());
//    } else if (tfmini2.getDistance() > 64) {
//      backward(40);
//      Serial.print("Backward - ");
//      Serial.println(tfmini1.getDistance());
//    }
//    break;
//  }

//    delay(300);
//
//    if (tfmini1.getDistance() >= 60 && tfmini1.getDistance() <= 62) {
//      bot.brake();
//      Serial.print("Brake");
//      Serial.println(tfmini2.getDistance());
//    } else if (tfmini1.getDistance() < 60) {
//      bot.right(45, 45, 45, 45);
//      Serial.print("Right");
//      Serial.println(tfmini2.getDistance());
//    } else if (tfmini1.getDistance() > 62) {
//      bot.left(45, 45, 45, 45);
//      Serial.print("Left");
//      Serial.println(tfmini2.getDistance());
//      //    }
//      //
//      //    delay(300);
//
//    }

void autoTask() {
  //  while (millis() < 5000) {
  //    left();
  //  }
  //  bot.brake();
  //  delay(1000);
  //  while(tfmini2.getDistance() > 200) {
  //    left();
  //  }
  //  bot.brake();
  //  delay(500);
  //  while()
  while (tfmini2.getDistance() < 80 || tfmini2.getDistance() == 30) {
    forward();
  }
  bot.brake();
  delay(500);
  while (tfmini1.getDistance() > 70) {
    left();
  }
  bot.brake();
  delay(500);
  while (tfmini2.getDistance() > 65) {
    backward();
  }
  Serial.println("TF mini2 is now closer than 100");
  bot.brake();

  // align

  if (tfmini1.getDistance() >= 58 && tfmini1.getDistance() <= 62) {
    bot.brake();
  } else if (tfmini1.getDistance() < 58) {
    bot.right(30, 30, 30, 30);
  } else if (tfmini1.getDistance() > 62) {
    bot.left(30, 30, 30, 30);
  }
}
