// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop()
{
 int value = analogRead(A0);
 
  if(value > 186){Serial.println("Fan ON");}
  else if(value < 153){Serial.println("Fan OFF");}
  else {Serial.println("Fan STANDBY");}
  delay(1000);
  
}