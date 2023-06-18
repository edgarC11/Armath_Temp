#include <LiquidCrystal.h>
int tempPin = 0;
int coldPin = 22;
int greenPin = 24;
int yellowPin = 26;
int redPin = 28;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup()
{
  pinMode(coldPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  lcd.begin(16, 2);
}
void loop()
{
  digitalWrite(coldPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);
  int tempReading = analogRead(tempPin);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float temp = tempK - 273.15;            // Convert Kelvin to Celcius


  lcd.setCursor(0, 0);
  lcd.print("Temp        C  ");

  lcd.setCursor(6, 0);

  lcd.print(temp);



  if(temp < 24)
  {
    digitalWrite(coldPin, HIGH);
    delay(300);
    digitalWrite(coldPin, LOW);
    delay(300);
  }
  
    if(temp >= 24 && temp <= 24.25)
  {
    digitalWrite(greenPin, HIGH);
    delay(300);
    digitalWrite(greenPin, LOW);
    delay(300);
  }

    if(temp > 24.25 && temp < 24.50)
  {
    digitalWrite(yellowPin, HIGH);
    delay(300);
    digitalWrite(yellowPin, LOW);
    delay(300);
  }

    if(temp >= 24.50)
  {
    digitalWrite(redPin, HIGH);
    delay(300);
    digitalWrite(redPin, LOW);
    delay(300);
  }
  delay(500);
}
