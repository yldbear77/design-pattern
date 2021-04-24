#include <iostream>

#include "GumballMachine.h"

int main(void) {
	GumballMachine* gumballMachine = new GumballMachine(5);

	std::cout << gumballMachine;

	gumballMachine->InsertQuarter();
	gumballMachine->TurnCrank();

	std::cout << gumballMachine;

	gumballMachine->InsertQuarter();
	gumballMachine->TurnCrank();
	gumballMachine->InsertQuarter();
	gumballMachine->TurnCrank();

	std::cout << gumballMachine;

	return 0;
}