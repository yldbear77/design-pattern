#include "DinerMenu.h"

Iterator* DinerMenu::CreateIterator() { 
	return new DinerMenuIterator(menuItems);
}