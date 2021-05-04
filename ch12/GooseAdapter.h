#ifndef __GOOSE_ADAPTER_H__
#define __GOOSE_ADAPTER_H__

#include "Quackable.h"
#include "Goose.h"

// adapter pattern
class GooseAdapter : public Quackable {
public:
	GooseAdapter(Goose* goose) {
		this->goose = goose;
	}

	void quack() {
		goose->honk();
	}

private:
	Goose* goose;
};

#endif