#define BLYNK_PRINT Serial
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
WidgetLED l(V1);
char auth[] = "9f1accc018f94d14a3fefb797e02ab98";

char ssid[] = "note4";
char pass[] = "123456788";

void setup()
{
  Serial.begin(9600);
  pinMode(D4,INPUT);
  Blynk.begin(auth, ssid, pass);
  lcd.begin(16,2);


}

void loop()
{
  int a;
  Blynk.run();

  
  a=digitalRead(D4);
  Serial.println(a);
 if(a==LOW)
  {
    Serial.print("Fire");
    Blynk.virtualWrite(V0,"FIREEE in the house");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("fire");
    l.on();
  }
  else if(a==HIGH)
{
  Serial.print("Chill");
  Blynk.virtualWrite(V0,"Chhiled house");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CHILL");
  l.off();
}
}
