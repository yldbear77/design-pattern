#ifndef __WAITRESS_H__
#define __WAITRESS_H__

#include <iostream>

#include "PancakeHouseMenu.h"
#include "DinerMenu.h"
#include "Iterator.h"

class Waitress {
public:
	Waitress(PancakeHouseMenu* pancakeHouseMenu, DinerMenu* dinerMenu) {
		this->pancakeHouseMenu = pancakeHouseMenu;
		this->dinerMenu = dinerMenu;
	}

	void PrintMenu() {
		Iterator* pancakeIterator = pancakeHouseMenu->CreateIterator();
		Iterator* dinerIterator = dinerMenu->CreateIterator();

		std::cout << "MENU\n----\nBREAKFAST\n";
		PrintMenu(pancakeIterator);
		std::cout << "\nLUNCH\n";
		PrintMenu(dinerIterator);
	}

private:
	PancakeHouseMenu* pancakeHouseMenu;
	DinerMenu* dinerMenu;

	void PrintMenu(Iterator* it) {
		while (it->HasNext()) {
			MenuItem menuItem = it->next();
			std::cout << menuItem.GetName() << ", ";
			std::cout << menuItem.GetPrice() << " -- ";
			std::cout << menuItem.GetDescription() << '\n';
		}
	}
};

#endif