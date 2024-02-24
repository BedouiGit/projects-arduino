
#include <Servo.h>


#include "dht.h"
#define dht_apin 8 // Analog Pin sensor is connected to
 Servo myservo; 
dht DHT;
const int buzzer = 3;
void setup(){
 pinMode(2,OUTPUT); //LED
 pinMode(buzzer,OUTPUT);
 myservo.attach(7);
  Serial.begin(9600);
  //delay(500);//Delay to let system boot
 // Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  //delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print(DHT.temperature); 
    Serial.print("C");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
    if (DHT.temperature >=23)
{
  myservo.write(180);                  // sets the servo position according to the scaled value 
  digitalWrite(2,HIGH);
  //digitalWrite(buzzer,high);
  tone(buzzer,1000);
  delay(500);
   //digitalWrite(8,low);
noTone(3); 
}
else{

digitalWrite(2,LOW);
 
}
 
  //Fastest should be once every two seconds.
 
}// end loop() 
