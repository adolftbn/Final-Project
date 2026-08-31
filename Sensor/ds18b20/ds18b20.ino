#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);

  Serial.println("Testing DS18B20...");

  sensors.begin();

  Serial.print("Jumlah sensor terdeteksi: ");
  Serial.println(sensors.getDeviceCount());
}

void loop() {
  sensors.requestTemperatures();

  float temperatureC = sensors.getTempCByIndex(0);

  if (temperatureC == DEVICE_DISCONNECTED_C) {
    Serial.println("DS18B20 tidak terdeteksi!");
  } else {
    Serial.print("Suhu: ");
    Serial.print(temperatureC);
    Serial.println(" °C");
  }

  delay(1000);
}