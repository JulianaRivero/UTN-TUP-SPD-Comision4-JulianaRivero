// Codigo Ejemplo
int buttonState = 0;

void setup()
{
  //Configurar Pin como Entrada
  pinMode(2, INPUT);
  //Configurar Pines como Salida
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  //Leer Estado del Puerto de Entrada 2
  buttonState = digitalRead(2);
  //Actual Segun el Estado de la Lectura
  if (buttonState == HIGH){
  //Apagar Led en puerto 7
  digitalWrite(7, LOW);
  //Encender Led en Puerto 13
  digitalWrite(13,HIGH);
  //Esperar 1 Segundo
  delay(1000);
  //Encender Led en Puerto 7
  digitalWrite(7,HIGH);
  //Apagar Led en puerto 13
  digitalWrite(13, LOW);
  //Esperar 1 Segundo
  delay(1000);
  }else{
  //Apagar Led en puerto 7 y 13
  digitalWrite(7,LOW);
  digitalWrite(13,LOW);
  }
}