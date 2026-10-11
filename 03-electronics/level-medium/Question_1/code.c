#include <Wire.h>
#include <Arduino.h>
#include <DHT.h>

#define PPM_PIN 4
#define buzzer 18

const int threshold = 500; // in PPM

DHT dht(14,DHT22);

void setup() {
  Wire.begin(23, 22);
  Serial.begin(115200);
  pinMode(buzzer,OUTPUT);

  dht.begin();

}

void loop() {

   int16_t ppmValue = analogRead(PPM_PIN);
   int mappedppmValue = (ppmValue/4.095);

   Serial.print("PPM: ");
   Serial.println(mappedppmValue);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));


  if(mappedppmValue > threshold && h > 70.00 )
  {
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }

   delay(100); 
}

