#include <Hx711.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DOUT_PIN 2
#define SCK_PIN 3

Hx711 scale(DOUT_PIN, SCK_PIN);
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() 
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}

void loop() 
{
  int mass = scale.getGram();
  double price = 0.05*(int)mass;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mass=");
  lcd.setCursor(5,0);
  lcd.print(mass);
  lcd.setCursor(0,1);
  lcd.print("Price=$");
  lcd.setCursor(7,1);
  lcd.print(price);
  delay(50);
}
