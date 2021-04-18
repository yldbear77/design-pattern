#include "DinerMenuIterator.h"

MenuItem DinerMenuIterator::next() {
	MenuItem item = items[position];
	++position;
	return item;
}

bool DinerMenuIterator::HasNext() {
	if (position >= DinerMenu::MAX_ITEMS || items[position].GetName() == "") return false;
	return true;
}