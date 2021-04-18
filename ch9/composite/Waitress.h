#ifndef __WAITRESS_H__
#define __WAITRESS_H__

#include <iostream>
#include <vector>

#include "MenuComponent.h"

class Waitress {
public:
	Waitress(MenuComponent* allMenus) {
		this->allMenus = allMenus;
	}

	void PrintMenu() {
		allMenus->print();
	}

private:
	MenuComponent* allMenus;
};

#endif