#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>

using namespace std;

/* interface */

class Observer {
public:
	//virtual void update(float temp, float humidity, float pressure) = 0;
	virtual void update() = 0;
};

class Subject {
public:
	virtual void registerObserver(Observer *o) = 0;
	virtual void removeObserver(Observer *o) = 0;
	virtual void notifyObservers() = 0;
};

class DisplayElement {
	virtual void display() = 0;
};

/* implementation */

class WeatherData : public Subject {
public:
	WeatherData() { }

	void registerObserver(Observer *o) {
		observers.insert(o);
	}

	void removeObserver(Observer *o) {
		observers.erase(o);
	}

	void notifyObservers() {
		for (auto a : observers) {
			//a->update(mTemperature, mHumidity, mPressure);
			a->update();
		}
	}

	void measurementsChanged() {
		notifyObservers();
	}

	void setMeasurements(float temperature, float humidity, float pressure) {
		mTemperature = temperature;
		mHumidity = humidity;
		mPressure = pressure;
		measurementsChanged();
	}

	float getTemperature() { return mTemperature; }
	float getHumidity() { return mHumidity; }

private:
	unordered_set<Observer*> observers;
	float mTemperature;
	float mHumidity;
	float mPressure;
};

class CurrentConditionDisplay : public Observer, DisplayElement {
public:
	CurrentConditionDisplay(WeatherData* weatherData) {
		mWeatherData = weatherData;
		weatherData->registerObserver(this);
	}
	
	void update() {
		mTemperature = mWeatherData->getTemperature();
		mHumidity = mWeatherData->getHumidity();
		display();
	}

	void display() {
		cout << "Current conditions: " << mTemperature << "F degrees and " << mHumidity << "% humidity\n";
	}

private:
	float mTemperature;
	float mHumidity;
	WeatherData* mWeatherData;
};

int main(void) {
	WeatherData *weatherData = new WeatherData();
	CurrentConditionDisplay *currentDisplay = new CurrentConditionDisplay(weatherData);

	weatherData->setMeasurements(80, 65, 30.4f);
	weatherData->setMeasurements(82, 70, 29.2f);
	weatherData->setMeasurements(78, 90, 29.2f);
}