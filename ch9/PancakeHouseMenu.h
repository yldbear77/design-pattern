#ifndef __PANCAKE_HOUSE_MENU_H__
#define __PANCAKE_HOUSE_MENU_H__

#include <vector>
#include <string>

#include "Menu.h"
#include "Iterator.h"
#include "MenuItem.h"
#include "PancakeHouseMenuIterator.h"

class PancakeHouseMenu : public Menu {
public:
	PancakeHouseMenu() {
		addItem("K&B's Pancake Breakfast",
			"Pancakes with scrambled eggs and toast",
			true,
			2.99);
		addItem("Regular Pancake Breakfast",
			"Pancakes with fried eggs, sausage",
			false,
			2.99);
		addItem("Blueberry Pancakes",
			"Pancakes made with fresh blueberries",
			true,
			3.49);
		addItem("Waffles",
			"Waffles with your choice of blueberries or strawberries",
			true,
			3.59);
	}

	void addItem(std::string name, std::string description,
		bool vegetarian, double price)
	{
		MenuItem menuItem = MenuItem(name, description, vegetarian, price);
		menuItems.push_back(menuItem);
	}

	//std::vector<MenuItem> GetMenuItems() { return menuItems; }
	Iterator* CreateIterator() { return new PancakeHouseMenuIterator(menuItems); }

private:
	std::vector<MenuItem> menuItems;
};

#endif