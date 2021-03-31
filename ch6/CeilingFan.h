#ifndef __CEILING_FAN_H__
#define __CEILING_FAN_H__

#include <iostream>

class CeilingFan {
public:
	static const int HIGH = 3;
	static const int MEDIUM = 2;
	static const int LOW = 1;
	static const int OFF = 0;

	CeilingFan(std::string location) {
		mLocation = location;
		mSpeed = OFF;
	}

	void high() { 
		mSpeed = HIGH;
		std::cout << mLocation << " ceiling fan is high\n";
	}

	void medium() { 
		mSpeed = MEDIUM;
		std::cout << mLocation << " ceiling fan is medium\n";
	}

	void low() { 
		mSpeed = LOW;
		std::cout << mLocation << " ceiling fan is low\n";
	}

	void off() { 
		mSpeed = OFF;
		std::cout << mLocation << " ceiling fan is off\n";
	}

	int getSpeed() { 
		return mSpeed; 
	}

private:
	std::string mLocation;
	int mSpeed;
};

#endif