//running on an Adafruit Trinket 3V
//IR receiver: TSOP38238
//SSR: VO14642AT
//Pulses relay when correct IR code is received.

#include "Adafruit_NECremote.h"

#define IR_PIN 2
#define RELAY_PIN 0

Adafruit_NECremote remote(IR_PIN);

//
void setup(void)
{
	//Serial.begin(115200);
	//Serial.println("Ready to decode IR!");
	pinMode(RELAY_PIN, OUTPUT);
}

//
void pulseRelay()
{
	//Serial.println("pulseRelay");
	digitalWrite(RELAY_PIN, HIGH);
	delay(1000);
	//delay(3000);
	digitalWrite(RELAY_PIN, LOW);
}

//
int lastcode = -1;
void loop(void)
{
	//Serial.println("waiting for code");
	int c = remote.listen();  // Without a #, it means wait forever
	//int c = remote.listen(5);  // seconds to wait before timing out!

	if (c >= 0)
	{
		//Serial.print("Received code #"); 
		//Serial.println(c, DEC);
		lastcode = c;

		if (c == 9)
			pulseRelay();
	}
	else if (c == -3)
	{
		//Serial.print("Repeat (");
		//Serial.print(lastcode);
		//Serial.println(")");
	}
	else if (c == -2)
	{
		//Serial.println("Data error");
	}
	else
	{
		//Serial.println("Timed out waiting!");
	}
}
