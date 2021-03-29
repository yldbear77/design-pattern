#ifndef __GARAGE_DOOR_H__
#define __GARAGE_DOOR_H__

#include <iostream>

class GarageDoor {
public:
	GarageDoor(std::string name) : mName(name) {}

	void open() { 
		std::cout << mName << " garage door is open\n";
	}

	void close() {
		std::cout << mName << " garage door is closed\n";
	}

private:
	std::string mName;
};

#endif