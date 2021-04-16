#ifndef __DINER_MENU_H__
#define __DINER_MENU_H__

#include <iostream>
#include <array>
#include <string>

#include "Iterator.h"
#include "MenuItem.h"
#include "DinerMenuIterator.h"

class DinerMenu {
public:
	static const int MAX_ITEMS = 6;
	//enum { MAX_ITEMS = 6 };

	DinerMenu() : numberOfItems(0) {
		menuItems = new MenuItem[MAX_ITEMS];

		addItem("Vegetarian BLT",
			"(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
		addItem("BLT",
			"Bacon with lettuce & tomato on whole wheat", false, 2.99);
		addItem("Soup of the day",
			"Soup of the day, with a side of potato salad", false, 3.29);
		addItem("Hotdog",
			"A hot dog, with sauerkraut, relish, onions, topped with cheese",
			false, 3.05);
	}

	void addItem(std::string name, std::string desc,
		bool vegetarian, double price)
	{
		MenuItem menuItem = MenuItem(name, desc, vegetarian, price);
		if (numberOfItems >= MAX_ITEMS) {
			std::cout << "Sorry, menu is full! Can't add item to menu\n";
		}
		else {
			menuItems[numberOfItems] = menuItem;
			++numberOfItems;
		}
	}

	//MenuItem* GetMenuItems() { return menuItems; }
	Iterator* CreateIterator();

private:
	int numberOfItems;
	MenuItem* menuItems;
};

#endif