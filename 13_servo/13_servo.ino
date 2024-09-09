// deneme kartı üzerindeki 0-60 derece arasında dönebilen servo motoru çalıştırma
#include <Servo.h>                // servo kütüphanesini ekle
Servo motor;
int aci=0;                        // moturun açısını tutan değişken
//***************************************
void setup() 
{
  motor.attach(D4);             
  motor.write(aci);
  delay(1000);
}
//***************************************
void loop() 
{
  aci=aci+10;
  if(aci>60)
    aci=0;
  motor.write(aci);
  delay(500);                 // 500ms bekleme
}
