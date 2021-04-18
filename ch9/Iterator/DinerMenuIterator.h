#ifndef __DINER_MENU_ITERATOR_H__
#define __DINER_MENU_ITERATOR_H__

#include "Iterator.h"
#include "MenuItem.h"
#include "DinerMenu.h"

class DinerMenuIterator : public Iterator {
public:
	DinerMenuIterator(MenuItem* items) :
		position(0)
	{
		this->items = items;
	}

	virtual MenuItem next();
	virtual bool HasNext();

private:
	MenuItem* items;
	int position;
};

#endif