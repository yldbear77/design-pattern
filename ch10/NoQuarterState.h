#ifndef __NO_QUARTER_STATE_H__
#define __NO_QUARTER_STATE_H__

#include <iostream>

#include "GumballMachine.h"
#include "State.h"

class NoQuarterState : public State {
public:
	NoQuarterState(GumballMachine* gumballMachine) {
		this->gumballMachine = gumballMachine;
	}

	void InsertQuarter() {
		std::cout << "You inserted a quarter\n";
		gumballMachine->SetState(gumballMachine->GetHasQuarterState());
	}

	void EjectQuarter() {
		std::cout << "You haven't inserted a quarter\n";
	}

	void TurnCrank() {
		std::cout << "You turned, but there's no quarter\n";
	}

	void Dispense() {
		std::cout << "You need to pay first\n";
	}

private:
	GumballMachine* gumballMachine;
};

#endif