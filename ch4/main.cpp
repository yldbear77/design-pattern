#include "Pizza.h"
#include "PizzaStore.h"

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	PizzaStore* nyStore = new NYPizzaStore;
	PizzaStore* ccStore = new ChicagoPizzaStore;

	Pizza *pizza = nyStore->orderPizza("cheese");
	cout << "Ethan ordered a " << pizza->getName() << "\n\n";

	pizza = ccStore->orderPizza("cheese");
	cout << "Joel ordered a " << pizza->getName() << '\n';

	return 0;
}