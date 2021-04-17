#include "DinerMenu.h"
#include "PancakeHouseMenu.h"
#include "Waitress.h"

int main(void) {
	PancakeHouseMenu* pancakeHouseMenu = new PancakeHouseMenu;
	DinerMenu* dinerMenu = new DinerMenu;

	Waitress* waitress = new Waitress(pancakeHouseMenu, dinerMenu);
	waitress->PrintMenu();

	return 0;
}