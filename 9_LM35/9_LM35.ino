// Sıcaklık sensörünü okuyup 25 dereceden büyükse LED yansın yoksa sönsün
int ADC_okunan=0;           // adc'den okunana ham değer
float sensor_gerilim=0.0;   // sensorden okunan degerin gerilim karsiligi mV cinsinden
float sicaklik=0.0;         // okunan sıcaklık değeri
//-------------------------------------------------
void setup() 
{
  Serial.begin(9600);     // seri portu 9600 baud rate de baslat

  pinMode(D0, OUTPUT);    // D0 pinini cikis olarak ayarla
  
  // deney setindeki silik yanan ledleri söndür
  pinMode(D1,OUTPUT);pinMode(D2,OUTPUT);pinMode(D3,OUTPUT);pinMode(D4,OUTPUT);
}
//-------------------------------------------------
void loop() 
{
  ADC_okunan=analogRead(A0);              // ADC yi oku, A0 girişine bağlı LM35
  sensor_gerilim=(ADC_okunan*1000.0)/1023.0; //bu kismin açıklaması en alttadır
  sicaklik=sensor_gerilim/10.0;
  
  Serial.print("Sicaklik:");    // seri port ekranına yazdırma
  Serial.println(sicaklik);     // seri port ekranına yazdırma
  
  if(sicaklik>25.0)             // sıcaklık 25'den büyük mü?
    digitalWrite(D0,HIGH);      // büyük LEDi yak
  else
    digitalWrite(D0,LOW);       // küçük LEDi söndür
}

//---------------------------------------------------
// Nodemcuda 10 bitlik ADC vardır ve Nodemcu ADC'si 0V ile 1V arasında deger
// olçebilmektedir. Yani 1V'a karşılık ADC'den 1023 sayısı üretilir. Örneğin;
// 200mV'luk gerilime karşılık üretilen deger söyledir: 
// 1000mV    1023
//  200mV     x=?
// x=(200*1023)/1000=204 sayısı okunur. Geriye dönük işlem yapılıp 200mV elde edilmeli.
// Çünkü LM35 her 1 derecelik sıcaklık için 10mV gerilim üretmektedir. Yani 23 derecelik 
// oda sıcaklığında üretilen gerilim 230mV'tur.
// (sensor_deger/1023)*1000 işlemi ile sensörden okunan değerin mV karşılığı bulunur.
// o değer de 10'a bölünerek sıcaklık degeri elde edilir.
