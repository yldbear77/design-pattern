#ifndef __CAFFEINE_BEVERAGE_H__
#define __CAFFEINE_BEVERAGE_H__

#include <iostream>

class CaffeineBeverage {
public:
	virtual void PrepareRecipe() final {
		BoilWater();
		brew();
		PourInCup();
		AddCondiments();
	}
	virtual void brew() = 0;
	virtual void AddCondiments() = 0;
	virtual void BoilWater() {
		std::cout << "Boiling water\n";
	}
	virtual void PourInCup() {
		std::cout << "Pouring into cup\n";
	}
	virtual void hook() {}
};

#endif