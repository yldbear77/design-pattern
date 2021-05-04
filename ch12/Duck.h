#ifndef __DUCK_H__
#define __DUCK_H__

#include <iostream>

#include "Quackable.h"

class MallardDuck : public Quackable {
public:
	void quack() {
		std::cout << "Quack\n";
	}
};

class RedheadDuck : public Quackable {
public:
	void quack() {
		std::cout << "Quack\n";
	}
};

class DuckCall : public Quackable {
public:
	void quack() {
		std::cout << "Kwak\n";
	}
};

class RubberDuck : public Quackable {
public:
	void quack() {
		std::cout << "Squeak\n";
	}
};

#endif