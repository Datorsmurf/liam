// 
// 
// 

#include "wifimanager.h"
#include "definitions.h"
#include <ESP8266mDNS.h>

void WifiManager::setup() {
	const char* ssid = wifi_ssid;
	const char* password = wifi_pass;
	const char* networkname = wifi_networkname;

	WiFi.mode(WIFI_STA);
	WiFi.hostname(networkname);
	WiFi.begin(ssid, password);

	long t = millis();
	Serial.print("Connecting to ");
	Serial.println(ssid);

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
		if (t + 10000 < millis()) {
			break;
		}
	}

	if (WiFi.status() == WL_CONNECTED) {
		Serial.println("");
		Serial.println("WiFi connected");
	}
	else {
		Serial.println("");
		Serial.println("WiFi connect failed. Setting up AP");

		IPAddress    apIP(42, 42, 42, 42);  // Defining a static IP address: local & gateway
											// Default IP in AP mode is 192.168.4.1

		WiFi.mode(WIFI_AP_STA);
		WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));   // subnet FF FF FF 00

																	  /* You can remove the password parameter if you want the AP to be open. */
		WiFi.softAP("liamconn__use_42.42.42.42");

		IPAddress myIP = WiFi.softAPIP();
		Serial.print("AP IP address: ");
		Serial.println(myIP);
	}

	MDNS.begin(networkname);
}