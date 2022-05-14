// Codigo Ejemplo
int Led_Pin = 13;
int Led_Rgb1 = 6;
int Led_Rgb2 = 5;
int Led_Rgb3 = 3;

void setup()
{
  //Configurar Pin como Salida
  pinMode(Led_Pin, OUTPUT);
  pinMode(Led_Rgb1, OUTPUT);
  pinMode(Led_Rgb2, OUTPUT);
  pinMode(Led_Rgb3, OUTPUT);
}

void loop()
{
  //Encender Led
  digitalWrite(Led_Pin, HIGH);
  //Esperar un segundo
  delay(1000);
  //Apagar Led
  digitalWrite(Led_Pin, LOW);
  //Esperar un segundo
  delay(1000); 
  //Encender Led Rgb
  digitalWrite(Led_Rgb1,HIGH);
  digitalWrite(Led_Rgb2,LOW);
  digitalWrite(Led_Rgb3,LOW);
  delay(1000);
  digitalWrite(Led_Rgb1,HIGH);
  digitalWrite(Led_Rgb2,LOW);
  digitalWrite(Led_Rgb3,HIGH);
  delay(1000);
  digitalWrite(Led_Rgb1,LOW);
  digitalWrite(Led_Rgb2,LOW);
  digitalWrite(Led_Rgb3,HIGH);
  delay(1000);
}