// deneme kartı üzerindeki RGB ledi yakma
int kirmizi = D7;       
int yesil = D8;
int mavi = D6;
//****************************************
void setup()
{
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(mavi, OUTPUT);
}
//****************************************
void loop()
{
  for (int i = 0; i < 1023; i++)
  {
    for (int j = 0; j < 1023; j++)
    {
      for (int k = 0; k < 1023; k++)
      {
        analogWrite(yesil, i);        // PWM sinyal gönderme
        analogWrite(mavi, k);         // PWM sinyal gönderme
        analogWrite(kirmizi, j);      // PWM sinyal gönderme
        delay(2);
      }
    }
  }
}
