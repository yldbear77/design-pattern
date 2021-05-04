#include <iostream>

#include "Quackable.h"
#include "Duck.h"
#include "Goose.h"
#include "GooseAdapter.h"
#include "QuackCounter.h"

int QuackCounter::numberOfQuacks = 0;

void simulate(Quackable* qa) {
	qa->quack();
}

int main(void) {
	Quackable* mallardDuck = new QuackCounter(new MallardDuck());
	Quackable* redheadDuck = new QuackCounter(new RedheadDuck());
	Quackable* duckCall = new QuackCounter(new DuckCall());
	Quackable* rubberDuck = new QuackCounter(new RubberDuck());
	Quackable* gooseDuck = new GooseAdapter(new Goose());

	std::cout << "Duck simulator\n";

	simulate(mallardDuck);
	simulate(redheadDuck);
	simulate(duckCall);
	simulate(rubberDuck);
	simulate(gooseDuck);

	std::cout << "The ducks quacked " << QuackCounter::GetQuacks() << " times\n";

	return 0;
}