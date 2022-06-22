#include <IRremote.h>

int RECV_PIN = 14;
int IRData = 0;
int Led_Pin1 = 7;
int Led_Pin2 = 8;
int Led_Status = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(Led_Pin1, OUTPUT);
  pinMode(Led_Pin2, OUTPUT);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
  {
    // Mostrar Lectura
    IRData = results.value;
    irrecv.resume();
    Serial.print("Datos: ");
    Serial.print(IRData, HEX);
    Serial.print(" {");
    Serial.print(IRData);
    Serial.println("}");

    // Controlar Led
    if (IRData == 2295)
    {
      if (Led_Status == 0)
      {
        digitalWrite(Led_Pin1, 1);
        Led_Status = 1;
        digitalWrite(Led_Pin2, 1);
        Led_Status = 1;
      }
      else
      {
        digitalWrite(Led_Pin1, 0);
        Led_Status = 0;
        digitalWrite(Led_Pin2, 0);
        Led_Status = 0;
      }
    }
  }
}
