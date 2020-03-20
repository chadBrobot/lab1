//Arduino PWM Speed Control：
int lm_pin = 5;   //PWM on M2
int lm_dir = 4;   //direction control on M2
int rm_pin = 6;   //PWM for M1
int rm_dir = 7;   //direction control for M1 


/*left turn sppeds*/
//int l_speed = 128; 
//int r_speed = 100;
/*right turn sppeds*/
int l_speed = 110; 
int r_speed = 98;

int goFor = 2100;

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

void backward(int motor_dir, int motor_pin, int speedy){
  digitalWrite(motor_dir,LOW);
  analogWrite(motor_pin, speedy);
  }

void left90(){
  //the 90 degree turn to the left
  int l_speed90 = 128; 
  int r_speed90 = 100;
  forward(rm_dir, rm_pin, r_speed90);
  backward(lm_dir, lm_pin, l_speed90);
  delay(435);
  backward(rm_dir, rm_pin, r_speed90);
  forward(lm_dir, lm_pin, l_speed90);
  delay(40);
  release(lm_pin);
  release(rm_pin);
  delay(2000);
  }

void right90(){
  int l_speed90 = 117; 
  int r_speed90 = 98;
  //the 90 degree turn to the right
  backward(rm_dir, rm_pin, r_speed90);
  forward(lm_dir, lm_pin, l_speed90);
  delay(455);
  forward(rm_dir, rm_pin, r_speed90);
  backward(lm_dir, lm_pin, l_speed90);
  delay(40);
  release(lm_pin);
  release(rm_pin);
  delay(2000);
}

void loop() {
   delay(4000);
  //goes relatively straight (like jack) and then stops
  for(int i = 0; i < 4; i++){
    forward(lm_dir, lm_pin, l_speed);
    forward(rm_dir, rm_pin, r_speed);
    delay(goFor);
    //set backwards
    backward(lm_dir, lm_pin, 255);
    backward(rm_dir, rm_pin, 255);
    delay(65);
    release(lm_pin);
    release(rm_pin);
    delay(1000);
    right90();
    delay(1000);
  }
  while(1){}
  
}
