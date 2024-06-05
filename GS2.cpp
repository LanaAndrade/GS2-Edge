#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"

const char* ssid = "Wokwi-GUEST"; // wifi ssid
const char* password = "";
const char* mqtt_server = "mqtt-dashboard.com"; // MQTT server
WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char valorFotorresistorString[10];
#define LDR_PIN 34 // define o pino de leitura do fotoresistor
const int DHT_PIN = 15;
DHTesp dhtSensor;
int PIR_SENSOR_PIN = 4;
int PIR_SENSOR_STATUS = 0;
char valorSensorMovimento[10];
char valorSensor[10];
String empresa = "empresa";
float leituraOxi = 0;

int sensorOxi = 33; // Pino analógico ao qual o sensor está conectado

float leituraPh = 0;

int sensorPh = 32; // Pino analógico ao qual o sensor está conectado

float leituraTurbidez = 0;

int sensorTurbidez = 35; // Pino analógico ao qual o sensor está conectado

void setup_wifi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(PIR_SENSOR_PIN, INPUT);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  if ((char)payload[0] == '1') {
    digitalWrite(2, LOW); // Turn the LED on
  } else {
    digitalWrite(2, HIGH); // Turn the LED off
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      client.publish("iotfrontier/mqtt", "iotfrontier");
      client.subscribe("iotfrontier/mqtt");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  setup_wifi();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  delay(2000); // Delay to allow sensor to stabilize

  pinMode(15, OUTPUT);
  

  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);

  pinMode(12, OUTPUT);

  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH); // Acende o LED
  delay(2000);            // Aguarda 2 segundos
  digitalWrite(12, LOW);  // Apaga o LED
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();

    digitalWrite(12, HIGH);

  if (now - lastMsg > 2000) { 
    lastMsg = now;

    TempAndHumidity data = dhtSensor.getTempAndHumidity();
    float temperatureValue = data.temperature;

    char tempStr[8];
    dtostrf(temperatureValue, 1, 2, tempStr);

    String topicoTemp = "OceanBlue/" + empresa + "/temperature";
    const char* topicoTemp_cstr = topicoTemp.c_str();
    client.publish(topicoTemp_cstr, tempStr);

    int valorFotorresistor = analogRead(LDR_PIN);
    String topicoLDR = "OceanBlue/" + empresa + "/luminosidade";
    const char* topicoLDR_cstr = topicoLDR.c_str();
    sprintf(valorFotorresistorString, "%d", valorFotorresistor);
    client.publish(topicoLDR_cstr, valorFotorresistorString);

    PIR_SENSOR_STATUS = digitalRead(PIR_SENSOR_PIN);
    sprintf(valorSensorMovimento, "%d", PIR_SENSOR_STATUS);
    String topicoMov = "OceanBlue/" + empresa + "/movimento";
    const char* topicoMov_cstr = topicoMov.c_str();
    client.publish(topicoMov_cstr, valorSensorMovimento);
    
    leituraOxi = analogRead(sensorOxi) * 20.0 / 1023.0;
    sprintf(valorSensor, "%f", leituraOxi);
    client.publish("OceanBlue/empresa/oxigenio", valorSensor);

    leituraPh = analogRead(sensorPh) * 14.0 / 4095.0;
    sprintf(valorSensor, "%f", leituraPh);
    client.publish("OceanBlue/empresa/ph", valorSensor);

    leituraTurbidez = -1120.4 * pow((analogRead(sensorTurbidez) * (3.3 / 4095.0)), 2) + 5742.3 * (analogRead(sensorTurbidez) * (3.3 / 4095.0)) - 4352.9;
    sprintf(valorSensor, "%f", leituraTurbidez);
    client.publish("OceanBlue/empresa/turbidez", valorSensor);
  }

}
