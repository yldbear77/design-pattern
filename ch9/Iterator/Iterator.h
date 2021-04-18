#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "MenuItem.h"

class Iterator {
public:
	virtual bool HasNext() = 0;
	virtual MenuItem next() = 0;
};

#endif