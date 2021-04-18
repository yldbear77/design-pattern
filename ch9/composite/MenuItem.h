#ifndef __MENU_ITEM_H__
#define __MENU_ITEM_H__

#include <iostream>
#include <string>

#include "MenuComponent.h"

class MenuItem : public MenuComponent {
public:
	MenuItem() {}
	MenuItem(std::string name,
		std::string desc,
		bool vegetarian,
		double price)
	{
		this->name = name;
		this->desc = desc;
		this->vegetarian = vegetarian;
		this->price = price;
	}

	std::string GetName() { return name; }
	std::string GetDescription() { return desc; }
	bool IsVegetarian() { return vegetarian; }
	double GetPrice() { return price; }

	void print() override {
		std::cout << " " << GetName();
		if (IsVegetarian()) std::cout << "(v)";
		std::cout << ", " << GetPrice() << '\n';
		std::cout << "    -- " << GetDescription() << '\n';
	}

private:
	std::string name;
	std::string desc;
	bool vegetarian;
	double price;
};

#endif