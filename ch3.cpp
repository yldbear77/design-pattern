#include <iostream>

using namespace std;

/* Beverage */

class Beverage {
public:
	virtual string getDescription() {
		return mDescription;
	}
	virtual double cost() = 0;

protected:
	string mDescription;
};

class Espresso : public Beverage {
public:
	Espresso() { mDescription = "Espresso"; }
	double cost() { return 1.99; }
};

class HouseBlend : public Beverage {
public:
	HouseBlend() { mDescription = "House Blend Coffee"; }
	double cost() { return .89; }
};

/* Condiment */

class CondimentDecorator : public Beverage {
public:
	virtual string getDescription() = 0;

protected:
	Beverage* mBeverage;
};

class Mocha : public CondimentDecorator {
public:
	Mocha(Beverage* beverage) { mBeverage = beverage; }
	string getDescription() { return mBeverage->getDescription() + ", Mocha"; }
	double cost() { return mBeverage->cost() + .20; }
};

int main(void) {
	Beverage* b1 = new Espresso;
	cout << b1->getDescription() << ": " << b1->cost() << '\n';

	Beverage* b2 = new HouseBlend;
	b2 = new Mocha(b2);
	cout << b2->getDescription() << ": " << b2->cost() << '\n';
}