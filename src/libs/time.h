#pragma once

struct time_struct {
        byte _hour;
        byte _minute;
	byte _adress;

        time() {}

        time(byte _h, byte _m) : _hour(_h), _minute(_m) {}

	void save_to_eeprom(byte _a) {
		_adress = _a;
		EEPROM.write(_adress * 2 - 1, _hour);
		EEPROM.write(_adress * 2, _minute);
	}

	time_struct read_from_eeprom() {
		byte _h = EEPROM.read(_adress * 2 - 1);
		byte _m = EEPROM.read(_adress * 2);
		return time_struct(_h, _m);
	}

        time operator - (int _m) {
                int _h_new = _hour - (_m / 60);
                int _m_new = _minute - (_m % 60);

                return time(_h_new, _m_new);
        }

        int operator - (time _t) {
                return abs(_t._hour - _hour) * 60 + abs(_t._minute - _minute);
        }

        void set_hour(int _h) { _hour = _h; }

        void set_minute(int _m) { _minute = _m; }

        void set_time(int _h, int _m) {
                set_hour(_h);
                set_minute(_m);
        }
};

time_struct read_time_from_eeprom() {
        byte _h = EEPROM.read(_adress * 2 - 1);
        byte _m = EEPROM.read(_adress * 2);
        return time_struct(_h, _m);
}
