#ifndef __PIZZA_STORE_H__
#define __PIZZA_STORE_H__

#include "Pizza.h"

#include <string>

class PizzaStore {
public:
	Pizza* orderPizza(std::string type) {
		Pizza* pizza;

		pizza = createPizza(type);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}

	virtual Pizza* createPizza(std::string type) = 0;
};

class NYPizzaStore : public PizzaStore {
public:
	Pizza* createPizza(std::string type) {
		if (type == "cheese") return new NYStyleCheesePizza;
		else return nullptr;
	}
};

class ChicagoPizzaStore : public PizzaStore {
public:
	Pizza* createPizza(std::string type) {
		if (type == "cheese") return new ChicagoStyleCheesePizza;
		else return nullptr;
	}
};

#endif