#ifndef __MENU_ITEM_H__
#define __MENU_ITEM_H__

#include <string>

class MenuItem {
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

private:
	std::string name;
	std::string desc;
	bool vegetarian;
	double price;
};

#endif