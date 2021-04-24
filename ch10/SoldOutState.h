#ifndef __SOLD_OUT_STATE_H__
#define __SOLD_OUT_STATE_H__

#include <iostream>

#include "State.h"
#include "GumballMachine.h"

class SoldOutState : public State {
public:
	SoldOutState(GumballMachine* gumballMachine) {
		this->gumballMachine = gumballMachine;
	}

	void InsertQuarter() {
		std::cout << "You can't insert a quarter, the machine is sold out\n";
	}

	void EjectQuarter() {
		std::cout << "You can't eject, you haven't inserted a quarter yet\n";
	}

	void TurnCrank() {
		std::cout << "You turned, but there are no gumballs\n";
	}

	void Dispense() {
		std::cout << "No gumball dispensed\n";
	}

private:
	GumballMachine* gumballMachine;
};

#endif