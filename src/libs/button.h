#include "Arduino.h"

class Button {
private:
	const unsigned byte pin;

public:
	Button(byte _p) : pin(_p) {}

	void init() {
		pinMode(pin, INPUT);
	}

	bool get() {
		return digitalRead(pin);
	}
}
