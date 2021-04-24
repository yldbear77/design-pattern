#ifndef __HAS_QUARTER_STATE_H__
#define __HAS_QUARTER_STATE_H__

#include <iostream>
#include <random>

#include "GumballMachine.h"
#include "State.h"

class HasQuarterState : public State {
public:
	HasQuarterState(GumballMachine* gumballMachine) {
		this->gumballMachine = gumballMachine;
	}

	void InsertQuarter() {
		std::cout << "You can't insert another quarter\n";
	}

	void EjectQuarter() {
		std::cout << "Quarter returned\n";
		gumballMachine->SetState(gumballMachine->GetNoQuarterState());
	}

	void TurnCrank() {
		std::cout << "You turned...\n";

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(0, 9);

		int winner = dist(mt);
		if ((winner == 0) && (gumballMachine->GetCount() > 1)) {
			gumballMachine->SetState(gumballMachine->GetWinnerState());
		}
		else {
			gumballMachine->SetState(gumballMachine->GetSoldState());
		}
	}

	void Dispense() {
		std::cout << "No gumball dispensed\n";
	}

private:
	GumballMachine* gumballMachine;
};

#endif