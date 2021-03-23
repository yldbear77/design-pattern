#ifndef __SINGLETON_H__
#define __SINGLETON_H__

class ChocolateBoiler {
public:
	static ChocolateBoiler* getInstance() {
		if (mInstance == nullptr) {
			mInstance = new ChocolateBoiler();
		}
		return mInstance;
	}

	void fill() {
		if (isEmpty()) {
			empty = false;
			boiled = false;
		}
	}

	void drain() {
		if (!isEmpty() && isBoiled()) {
			empty = true;
		}
	}

	void boil() {
		if (!isEmpty() && !isBoiled()) {
			boiled = true;
		}
	}

	bool isEmpty() { return empty; }
	bool isBoiled() { return boiled; }

private:
	static ChocolateBoiler *mInstance;

	bool empty;
	bool boiled;

	ChocolateBoiler() {
		empty = true;
		boiled = false;
	}
};

#endif