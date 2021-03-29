#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <iostream>

class Light {
public:
	Light(std::string name) : mName(name) {}

	void on() {
		std::cout << mName << " light is on\n";
	}

	void off() {
		std::cout << mName << " light is off\n";
	}

private:
	std::string mName;
};

#endif