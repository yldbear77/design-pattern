#ifndef __GARAGE_DOOR_H__
#define __GARAGE_DOOR_H__

#include <iostream>

class GarageDoor {
public:
	void open() { 
		std::cout << "Garage door is Open\n";
	}

	void close() {
		std::cout << "Garage door is Closed\n";
	}
};

#endif