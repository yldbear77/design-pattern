#ifndef __CAFE_MENU_H__
#define __CAFE_MENU_H__

#include <map>
#include <string>

#include "Iterator.h"
#include "Menu.h"
#include "MenuItem.h"
#include "CafeMenuIterator.h"

class CafeMenu : public Menu {
public:
	std::map<std::string, MenuItem> menuItems;
	CafeMenu() {
		addItem("Veggie Burger and Air Fries",
			"Veggie burger on a whole wheat bun, lettuce, tomato, and fries",
			true, 3.99);
		addItem("Soup of the day",
			"A cup of the soup of the day, with a side salad",
			false, 3.69);
		addItem("Burrito",
			"A large burrito, with whole pinto beans, salsa, guacamole",
			true, 4.29);
	}

	void addItem(const std::string name,
		const std::string desc,
		bool vegetarian,
		double price)
	{
		MenuItem menuItem = MenuItem(name, desc, vegetarian, price);
		menuItems[name] = menuItem;
	}

	std::map<std::string, MenuItem> GetMenuItems() {
		return menuItems;
	}

	virtual Iterator* CreateIterator() {
		return new CafeMenuIterator(menuItems);
	}
};

#endif