//Project-1: //ARDUINO LINE FOLLOWING CAR - QUAD Robotics - A unit of Quad Store//
//www.quadstore.in

// YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
// GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //


//including the libraries
#include <AFMotor.h>

//defining pins and variables
#define lefts A0
#define rights A2

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  //Setting the motor speed
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
  //Declaring PIN input types
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  //Begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  //Printing values of the sensors to the serial monitor
  Serial.println(digitalRead(lefts));
  Serial.println(digitalRead(rights));
  //line detected by both
  if(digitalRead(lefts)==1 && digitalRead(rights)==1){
    //Forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);

  }
  //line detected by left sensor
  else if(digitalRead(lefts)==0 && digitalRead(rights)==1){
    //turn left
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    
  }
  //line detected by right sensor
  else if(digitalRead(lefts)==1 && digitalRead(rights)==0){
    //turn right
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
   
  }
  //line detected by none
  else if(digitalRead(lefts)==0 && digitalRead(rights)==0){
    //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
   
  }
  /*
   motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);

     motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);

     motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  */
  
}