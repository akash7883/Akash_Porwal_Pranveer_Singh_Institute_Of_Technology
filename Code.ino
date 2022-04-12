#include <TinyGPS.h>
#include <SoftwareSerial.h>
#define greenLed 10
#define redLed 8
#define sensor 6
// Configure software serial port
SoftwareSerial SIM900(7, 8);
String textMessage;
TinyGPS gps;
 char inchar;
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  SIM900.begin(9600);
   delay(5000);
  Serial.print("SIM900 ready...");
pinMode(greenLed,OUTPUT);
pinMode(redLed,OUTPUT);
digitalWrite(greenLed,HIGH);
pinMode(sensor,INPUT);

// AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
int x= analogRead(sensor);
if (x>600){
  // enable the red light
  digitalWrite(redLed,HIGH);
 // enable gps to activate the gps
  gps_activation();
  // enable gsm to send message
  send_sms();
}
}

  gps_activation(){
    
  }
  
void send_sms(String location){
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
 SIM900.println("AT + CMGS = \"+91121\""); 
  delay(100);
  // Send the SMS
  SIM900.println(message); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  // Give module time to send SMS
  delay(5000);  
}}
