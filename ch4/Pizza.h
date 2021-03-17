#ifndef __PIZZA_H__
#define __PIZZA_H__

#include <iostream>
#include <string>
#include <vector>

class Pizza {
public:
	virtual void prepare() {
		std::cout << "Preparing: " << name << '\n';
		std::cout << "Tossing dough ...\n";
		std::cout << "Adding sauce ...\n";
		std::cout << "Adding toppings: ";
		for (const auto& t : toppings) {
			std::cout << t << " ";
		}
		std::cout << '\n';
	}

	virtual void bake() {
		std::cout << "Bake for 25 minutes at 350\n";
	}

	virtual void cut() {
		std::cout << "Cutting the pizza into diagonal slices\n";
	}

	virtual void box() {
		std::cout << "Place pizza in official PizzaStore box\n";
	}

	std::string getName() {
		return name;
	}

protected:
	std::string name;
	std::string dough;
	std::string sauce;
	std::vector<std::string> toppings;
};

class NYStyleCheesePizza : public Pizza {
public:
	NYStyleCheesePizza() {
		name = "NY Style Sauce and Cheese Pizza";
		dough = "Thin Crust Dough";
		sauce = "Marinara Sauce";
		toppings.push_back("Grated Reggiano Cheese");
	}
};

class ChicagoStyleCheesePizza : public Pizza {
public:
	ChicagoStyleCheesePizza() {
		name = "Chicago Style Deep Dish Cheese Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Plum Tomato Sauce";
		toppings.push_back("Shredded Mozzarella Cheese");
	}

	virtual void cut() {
		std::cout << "Cutting the pizza into square slices\n";
	}
};

#endif