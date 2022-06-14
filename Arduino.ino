//initialize various components
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int sensorPin = 0;
int buzzerPin = 11;
int redLEDPin = 2;
int tempo = 180;
LiquidCrystal_I2C lcd(0x20,16,2);

void setup()
{
    lcd.init(); // initialize the lcd
    pinMode(buzzerPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);
}
void loop()
{
  lcd.backlight();
   
  int sensorPin=0;
   
  Serial.begin(9600);
  // Get the voltage reading from the TMP36
  int reading = analogRead(sensorPin);

  // Convert that reading into voltage
  float voltage = reading * (5.0 / 1024.0);
  // Convert the voltage into the temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;
 
  // now convert to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 
  lcd.setCursor(0,0);
  lcd.print(temperatureF);
  lcd.print(" F");
  lcd.setCursor(0,1);
  lcd.print(temperatureC);
  lcd.print(" C");
  delay(2000);
   //buzzer
    if (temperatureC < 25.0 || temperatureC > 30) {
        tone(buzzerPin, 500);
        digitalWrite(redLEDPin, HIGH);
        delay(100);
        noTone(buzzerPin);
        digitalWrite(redLEDPin, LOW);
        delay(100);
      } else {
        noTone(buzzerPin);
        digitalWrite(redLEDPin, LOW);
        delay(500);
      }
}
