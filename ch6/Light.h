#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <iostream>

class Light {
public:
	void on() {
		std::cout << "Light is On\n";
	}

	void off() {
		std::cout << "Light is Off\n";
	}
};

#endif