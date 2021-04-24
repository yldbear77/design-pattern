#ifndef __SOLD_STATE_H__
#define __SOLD_STATE_H__

#include <iostream>

#include "GumballMachine.h"
#include "State.h"

class SoldState : public State {
public:
	SoldState(GumballMachine* gumballMachine) {
		this->gumballMachine = gumballMachine;
	}

	void InsertQuarter() {
		std::cout << "Please wait, we're already giving you a gumball\n";
	}

	void EjectQuarter() {
		std::cout << "Sorry, you already turned the crank\n";
	}

	void TurnCrank() {
		std::cout << "Turning twice doesn't get you another gumball!\n";
	}

	void Dispense() {
		gumballMachine->ReleaseBall();
		if (gumballMachine->GetCount() > 0) {
			gumballMachine->SetState(gumballMachine->GetNoQuarterState());
		}
		else {
			std::cout << "Oops, out of gumballs!\n";
			gumballMachine->SetState(gumballMachine->GetSoldOutState());
		}
	}

private:
	GumballMachine* gumballMachine;
};

#endif