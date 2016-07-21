/*Experimentory 2016 Rover Blocking Project
 * Starter code by: Meghan Jimenez
 * Additional code by:
 */

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

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
}

void forward(){
  move(1, 56, 1); //motor 1, low speed, forward
  move(2, 50, 1); //motor 2, low speed, forward
  delay(1000);
  stop();
}

void backward(){
  move(1, 54, 0); //motor 1, low speed, reverse
  move(2, 50, 0); //motor 2, low speed, reverse
  delay(1000);
  stop();
}

void left(){
  move(1, 50, 1); //motor 1, low speed, forward
  move(2, 50, 0); //motor 2, low speed, reverse
  delay(1000);
  stop();
}

void right(){
  //go();
  move(1, 50, 0); //motor 1, low speed, reverse
  move(2, 50, 1); //motor 2, low speed, forward
  delay(1000);
  stop();
}

void softLeft(){
  move(1, 50, 1); //motor 1, low speed, forward
  move(2, 50, 0); //motor 2, low speed, reverse
  delay(500);
  stop();
}

void softRight(){
  move(1, 50, 0); //motor 1, low speed, reverse
  move(2, 50, 1); //motor 2, low speed, forward
  delay(500);
  stop();
}

