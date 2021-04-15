#ifndef __TEA_H__
#define __TEA_H__

#include <iostream>

#include "CaffeineBeverage.h"

class Tea : public CaffeineBeverage {
public:
	virtual void brew() {
		std::cout << "Steeping the tea\n";
	}

	virtual void AddCondiments() {
		std::cout << "Adding lemon\n";
	}
};

#endif