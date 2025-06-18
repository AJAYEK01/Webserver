#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
#include <ESP8266HTTPClient.h>

#define DHTPIN D2
#define DHTTYPE DHT11

const char *ssid = "moto g64 5G";           // 🔒 Your WiFi SSID
const char *password = "12345678";          // 🔒 Your WiFi Password

unsigned long channelNumber = 2992753;      // ✅ Your ThingSpeak Channel ID
const char *writeAPIKey = "SHNLOY65HZRYYKPZ"; // ✅ Your ThingSpeak Write API Key

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

void setup()
{
  Serial.begin(9600);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
  ThingSpeak.begin(client);
}

void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(10000);
    return;
  }

  Serial.println("Temperature: " + String(temperature) + " °C");
  Serial.println("Humidity: " + String(humidity) + "%");

  // Set multiple fields
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);

  int result = ThingSpeak.writeFields(channelNumber, writeAPIKey);

  if (result == 200)
  {
    Serial.println("✅ Data successfully sent to ThingSpeak");
  }
  else
  {
    Serial.print("❌ Failed to send data. HTTP error code: ");
    Serial.println(result);
  }

  delay(20000); // Wait 20 seconds before sending next data
}
