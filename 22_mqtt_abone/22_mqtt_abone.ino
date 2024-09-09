// shiftr.io sitesindeki projemizden veri alma
#include <ESP8266WiFi.h>
#include <MQTTClient.h>

const char *ssid = "xxxxxxxxxxxxx";                 // bağlanılacak olan kablosuz ağın SSID si
const char *password = "xxxxxxxx";                  // bağlanılacak olan kablosuz ağın şifresi

WiFiClient wifi_istemci;
MQTTClient mqtt_istemci;
//*********************************************************************
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
 
  mqtt_istemci.begin("******.cloud.shiftr.io", wifi_istemci); // site üzerindeki projeye linkine bağlan
  mqtt_istemci.onMessage(mesaj_geldi);			// mesaj gelince mesaj_geldi fonksiyonunu çagır
}
//*********************************************************************
void loop() 
{
  mqtt_istemci.loop();							// broker a veri gönderebilmek ve gelen veriyi okuyabilmek için
  if (!mqtt_istemci.connected()) 
    baglan();

  delay(1000);
}
//*********************************************************************
void baglan()
{
  // baglanana kadar bekle ekrana . yazdır
  while (!mqtt_istemci.connect("xxx", "yyy", "zzz")) // xxx=sizin client adınız, yyy=proje adı, zzz= token
  {
    Serial.print(".");
    delay(1000);
  }
  
  mqtt_istemci.subscribe("sensorler/sicaklik");		//sensorler/sicaklik konusuna abone ol
}
//*********************************************************************
void mesaj_geldi(String &konu, String &veri)		// gelen veriyi oku
{
  Serial.println(konu + ": "+ veri);
}
