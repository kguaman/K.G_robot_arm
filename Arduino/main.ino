#include <Servo.h>

Servo  serv1;
Servo  serv2;
Servo  serv3;
// refer to potentiometer
int const potenpin1 = A0;
int const potenpin2 = A1;
int const potenpin3 = A2;

// value of of analog
int potenpinval;
// angle of sevo
int angle;

int const m_speed = 10;

void setup() {
  // connected to servo motor to PWM pins
  servo_attach();

  Serial.begin(9600);


}

void loop() {
  motor_movements();
  
}


void motor_movements() {
  potenpinval = analogRead(potenpin1);
  Serial.print("potenpin value :  ");
  Serial.print(potenpinval);
  angle = map(potenpinval, 0, 1023, 0, 359);
  serv1.write(angle);
  delay(m_speed );


  potenpinval = analogRead(potenpin2);
  Serial.print("potenpin value :  ");
  Serial.print(potenpinval);
  angle = map(potenpinval, 0, 1023, 0, 89);
  serv2.write(angle);
  delay(m_speed );

  potenpinval = analogRead(potenpin3);
  Serial.print("potenpin value :  ");
  Serial.print(potenpinval);
  angle = map(potenpinval, 0, 1023, 0, 79);
  serv3.write(angle);
  delay(m_speed );
}


void servo_attach(){
    serv1.attach(5);
    serv2.attach(6);
    serv3.attach(7);
}
    
