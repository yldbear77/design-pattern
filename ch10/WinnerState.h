#ifndef __WINER_STATE_H__
#define __WINER_STATE_H__

#include <iostream>

#include "State.h"
#include "GumballMachine.h"

class WinnerState : public State {
public:
	WinnerState(GumballMachine* gumballMachine) {
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
		if (gumballMachine->GetCount() == 0) {
			gumballMachine->SetState(gumballMachine->GetSoldOutState());
		}
		else {
			gumballMachine->ReleaseBall();
			std::cout << "YOU'RE A WINNER! You got two gumballs for your quarter\n";
			if (gumballMachine->GetCount() > 0) {
				gumballMachine->SetState(gumballMachine->GetNoQuarterState());
			}
			else {
				std::cout << "Oops, out of gumballs!\n";
				gumballMachine->SetState(gumballMachine->GetSoldOutState());
			}
		}
	}

private:
	GumballMachine* gumballMachine;
};

#endif