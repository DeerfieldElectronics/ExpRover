/*Experimentory 2016 Rover Blocking Project
 * Starter code by: Meghan Jimenez
 * Additional code by:
 */

/*
 * Control functions:
 * stop(), forward(), backward(), left(), right(), softLeft(), softRight()
 */
 //Photoresistor variables
 int rightPR = A0;
 int leftPR = A1;
 
 int rightValue = 0;
 int leftValue = 0;

 int threshold = 700;

 //Motor control variables
 int STBY = 10; //standby

  //Motor A
  int PWMA = 3; //Speed control 
  int AIN1 = 9; //Direction
  int AIN2 = 8; //Direction
  
  //Motor B
  int PWMB = 5; //Speed control
  int BIN1 = 11; //Direction
  int BIN2 = 12; //Direction

void setup() {
  // put your setup code here, to run once:
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  
  Serial.begin(9600);  
  Serial.println("Ready to line follow!");

}

void loop() {
  // put your main code here, to run repeatedly:
  rightValue = analogRead(rightPR);
  leftValue = analogRead(leftPR);
  Serial.println(leftValue);
  Serial.print(rightValue);
  Serial.println();
  if (leftValue < threshold && rightValue < threshold){
    stop();
  }
  else if (leftValue< threshold){
    left();
  }
  else if (rightValue < threshold){
    right();
  }
  else{
    forward();
  }
  //delay(100);
} 



/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

 
//Move function from http://bildr.org/2012/04/tb6612fng-arduino/
void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A

//speed: 0 is off, and 255 is full speed

//direction: 0 clockwise, 1 counter-clockwise



  digitalWrite(STBY, HIGH); //make sure that robot is not in standby 

  boolean inPin1 = LOW; //inPins choose which direction the motor is spinning
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1); //chooses motor A and sets the direction by changing the inPin
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);   //changes motor speed by setting PWM for A to the input speed
  }else{
    digitalWrite(BIN1, inPin1); //same as above but for B
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void stop(){  
  move(1, 0, 0); //motor 1, stop
  move(2, 0, 0); //motor 2, stop
  delay(100);
}

void forward(){
  move(1, 56, 1); //motor 1, low speed, forward
  move(2, 50, 1); //motor 2, low speed, forward
  delay(100);
  //stop();
}

void backward(){
  move(1, 54, 0); //motor 1, low speed, reverse
  move(2, 50, 0); //motor 2, low speed, reverse
  delay(100);
  //stop();
}

void left(){
  move(1, 50, 1); //motor 1, low speed, forward
  move(2, 50, 0); //motor 2, low speed, reverse
  delay(100);
  //stop();
}

void right(){
  //go();
  move(1, 50, 0); //motor 1, low speed, reverse
  move(2, 50, 1); //motor 2, low speed, forward
  delay(100);
  //stop();
}

