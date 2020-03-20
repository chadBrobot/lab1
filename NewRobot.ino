//Arduino PWM Speed Control：
int rm_pin = 5;   //PWM on M2
int rm_dir = 4;   //direction control on M2
int lm_pin = 6;   //PWM for M1
int lm_dir = 7;   //direction control for M1 

int l_speed = 100;
int r_speed = 100;

void setup() {
    pinMode(lm_dir, OUTPUT);
    pinMode(rm_dir, OUTPUT);
}

void release(int motor){
  analogWrite(motor, 0);
  }

void forward(int motor_dir, int motor_pin, int speedy){
  digitalWrite(motor_dir,HIGH);
  analogWrite(motor_pin, speedy);
  }

void backward(int motor, int speedy){
  digitalWrite(motor,LOW);
  analogWrite(motor, speedy);
  }

void loop() {
   {    
  forward(lm_dir, lm_pin, l_speed);
  forward(rm_dir, rm_pin, r_speed);
  delay(2000);
  release(lm_pin);
  release(rm_pin);
  delay(2000);
 /** / delay(2000);
  release(left_motor);
  release(right_motor);
  backward(left_motor, left_speed);
  backward(right_motor, right_speed);
  delay(2000);
    
  /* * /  digitalWrite(right_motor,LOW);
    digitalWrite(left_motor, LOW);
    analogWrite(left_motor_sp, left_speed);   //PWM Speed Control
    analogWrite(right_motor_sp, right_speed);   //PWM Speed Control
    delay(30);
    release(right_motor);
    release(left_motor);
 /* */
  
  }
}
