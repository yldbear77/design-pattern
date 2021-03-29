#ifndef __STEREO_H__
#define __STEREO_H__

#include <iostream>

class Stereo {
public:
	Stereo(std::string name) : mName(name) {}

	void on() {
		std::cout << "Stereo is On\n";
	}

	void setCD() {
		std::cout << "Stereo sets CD\n";
	}

	void setVolume(int v) {
		std::cout << "Stereo's volume is " << v << '\n';
	}

private:
	std::string mName;
};

#endif