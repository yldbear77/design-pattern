#ifndef __WAITRESS_H__
#define __WAITRESS_H__

#include <iostream>
#include <vector>

#include "PancakeHouseMenu.h"
#include "DinerMenu.h"
#include "CafeMenu.h"
#include "Iterator.h"

class Waitress {
public:
	Waitress(std::vector<Menu*> menus) {
		this->menus = menus;
	}

	void PrintMenu() {
		for (auto& m : menus) {
			Iterator* it = m->CreateIterator();
			PrintMenu(it);
		}
	}

private:
	std::vector<Menu*> menus;

	void PrintMenu(Iterator* it) {
		while (it->HasNext()) {
			MenuItem menuItem = it->next();
			std::cout << menuItem.GetName() << ", ";
			std::cout << menuItem.GetPrice() << " -- ";
			std::cout << menuItem.GetDescription() << '\n';
		}
		std::cout << '\n';
	}
};

#endif