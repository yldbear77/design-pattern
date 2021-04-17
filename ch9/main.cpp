#include "DinerMenu.h"
#include "PancakeHouseMenu.h"
#include "CafeMenu.h"
#include "Waitress.h"

int main(void) {
	PancakeHouseMenu* pancakeHouseMenu = new PancakeHouseMenu;
	DinerMenu* dinerMenu = new DinerMenu;
	CafeMenu* cafeMenu = new CafeMenu;

	Waitress* waitress = new Waitress({ pancakeHouseMenu, dinerMenu, cafeMenu });
	waitress->PrintMenu();

	return 0;
}