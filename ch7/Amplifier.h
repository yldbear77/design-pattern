#ifndef __AMPLIFIER_H__
#define __AMPLIFIER_H__

#include "StreamingPlayer.h"

class Amplifier {
public:
	void on() {}
	void off() {}
	void setStreamingPlayer(StreamingPlayer *player) {}
	void setSurroundSound() {}
	void setVolume(int n) {}
};

#endif