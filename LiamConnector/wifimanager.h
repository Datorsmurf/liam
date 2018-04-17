// wifimanager.h

#ifndef _WIFIMANAGER_h
#define _WIFIMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class WifiManager {
public:
	void setup();
};

#endif

