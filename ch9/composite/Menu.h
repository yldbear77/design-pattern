#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <string>
#include <list>

#include "MenuComponent.h"

class Menu : public MenuComponent {
public:
	Menu() {}

	Menu(std::string name, std::string desc) {
		this->name = name;
		this->desc = desc;
	}

	virtual void add(MenuComponent* menuComponent) {
		menuComponents.push_back(menuComponent);
	}

	virtual void remove(MenuComponent* menuComponent) {
		std::list<MenuComponent*>::iterator it;
		for (it = menuComponents.begin(); it != menuComponents.end(); ++it) {
			if (*it == menuComponent) {
				menuComponents.erase(it);
				break;
			}
		}
	}

	virtual MenuComponent* getChild(int i) {
		std::list<MenuComponent*>::iterator it = menuComponents.begin();
		for (int j = 0; j < i; ++i) ++it;
		return *it;
	}

	virtual std::string GetName() { return name; }
	virtual std::string GetDescription() { return desc; }
	
	virtual void print() {
		std::cout << "\n" << GetName();
		std::cout << ", " << GetDescription() << '\n';
		std::cout << "---------------------\n";
		for (auto& m : menuComponents) m->print();
	}

private:
	std::list<MenuComponent*> menuComponents;
	std::string name;
	std::string desc;
};

#endif