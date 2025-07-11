#include <DHT.h>

#define DHTPIN 2          
#define DHTTYPE DHT11      
#define GAS_SENSOR A0      
#define PIR_SENSOR 9      

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(GAS_SENSOR, INPUT);
  pinMode(PIR_SENSOR, INPUT);
}

void loop() {
  
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  int gasValue = analogRead(GAS_SENSOR);
  
  int pirState = digitalRead(PIR_SENSOR);
  
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);
  Serial.print("PIR State: ");
  Serial.println(pirState);
  
  delay(1000);
}
