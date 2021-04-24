#ifndef __STATE_H__
#define __STATE_H__

class State {
public:
	virtual void InsertQuarter() = 0;
	virtual void EjectQuarter() = 0;
	virtual void TurnCrank() = 0;
	virtual void Dispense() = 0;
};

#endif