#ifndef __PIZZA_INGREDIENT_FACTORY_H__
#define __PIZZA_INGREDIENT_FACTORY_H__

#include "Ingredient.h"

#include <vector>

class PizzaIngredientFactory {
public:
	virtual Dough createDough() = 0;
	virtual Sauce createSauce() = 0;
	virtual Cheese createCheese() = 0;
	virtual std::vector<Veggies*> createVeggies() = 0;
	virtual Pepperoni createPepperoni() = 0;
	virtual Clams createClam() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
	Dough createDough() { }
	Sauce createSauce() { }
	Cheese createCheese() { }
	Pepperoni createPepperoni() {}
	Clams createClam() {}
};

#endif