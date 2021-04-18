#ifndef __PANCAKE_HOUSE_MENU_ITERATOR_H__
#define __PANCAKE_HOUSE_MENU_ITERATOR_H__

#include "Iterator.h"
#include "PancakeHouseMenu.h"

class PancakeHouseMenuIterator : public Iterator {
public:
	PancakeHouseMenuIterator(std::vector<MenuItem> items) :
		position(0)
	{
		this->items = items;
	}

	virtual MenuItem next() {
		MenuItem item = items[position];
		++position;
		return item;
	}

	virtual bool HasNext() {
		if (position >= items.size()) return false;
		return true;
	}

private:
	std::vector<MenuItem> items;
	int position;
};

#endif