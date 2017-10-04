#include <math.h>
const int in_1  = 10;
const int in_2  = 11;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(in_1, OUTPUT);
pinMode(in_2, OUTPUT);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
 delay(10000);

}
double Termistor(int analogOkuma)
{
  double sicaklik;
  sicaklik = log(((10240000 / analogOkuma) - 10000));
  sicaklik =1/(0.001129148 + (0.000234125 + (0.00000000876741 * sicaklik * sicaklik )) * sicaklik);
  sicaklik=sicaklik - 273.15;
  return sicaklik;
  }

void loop() {
  int deger;
  double sicaklik;
  deger=analogRead(A0);
  sicaklik=Termistor(deger);
  Serial.print("Şu anki Sıcaklık: ");
  Serial.println(sicaklik);
  delay(1000);
  noTone(12);

if (sicaklik >= 33)
{
  digitalWrite(in_1 , HIGH);
digitalWrite(in_2 , LOW);
digitalWrite(13,HIGH);
melodi();


noTone(12);
  }
  else if (sicaklik < 33)
  {
    digitalWrite(in_1 , LOW);
digitalWrite(in_2 , LOW);
digitalWrite(13,LOW);


    }
  
}

int melodi()
{
  tone(12,440);
 delay(200);
noTone(12);

  }
