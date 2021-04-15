#ifndef __COFFEE_H__
#define __COFFEE_H__

#include <iostream>

#include "CaffeineBeverage.h"

class Coffee : public CaffeineBeverage {
public:
	virtual void brew() {
		std::cout << "Dripping coffee through filter\n";
	}

	virtual void AddCondiments() {
		std::cout << "Adding sugar and milk\n";
	}
};

#endif