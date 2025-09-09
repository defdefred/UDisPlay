#include <WiFi.h>
#include <NetworkUdp.h>
#define DEBUG

NetworkUDP udp;

// Set local WiFi credentials
// const char *configSTASSID = "mySID";
// const char *configSTAPSK = "mySECRET";
const char *configSTASSID = "fred";
const char *configSTAPSK = "dIeX2tErJUCHBfGIZDUb2a2upWm9dpaw8ld3DOs4xSnIWymCogNsEDz5vpN9OyJ";
// Location for the udpscreen
const char *udpAddress = "192.168.3.233";
const int udpPort = 4444;
bool connected=false;
 
//#define MAX 
//char [MAX];

void setup()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  WiFi.setHostname("Bathroom");  
  WiFi.onEvent(WiFiEvent); 
  #ifdef DEBUG
  Serial.begin(115200);
  Serial.println("Waiting for Wifi...");
  #endif
  WiFi.begin(configSTASSID, configSTAPSK);
}

void loop()
{
	if (connected) {
		udp.beginPacket(udpAddress, udpPort);
		udp.printf("Seconds since boot: %lu", millis() / 1000);
		if( udp.endPacket() < 0 ) {
		#ifdef DEBUG
			Serial.println("UDP packet failed");
		} else {
			Serial.println("UDP packet OK");
  		#endif
		}
	}
	#ifdef DEBUG
	else {
		Serial.printf("not connected, ");
	}
	Serial.println("Waiting 1s...");
  	Serial.println(WiFi.localIP());
  	#endif
  delay(1000);
}

void WiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:
		#ifdef DEBUG
		Serial.print("Wifi MAC: ");
		Serial.println(WiFi.macAddress());
  		Serial.print("Wifi IP: ");
  		Serial.println(WiFi.localIP());
  		#endif
      udp.begin(WiFi.localIP(), udpPort);
      connected = true;
      break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
		#ifdef DEBUG
      Serial.println("WiFi lost connection");
  		#endif
      connected = false;
      break;
    default: break;
  }
}
