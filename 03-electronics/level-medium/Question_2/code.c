
const int trig = 5;
const int echo = 18;
const int ldr = 14;
const int led = 16;

#define Sound 0.034
#define cm_to_inch 0.393701

long duration;
float dCm;
float dInch;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  ledcAttach(led,5000,8);
  pinMode(ldr,INPUT);
}

void loop() {
  // LDR
  int reading = analogRead(ldr)/8;


  // Ultrasonic
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

// So this will basically trigger a wave
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  // Checkin pulse   
  duration = pulseIn(echo,HIGH);;
  
  //calculating in cm 
  dCm = duration * Sound/2;

  Serial.println(reading);
  if(dCm<10)
  {
    Serial.println("Static!");
    ledcWrite(led,reading);
  }
  else if(dCm < 20)
  {
    Serial.println("Blinking!");
    ledcWrite(led,reading);
    delay(600);
    ledcWrite(led,0);
    delay(600);
  }
  else
  {
    Serial.println("Off!");
    delay(600);
    ledcWrite(led,0);
  }

  //Serial.print("The distance is : ");Serial.println(dCm);

}
