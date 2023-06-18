#include <LiquidCrystal.h>


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
 
  lcd.print(millis() / 1000);
}

