#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

#define dht_dpin 12
#define led_pin 13
#define DHTTYPE DHT11

DHT dht(dht_dpin, DHTTYPE);


char* ssid = ""; //Enter your Wi-Fi Name
char* password = "";  //Enter your Wi-Fi password

unsigned long myChannelNumber = ; //Enter your Thingspeak channel id
const char * myWriteAPIKey = "";

WiFiClient client;

float temp;

void setup() {
 pinMode(led_pin,OUTPUT);
 Serial.begin(9600);
 dht.begin();
 Serial.print("Conectando a la red ");
 Serial.println(ssid);
 WiFi.begin(ssid,password);// Pass the credential for local wifi network to connect ESP8266 board
    while (WiFi.status()!= WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");

    delay(500);
    ThingSpeak.begin(client);
}

void loop() {

  temp = dht.readTemperature();
  Serial.print("Temperatura = ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.println("\n...Subiendo a Thingspeak............./n");
  ThingSpeak.setField(1, temp);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
   digitalWrite(led_pin,0);
  for(int i = 0; i < 600; i++)
  {
    digitalWrite(led_pin,!digitalRead(led_pin));
    delay(1000);
    Serial.println(i);
  }
 
}

