// Codigo Ejemplo
int Led_Pin = 3;
int Led_Pin2 = 2;
int Fot_Pin = A0;
int Int_Pin = 2;
int sensorValue = 0;
int inputValue = 0;
int counter = 0;


//Limites invierno
int start1 = 18;
int stop1 = 24;

//Limites verano
int start2 = 20;
int stop2 = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(Led_Pin, OUTPUT);
  pinMode(Led_Pin2, OUTPUT);
  pinMode(Int_Pin, INPUT);
  
}

void loop()
{
  //Lectura digital
  inputValue = digitalRead(Int_Pin);
  if (inputValue == HIGH)
  {
    Serial.println("Led: Encendido");
   digitalWrite(Led_Pin, 1);
    digitalWrite(Led_Pin2, 1);
  }
  else
  {
    if(counter >= start1)
    {
      //Lectura Analógica
      sensorValue = analogRead(Fot_Pin);
      if(sensorValue < 500)
      {
        Serial.println("Led: Encendido");
        digitalWrite(Led_Pin, 1);
        digitalWrite(Led_Pin2, 1);
      }else{
        Serial.println("Led: Apagado");
        digitalWrite(Led_Pin, 0);
        digitalWrite(Led_Pin2, 0);
      }
   }
    else
   {
     Serial.println("Led: Apagado");
        digitalWrite(Led_Pin, 0);
        digitalWrite(Led_Pin2, 0);
    }
}   
      
counter++;
Serial.print("Hora: ");
Serial.println(counter);
if (counter == 24)
{
  counter = 0;
}
delay(1000);
}

