#include "DHT.h"

#define DHTPIN 2     // Pin para temperatura humedad
#define DHTTYPE DHT11   // Tipo de sensor temperatura-humedad

DHT dht(DHTPIN, DHTTYPE); //Inicializando DHT
int sensorValue;

void setup() {
  Serial.begin(9600);
  Serial.println("Temperatura - Humedad");
  dht.begin();
}


void loop(){
  medirTempHum();
  /*sensorValue = analogRead(0);       // read analog input pin 0
  Serial.print("AirQua=");
  Serial.print(sensorValue, DEC);  // prints the value read
  Serial.println(" PPM");
  lcd.setCursor(0,0);
  lcd.print("ArQ=");
  lcd.print(sensorValue,DEC);
  lcd.print(" PPM");
  lcd.println("       "); 
  lcd.print("  ");
  delay(2000); */                       // wait 100ms for next reading
}

void medirTempHum(){
  delay(5000);
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  
}

