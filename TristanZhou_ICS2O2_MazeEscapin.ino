/*
* A bunch of movement functions and demo for the robot, including but not limited to
* forward, backward, leftwheel, STOPHIGH, accelerateHIGH
* also contains distance detect code and functions for maze escape
*
*Programmer: Tristan Zhou
*
*Last Updated: mm/dd/yyyy | 2/1/2023
*
*/
//setting up servo and values for variables
#include <Servo.h>
Servo myservo;
#define SpeedLeft 5
#define SpeedRight 6
#define DirectionLeft 7
#define DirectionRight 8
#define PowerAll 3
#define Speed2 

int Echo = 12;
int Trig = 13;
long duration;
long distance;


int DetectFront(){
  myservo.write(90);
       delay(400);
       digitalWrite(Trig,LOW);
       delayMicroseconds(2);
       digitalWrite(Trig,HIGH);
       delayMicroseconds(20);
       digitalWrite(Trig, LOW);
       duration = pulseIn(Echo, HIGH);
       distance = duration / 58;
       Serial.print("Distance: ");
       Serial.println(distance);
       return distance;
}

int DetectLeft(){
  myservo.write(180);
       delay(400);
       digitalWrite(Trig,LOW);
       delayMicroseconds(2);
       digitalWrite(Trig,HIGH);
       delayMicroseconds(20);
       digitalWrite(Trig, LOW);
       duration = pulseIn(Echo, HIGH);
       distance = duration / 58;
       Serial.print("Distance: ");
       Serial.println(distance);
       return distance;
}

int DetectRight(){
  myservo.write(0);
       delay(400);
       digitalWrite(Trig,LOW);
       delayMicroseconds(2);
       digitalWrite(Trig,HIGH);
       delayMicroseconds(20);
       digitalWrite(Trig, LOW);
       duration = pulseIn(Echo, HIGH);
       distance = duration / 58;
       Serial.print("Distance: ");
       Serial.println(distance);
       return distance;
}

void forward(int speed){
  digitalWrite(PowerAll, HIGH);
  digitalWrite(DirectionLeft, HIGH);
  analogWrite(SpeedLeft, speed);
  digitalWrite(DirectionRight, HIGH);
  analogWrite(SpeedRight, speed-17);
  Serial.println("forward");
//Moves Forward
}
void backward(int speed){
  digitalWrite(PowerAll, HIGH);
  digitalWrite(DirectionLeft, LOW);
  analogWrite(SpeedLeft, speed);
  digitalWrite(DirectionRight, LOW);
  analogWrite(SpeedRight, speed);
  Serial.println("back");
  //Moves Backward
}
void left(int speed){
  digitalWrite(PowerAll, HIGH);
  digitalWrite(DirectionLeft, HIGH);
  analogWrite(SpeedLeft, speed);
  digitalWrite(DirectionRight, LOW);
  analogWrite(SpeedRight, speed);
  Serial.println("left");
  //Turns on the spot left
}
void right(int speed){
  digitalWrite(PowerAll, HIGH);
  digitalWrite(DirectionLeft, LOW);
  analogWrite(SpeedLeft, speed);
  digitalWrite(DirectionRight, HIGH);
  analogWrite(SpeedRight, speed);
  Serial.println("right");
  //Turns on the spot Right
}
void rightwheel(int speed, int speed2){
  digitalWrite(PowerAll, HIGH);
  digitalWrite(DirectionLeft, HIGH);
  analogWrite(SpeedLeft, speed2);
  digitalWrite(DirectionRight, HIGH);
  analogWrite(SpeedRight, speed);
  Serial.println("rightwheel");
  //Moves and Turns right
}
void leftwheel(int speed, int speed2){
  digitalWrite(PowerAll, HIGH);
  digitalWrite(DirectionLeft, HIGH);
  analogWrite(SpeedLeft, speed);
  digitalWrite(DirectionRight, HIGH);
  analogWrite(SpeedRight, speed2);
  Serial.println("leftwheel");
  //Moves and turns left
}
void STOP(){
  digitalWrite(PowerAll, LOW);
  Serial.println("Stop");
  //Stops the robot
}
void accelerateHIGH(int speed, int end) {
  for(int i=speed; i<=end; i++){
    forward(i);
    delay(20);
    Serial.println("accelerateHIGH");
    //accelerates forward to full speed from a stop
}}
void accelerateLOW(int speed, int end) {
  for(int i=speed; i<=end; i++){
    backward(i);
    delay(20);
    Serial.println("accelerateLOW");
    //accelerates backward to full speed from a stop
}}
void STOPHIGH(int speed, int end) {
  for(int i=speed; i>=end; i--){
    forward(i);
    delay(20);
    Serial.println("STOPHIGH");
    //decelerates from full forward speed to a stop
}}
void STOPLOW(int speed, int end) {
  for(int i=speed; i>=end; i--){
    backward(i);
    delay(20);
    Serial.println("STOPLOW");
    //decelerates from full backward speed to a stop 
}}
void setup() {
  // 
  myservo.attach(10);
  myservo.write(90);
  pinMode(SpeedLeft, OUTPUT);
  pinMode(SpeedRight, OUTPUT);
  pinMode(DirectionLeft, OUTPUT);
  pinMode(DirectionRight, OUTPUT);
  pinMode(PowerAll, OUTPUT);
  Serial.begin(9600);

  pinMode(Echo, INPUT);
pinMode(Trig, OUTPUT);
  }


void loop() {

  


      /* if (DetectFront() > 6){ //if distance is below 9 on the front side 
        if(DetectLeft() < 10) {
          rightwheel(50);
          delay(100);
          forward(75);
          delay(1000);
        } else {
          if(DetectRight() < 10) {
            leftwheel(50);
            delay(100);
            forward(75);
            delay(1000);
            }
            }
            }
         digitalWrite(PowerAll, LOW);
*/
         if(DetectFront()<5) {
          if(DetectRight() >37, DetectLeft()<37){ // if right is the only way to go then go right
            
          right(110);
          delay(600);
          forward(75);
          delay(1000);
         }
         else {
          if(DetectLeft() >37, DetectRight() <37){ //if left is the only way to go then go left
            
            left(110);
            delay(600);
            forward(75);
            delay(1000);
          }
         
         else{
          if(DetectLeft() <37, DetectRight()<37){ //if both distances are close then do a 180
          
          
          left(110);
          delay(1200);
          forward(75);
          delay(1000);
         }
         
         else{
          if(DetectLeft()>37,DetectRight()>37){ //if both distances are far then just go left
            left(110);
            delay(600);
            forward(50);
            delay(1000);
          }
          }
         }
         }
         }
       
         else { //if you can go forward then go forward
          forward(75);
          delay(100);
         }
         

}
         
          

   
              
