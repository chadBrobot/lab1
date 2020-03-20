#include <AFMotor.h>
#include <math.h> 
//set up for motor and speeds
// Authors: Jack Casey-Campbell and Breann Thiessen
AF_DCMotor motor_left(1); //pin 11
AF_DCMotor motor_right(2); //pin 3

int speed_right = 125;

int speed_left = (30 + (0.435*speed_right)) + (0.00152 * (speed_right * speed_right));// forward formula   
//int speed_left = (-391 + (102 * log(speed_right)));//backward formula

void setup() {
  delay(2000);
  Serial.begin(9600);           
  motor_left.setSpeed(speed_left);
  motor_right.setSpeed(speed_right);
  motor_left.run(RELEASE);
  motor_right.run(RELEASE); 
}


void loop() {
  motor_left.run(FORWARD);
  motor_right.run(FORWARD);
  delay(2000);
  motor_left.run(RELEASE);
  motor_right.run(RELEASE);
}
