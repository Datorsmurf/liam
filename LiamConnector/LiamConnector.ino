#include "wifimanager.h"
#include "LiamState.h"
#include "webconnector.h"
#include <WiFiUdp.h>
#include <WiFiServer.h>
#include <WiFiClientSecure.h>
#include <WiFiClient.h>
#include <ESP8266WiFiType.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFi.h>

LiamState liamState;
WebConnector webconnector(&liamState);
WifiManager wifiManager;


void setup() {
	Serial.begin(115200);
	delay(100);
	wifiManager.setup();
	webconnector.setup(80);
}



// the loop function runs over and over again until power down or reset
void loop() {
	webconnector.handleLoop();
	if ((millis() / 1000) % 2 == 0) {
		liamState.Sensor0 = OutOfBounds;
	}
	else {
		liamState.Sensor0 = InsideBounds;
	}
	delay(100);
}
