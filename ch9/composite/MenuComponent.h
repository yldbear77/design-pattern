#ifndef __MENU_COMPONENT_H__
#define __MENU_COMPONENT_H__

#include <string>
#include <stdexcept>

class MenuComponent {
public:
	virtual void add(MenuComponent* menuComponent) {
		throw std::runtime_error("add() is unsupported");
	}

	virtual void remove(MenuComponent* menuComponent) {
		throw std::runtime_error("remove() is unsupported");
	}

	virtual MenuComponent* GetChild(int i) {
		throw std::runtime_error("GetChild() is unsupported");
	}

	virtual std::string GetName() {
		throw std::runtime_error("GetName() is unsupported");
	}

	virtual std::string GetDescription() {
		throw std::runtime_error("GetDescription() is unsupported");
	}

	virtual double GetPrice() {
		throw std::runtime_error("GetPrice() is unsupported");
	}

	virtual bool isVegetarian() {
		throw std::runtime_error("isVegetarian() is unsupported");
	}

	virtual void print() {
		throw std::runtime_error("print() is unsupported");
	}
};

#endif