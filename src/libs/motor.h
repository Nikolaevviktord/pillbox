class Motor {
private:
	const byte _pin;

public:
	Motor(byte _p) : _pin(_p) {}

	void init() { pinMode(_pin, OUTPUT); }

	void go() { digitalWrite(_pin, 1); }

	void stop() { digitalWrite(_pin, 0); }
};
