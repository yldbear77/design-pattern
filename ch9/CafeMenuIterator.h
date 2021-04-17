#ifndef __CAFE_MENU_ITERATOR_H__
#define __CAFE_MENU_ITERATOR_H__

#include <map>
#include <string>

#include "Iterator.h"

class CafeMenuIterator : public Iterator {
public:
	CafeMenuIterator(std::map<std::string, MenuItem> items) {
		this->items = items;
		it = this->items.begin();
	}

	virtual MenuItem next() {
		MenuItem item = it->second;
		++it;
		return item;
	}

	virtual bool HasNext() {
		if (it == items.end()) return false;
		return true;
	}

private:
	std::map<std::string, MenuItem> items;
	std::map<std::string, MenuItem>::iterator it;
};

#endif