#include<Servo.h>

//Joystick 1 (X and Y axis)
int x_pin1 = A0;
int y_pin1 = A1;

//Joystick 2 (X and Y axis)
int x_pin2 = A2;
int y_pin2 = A3;

//Joystick Buttons and Servo
int servoPin5 = 8;
int angleStep = 3;
int angle5 = 0;

#define LEFT 0
#define RIGHT 1

//Initialize all servos at position degree 0
int pos2, pos4 = 0;
int pos1, pos3, pos6, pos7 = 180;

//Servo Objects
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;
Servo s7;

void setup() {
  Serial.begin(500000);

  s5.attach(servoPin5);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  s5.write(angle5);


  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  s1.attach(3);
  s1.write(pos1);

  s2.attach(4);
  s2.write(pos2);

  s3.attach(5);
  s3.write(pos3);

  s4.attach(6);
  s4.write(pos4);

  s6.attach(9);
  s6.write(pos6);

  s7.attach(10);
  s7.write(pos7);

}

void loop() {
  //Reading X and Y axis of Joystick 1
  int x_data1 = analogRead(A0);
  int y_data1 = analogRead(A1);

  //Reading X axis of Joystick 2
  int x_data2 = analogRead(A2);
  int y_data2 = analogRead(A3);

  Serial.print("x_data1:");
  Serial.print(x_data1);
  Serial.print("\t");
  Serial.print("y_data1:");
  Serial.print(y_data1);
  Serial.print("\t");
  Serial.print("x_data2:");
  Serial.print(x_data2);
  Serial.print("y_data2:");
  Serial.print(y_data2);
  delay(15);

  //Servo 1 control with Joystick 1
  if(x_data1 >= 550)
  {
    if(pos1 <= 180)
    {
      pos1 = pos1 + 3;
      s1.write(pos1);
    }
  }
  
  else if(x_data1 <= 450)
  {
    if(pos1 >= 0)
    {
      pos1 = pos1 - 3;
      s1.write(pos1);
    }
  }

  if(x_data1 >= 550)
  {
    if(pos6 >= 0)
    {
      pos6 = pos6 - 3;
      s6.write(pos6);
    }
  }
  
  else if(x_data1 <= 450)
  {
    if(pos6 <= 180)
    {
      pos6 = pos6 + 3;
      s6.write(pos6);
    }
  }

  //Servo 2 control with Joystick 1
  if(y_data1 >= 550)
  {
    if(pos2 <= 180)
    {
      pos2 = pos2 + 3;
      s2.write(pos2);
    }
  }

  else if(y_data1 <= 450)
  {
    if(pos2 >= 0)
    {
      pos2 = pos2 - 3;
      s2.write(pos2);
    }
  }


  //Servo 3 control with Joystick 2
  if(x_data2 >= 550)
  {
    if(pos3 <= 180)
    {
      pos3 = pos3 + 3;
      s3.write(pos3);
    }
  }

  else if(x_data2 <= 450)
  {
    if(pos3 >= 0)
    {
      pos3 = pos3 - 3;
      s3.write(pos3);
    }
  }

  if(x_data2 >= 550)
  {
    if(pos7 >= 0)
    {
      pos7 = pos7 - 3;
      s7.write(pos7);
    }
  }

  else if(x_data2 <= 450)
  {
    if(pos7 <= 180)
    {
      pos7 = pos7 + 3;
      s7.write(pos7);
    }
  }

  
  //Servo 4 Control with Joystick 2
 if(y_data2 >= 550)
  {
    if(pos4 <= 180)
    {
      pos4 = pos4 + 3;
      s4.write(pos4);
    }
  }

  else if(y_data2 <= 500)
  {
    if(pos4 >= 0)
    {
      pos4 = pos4 - 3;
      s4.write(pos4);
    }
  }

  while(digitalRead(RIGHT) == LOW)
  {
    angle5 = angle5 - angleStep;
    if(angle5 < 0)
    {
      angle5 = 0;
    }
    else
    {
      s5.write(angle5);
    }
    delay(10);
  }

  while(digitalRead(LEFT) == LOW)
  {
    angle5 = angle5 + angleStep;
    if(angle5 > 180)
    {
      angle5 = 180;
    }
    else
    {
      s5.write(angle5);
    }
    delay(10);
  }
}


