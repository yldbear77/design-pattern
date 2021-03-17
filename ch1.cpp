#include <iostream>

using namespace std;

/* FlyBehavior */

class FlyBehavior {
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
	void fly() {
		cout << "I'm flying !\n";
	}
};

class FlyNoWay : public FlyBehavior {
	void fly() {
		cout << "I can't fly.\n";
	}
};

class FlyRocketPowered : public FlyBehavior {
	void fly() {
		cout << "I'm flying with a rocket !\n";
	}
};

/* QuackBehavior */

class QuackBehavior {
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior {
	void quack() {
		cout << "Quack\n";
	}
};

class MuteQuack : public QuackBehavior {
	void quack() {
		cout << "<< Silence >>\n";
	}
};

class Squeak : public QuackBehavior {
	void quack() {
		cout << "Squeak\n";
	}
};

class Duck {
public:
	FlyBehavior *flyBehavior;
	QuackBehavior *quackBehavior;

	virtual void display() = 0;

	void performFly() { flyBehavior->fly(); }
	void performQuack() { quackBehavior->quack(); }

	void swim() { cout << "All ducks float, even decoys !\n"; }

	void setFlyBehavior(FlyBehavior *fb) { flyBehavior = fb; }
	void setQuackBehavior(QuackBehavior* qb) { quackBehavior = qb; }
};

class MallardDuck : public Duck {
public:
	MallardDuck() {
		flyBehavior = new FlyWithWings();
		quackBehavior = new Quack();
	}

	void display() {
		cout << "I'm a real Mallard duck\n";
	}
};

class ModelDuck : public Duck {
public:
	ModelDuck() {
		flyBehavior = new FlyNoWay();
		quackBehavior = new Quack();
	}

	void display() {
		cout << "I'm a model duck\n";
	}
};

int main(void) {
	Duck *mallard = new MallardDuck();
	mallard->performFly();
	mallard->performQuack();

	Duck* model = new ModelDuck();
	model->performFly();
	model->setFlyBehavior(new FlyRocketPowered());
	model->performFly();
}