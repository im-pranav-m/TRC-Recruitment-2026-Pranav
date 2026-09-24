void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Red light");
  delay(10000);
  Serial.println("Green light");
  delay(7000);
  Serial.println("Yellow light");
  delay(3000);
}