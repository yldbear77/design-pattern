#ifndef __PIZZA_H__
#define __PIZZA_H__

#include "Pizza.h"
#include "PizzaIngredientFactory.h"
#include "Ingredient.h"

#include <iostream>
#include <string>
#include <vector>

class Pizza {
public:
	virtual void prepare() = 0;

	virtual void bake() {
		std::cout << "Bake for 25 minutes at 350\n";
	}

	virtual void cut() {
		std::cout << "Cutting the pizza into diagonal slices\n";
	}

	virtual void box() {
		std::cout << "Place pizza in official PizzaStore box\n";
	}

	void setName(std::string name) {
		mName = name;
	}

	std::string getName() {
		return mName;
	}

protected:
	std::string mName;

	Dough mDough;
	Sauce mSauce;
	std::vector<Veggies*> mVeggies;
	Cheese mCheese;
	Pepperoni mPepperoni;
	Clams mClam;
};

class CheesePizza : public Pizza {
public:
	CheesePizza(PizzaIngredientFactory* ingredientFactory) : 
		mIngredientFactory(ingredientFactory) {}

	void prepare() {
		std::cout << "Preparing " << mName << '\n';
		mDough = mIngredientFactory->createDough();
		mSauce = mIngredientFactory->createSauce();
		mCheese = mIngredientFactory->createCheese();
	}

private:
	PizzaIngredientFactory* mIngredientFactory;
};

class ClamPizza : public Pizza {
public:
	ClamPizza(PizzaIngredientFactory* ingredientFactory) :
		mIngredientFactory(ingredientFactory) {}

	void prepare() {
		std::cout << "Preparing " << mName << '\n';
		mDough = mIngredientFactory->createDough();
		mSauce = mIngredientFactory->createSauce();
		mCheese = mIngredientFactory->createCheese();
		mClam = mIngredientFactory->createClam();
	}

private:
	PizzaIngredientFactory* mIngredientFactory;
};

#endif