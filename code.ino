#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

float temperature;
float humidity;
DHT dht14(D4,DHT11);

void setup()
{
  temperature = 0;
  humidity = 0;
  Serial.begin(9600);
  dht14.begin();

  lcd.begin();
}

void loop()
{
  temperature = (dht14.readHumidity());
  humidity = (dht14.readTemperature());
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("  Humidty: ");
  Serial.print(humidity);

  lcd.setCursor(0, 0);
  char humidityString[10];
  sprintf(humidityString, "Hum: %.2f %%", humidity);
  lcd.print(humidityString);

  lcd.setCursor(0, 1);
  char temperatureString[10];
  sprintf(temperatureString, "Temp: %.2f C", temperature);
  lcd.print(temperatureString);

  delay(1000);
}