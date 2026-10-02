

#define RED 13
#define YELLOW 12
#define GREEN 11
#define LDR 10

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(LDR, INPUT);
  
}

void loop()
{
  
  if(!digitalRead(LDR)){
  digitalWrite(RED, HIGH);
  delay(7000);
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW,HIGH);
  delay(5000);
  digitalWrite(YELLOW,LOW);
  digitalWrite(GREEN,HIGH);
  delay(2000);
  digitalWrite(GREEN,LOW);}
}