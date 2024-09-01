
#include <ESP32Servo.h>


int servo_value = 0;
int val;
int v;
const int servopin =1;
const int potpin =2;

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, servo");
  myservo.attach(servopin); 
  //Dabble.begin(115200);     //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.

}

void servo_turn_value(int v){
  Serial.print("value: ");
  Serial.println(v);
  myservo.write(v);
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
  v = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(v, 0, 720, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
 
  Serial.print(v);
  Serial.print(val);
  servo_turn_value(val);
  delay(100);              // wait for a second
  
}


