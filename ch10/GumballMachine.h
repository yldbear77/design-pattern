#ifndef __GUMBALL_MACHINE_H__
#define __GUMBALL_MACHINE_H__

#include <iostream>

#include "State.h"

class SoldOutState;
class NoQuarterState;
class HasQuarterState;
class SoldState;
class WinnerState;

class GumballMachine {
public:
	GumballMachine(int count);
	void InsertQuarter();
	void EjectQuarter();
	void TurnCrank();
	void SetState(State* state);
	void ReleaseBall();

	int GetCount() { return count; }

	State* GetSoldOutState() { return soldOutState; }
	State* GetNoQuarterState() { return noQuarterState; }
	State* GetHasQuarterState() { return hasQuarterState; }
	State* GetSoldState() { return soldState; }
	State* GetWinnerState() { return winnerState; }

private:
	friend std::ostream& operator<<(std::ostream& os, const GumballMachine* gumballMachine);

	static const int SOLD_OUT = 0;
	static const int NO_QUARTER = 1;
	static const int HAS_QUARTER = 2;
	static const int SOLD = 3;

	State* soldOutState;
	State* noQuarterState;
	State* hasQuarterState;
	State* soldState;
	State* winnerState;

	State* state;

	int count;
};

#endif