int sensorPin = A1;
float temperatura = 0;
int volt = 0;
int led1 = 3;
int led2 = 7;
int led3 = 11;
int readValue = 0;
int lastValue = 1;

void setup()
{
  Serial.begin (9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  //analogReference (INTERNAL);
  }

void loop()
{
  //Lectura digital
  readValue = analogRead(sensorPin);
  if (temperatura < 20){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  } else if (temperatura >= 20 && temperatura <= 30){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);


  } else {(temperatura >30);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }

  
  //Lectura Analoga
  readValue = analogRead(sensorPin);
  if (lastValue != readValue) {
    Serial.print("readValue: ");
    Serial.print(readValue);
    lastValue = readValue;
    volt = 5.0 / 1024 * readValue;
    Serial.print(" -> voltsValue: ");
    Serial.print(volt);
    temperatura = volt * 100 -50;
    Serial.print(" -> tempValue: ");
    Serial.println(temperatura);
    delay(1000);
  }  
}