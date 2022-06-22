//Temperatura
int readValue = 0;
int lastValue = 1;
int sensorPin = A2;
float voltsValue;
float tempValue;
int Led1_Pin= 4;
int Led2_Pin = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(Led1_Pin, OUTPUT);
  pinMode(Led2_Pin, OUTPUT);
}

void loop()
{
  //Lectura digital
  readValue = analogRead(sensorPin);
  if (tempValue >20){
  digitalWrite(7, HIGH);
  digitalWrite(4, LOW);
  }else{
  digitalWrite(7, LOW);
  digitalWrite(4, HIGH);
  delay(1000);
  }
  
  
  //Lectura Analoga
  readValue = analogRead(sensorPin);
  if (lastValue != readValue) {
    Serial.print("readValue: ");
    Serial.print(readValue);
    lastValue = readValue;
    voltsValue = 5.0 / 1024 * readValue;
    Serial.print(" -> voltsValue: ");
    Serial.print(voltsValue);
    tempValue = voltsValue * 100 -50;
    Serial.print(" -> tempValue: ");
    Serial.println(tempValue);
  }
  delay(100);
}