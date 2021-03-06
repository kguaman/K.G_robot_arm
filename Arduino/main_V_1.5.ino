/*
I'm currently working on implementing bluetooth module code is incomplete
*/

# include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial Bluetooth(1,2); //RX|TX

Servo serv1;
Servo serv2;
Servo serv3;
Servo serv4;

// servo current position 
int serv1pos,serv2pos,serv3pos,serv4pos;

//previous position 
int serv1pre_pos,serv2pre_pos,serv3pre_pos,serv4pre_pos;
int const speed = 10;

String data = ""; // to get info form data 

void setup() {
  // setup servo
   servo_attach();

 // start bluetooth 38400 is the default baud rate 
   Bluetooth.begin(38400); 
   Bluetooth.setTimeout(1); // settimeout what for stream data ms 
   delay(speed);
   initalposition();
}

void loop() {
  // check if data is being sent
  if (Bluetooth.available() > 0){
    data = Bluetooth.readString();
    if (data.startsWith("M1")){ 
      String data_sl = data.substring(2,data.length()); 
      serv1pos = data_sl.toInt();
      
      // from current postion to data we use loop for a swift motion
      if (serv1pre_pos > serv1pos){ 
        // if pre > current we decrement 
        for(int i = serv1pre_pos; i  >= serv1pos; i--){
          serv1.write(i);  
          delay(speed); // "creates" a speed at which motor move 
        }
      }
      
      if (serv1pre_pos < serv1pos){ // if pre < current we increment
        for (int i = serv1pre_pos; i <= serv1pos; i++){
          serv1.write(i);
          delay(speed);
        }
      }
      // once servopos is reached we make pre = current 
      serv1pre_pos = serv1pos;
    }
    // as servo1 we follow the same steps for other servo 
    // if the slider2  is moved 

    if (data.startsWith("M2")){
      String data_S2 = data.substring(2,data.length());
      serv2pos = data_S2.toInt();

      if ( serv2pre_pos > serv2pos){
        for (int i = serv2pre_pos; i >= serv2pos; i--){
          serv2.write(i);
          delay(speed);
        }
      }
      if(serv2pre_pos< serv2pos){
        for (int i = serv1pre_pos; i <= serv2pos; i++){
          serv2.write(i);
          delay(speed); 
        }
      }
       serv2pre_pos = serv2pos;
    }  
   
   if(data.startsWith("M3")){
    String data_S3 = data.substring(2,data.length());
    serv3pos = data_S3.toInt();
    
    if ( serv3pos > serv3pre_pos){
      for (int i = serv3pre_pos; i <= serv3pos; i++){
        serv3.write(i);
        delay(speed);
      }
    }
    if(serv3pos < serv3pre_pos){
      for (int i = serv3pre_pos; i >= serv3pos; i--){
        serv3.write(i);
        delay(speed);
      }
    }
    serv3pre_pos = serv3pos;
   }
    
   if (data.startsWith("M4")){
    String data_S4 = data.substring(2,data.length());
    serv4pos = data_S4.toInt();
    
    if (serv4pos > serv4pre_pos){
      for (int i = serv4pre_pos; i <= serv4pos;i++){
        serv4.write(i);
        delay(speed); // test to make sure delay speed is prefect for you
      }
    }
    if (serv4pre_pos > serv4pos){
     for (int i = serv4pre_pos; i >= serv4pos; i--){
      serv4.write(i);
      delay(speed);
      }
    }
    serv4pre_pos = serv4pos;
   }
    // user stops the motor movments
   if (data == "Stop"){
        while(1);
      }
   }
   
 }  
 static void initalposition(){
    // the arm postion when it turns on 
    serv1pos = 90; // postion depend on the motor check first to see if anglr fits ur need 
    serv1.write(serv1pos);
    serv2pos = 150;
    serv2.write(serv2pos);
    serv3pos = 35;
    serv3.write(serv3pos);
    serv4pos = 140;
    serv4.write(serv4pos);
  }
  static void servo_attach(){
    serv1.attach(5);
    serv2.attach(6);
    serv3.attach(7);
    serv4.attach(8);
  }
