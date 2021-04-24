#include "GumballMachine.h"

#include "SoldOutState.h"
#include "NoQuarterState.h"
#include "HasQuarterState.h"
#include "SoldState.h"
#include "WinnerState.h"

GumballMachine::GumballMachine(int count) : count(count) {
	soldOutState = new SoldOutState(this);
	noQuarterState = new NoQuarterState(this);
	hasQuarterState = new HasQuarterState(this);
	soldState = new SoldState(this);
	winnerState = new WinnerState(this);
	if (count > 0) state = noQuarterState;
	else state = soldOutState;
}

void GumballMachine::InsertQuarter() { 
	state->InsertQuarter();
}

void GumballMachine::EjectQuarter() { 
	state->EjectQuarter();
}

void GumballMachine::TurnCrank() {
	state->TurnCrank();
	state->Dispense();
}

void GumballMachine::SetState(State* state) { 
	this->state = state;
}

void GumballMachine::ReleaseBall() {
	std::cout << "A gumball comes rolling out the slot ...\n";
	if (count > 0) --count;
}

std::ostream& operator<<(std::ostream& os, const GumballMachine* gumballMachine) {
	os << "\nMighty Gumball, Inc.";
	os << "\nC++-enabled Standing Gumball Model #2021";
	os << "\nInventory: " << gumballMachine->count << " gumball";
	if (gumballMachine->count >= 1) os << "s";
	os << '\n';

	os << "Machine is ";
	if (dynamic_cast<SoldOutState*>(gumballMachine->state)) {
		std::cout << "sold out\n\n";
	}
	else if (dynamic_cast<NoQuarterState*>(gumballMachine->state)) {
		std::cout << "waiting for a quarter\n\n";
	}
	else if (dynamic_cast<HasQuarterState*>(gumballMachine->state)) {
		std::cout << "waiting for turn of crank\n\n";
	}
	else if (dynamic_cast<SoldState*>(gumballMachine->state)) {
		std::cout << "delivering a gumball\n\n";
	}

	return os;
}