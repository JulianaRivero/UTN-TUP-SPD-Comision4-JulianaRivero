int led1 = 13;
int led2 = 12;
int led3 = 11;
int buzzer = 5;
int distancia = 0;
 
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
 
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  // measure the ping time in cm
  distancia = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  Serial.print("in, ");
  Serial.print(distancia);
  Serial.println("distancia");
  delay(100); // Wait for 100 millisecond(s)
 
  if (distancia > 206) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  if (distancia < 206 && distancia > 145) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(buzzer, HIGH);
    delay(700);
    digitalWrite(buzzer, LOW);
    delay(700);
  }
  if (distancia < 145 && distancia > 20) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  }
}