#ifndef __MENU_H__
#define __MENU_H__

#include "Iterator.h"

class Menu {
public:
	virtual Iterator* CreateIterator() = 0;
};

#endif