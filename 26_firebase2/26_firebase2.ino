// firebase realtime database'e bağlanıp float deger okuma
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>                        // firebase kütüphanesini ekle

const char *ssid = "xxxxxxxxxxxxx";                 // bağlanılacak olan kablosuz ağın SSID si
const char *password = "xxxxxxxx";                  // bağlanılacak olan kablosuz ağın şifresi

#define FIREBASE_HOST "********.firebaseio.com"     // veritabanının linki
#define FIREBASE_AUTH "**************"              // veritabanı secret key
//------------------------------------------------------------------------------------
void setup() 
{
  Serial.begin(9600);                             //Seri iletişim hızı 9600 bps olarak ayarlanarak başlatılıyor.
  delay(1000);
  Serial.println("Wifi agina baglaniliyor");

  WiFi.mode(WIFI_STA);                           //ESP8266 istasyon moduna alınıyor. 
  WiFi.begin(ssid, password);                    //SSID ve şifre girilierek wifi başlatılıyor.

  //------- Wifi ağına bağlanıncaya kadar beklenilen kısım ------------
  while (WiFi.status() != WL_CONNECTED) 
  { 
    delay(500);                                 // Bu arada her 500 ms de bir seri ekrana yan yana noktalar yazdırılarak
    Serial.print(".");                          //görsellik sağlanıyor.
  }
  //-------------------------------------------------------------------

  Serial.println("");                           //Bir alt satıra geçiliyor.
  Serial.println("Bağlantı sağlandı...");       //seri ekrana bağlantının kurulduğu bilgisi gönderiliyor.

  Serial.print("Alınan IP addresi: ");          // kablosuz ağdan alınan IP adresi
  Serial.println(WiFi.localIP());               // kablosuz ağdan alınan IP adresi

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); // firabase i başlat
}
//------------------------------------------------------------------------------------
void loop() 
{
  // get Float value
  Serial.print("Veritabanından okunan veri: ");
  Serial.println(Firebase.getFloat("sicaklik"));     // Float_deger etiketi altındaki degeri oku
  delay(1000);
}
