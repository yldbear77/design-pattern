#ifndef __PIZZA_STORE_H__
#define __PIZZA_STORE_H__

#include "Pizza.h"
#include "PizzaIngredientFactory.h"

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
		Pizza* pizza = nullptr;
		PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory;

		if (type == "cheese") {
			pizza = new CheesePizza(ingredientFactory);
			pizza->setName("New York Style Cheese Pizza");
		}
		else if (type == "veggie") {
			//pizza = new VeggiePizza(ingredientFactory);
			pizza->setName("New York Style Veggie Pizza");
		}
		else if (type == "clam") {
			pizza = new ClamPizza(ingredientFactory);
			pizza->setName("New York Style Clam Pizza");
		}
		else if (type == "pepperoni") {
			//pizza = new PepperoniPizza(ingredientFactory);
			pizza->setName("New York Style Pepperoni Pizza");
		}

		return pizza;
	}
};

class ChicagoPizzaStore : public PizzaStore {
public:
	Pizza* createPizza(std::string type) {

	}
};

#endif