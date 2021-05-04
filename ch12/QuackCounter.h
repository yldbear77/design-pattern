#ifndef __QUACK_COUNTER_H__
#define __QUACK_COUNTER_H__

#include "Quackable.h"

// decorator pattern
class QuackCounter : public Quackable {
public:
	QuackCounter(Quackable* duck) {
		this->duck = duck;
	}

	void quack() {
		duck->quack();
		++numberOfQuacks;
	}

	static int GetQuacks() {
		return numberOfQuacks;
	}

private:
	Quackable* duck;
	static int numberOfQuacks;
};

#endif