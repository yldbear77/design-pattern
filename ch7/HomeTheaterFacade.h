#ifndef __HOME_THEATER_FACADE_H__
#define __HOME_THEATER_FACADE_H__

#include "PopcornPopper.h"
#include "Screen.h"
#include "TheaterLights.h"
#include "Projector.h"
#include "StreamingPlayer.h"
#include "Tuner.h"
#include "Amplifier.h"

#include <iostream>
#include <string>

class HomeTheaterFacade {
public:
	HomeTheaterFacade(
		Amplifier* amp,
		Tuner* tuner,
		StreamingPlayer* player,
		Projector *projector,
		TheaterLights* lights,
		Screen* screen,
		PopcornPopper* popper
	) :
		mAmp(amp),
		mTuner(tuner),
		mPlayer(player),
		mProjector(projector),
		mLights(lights),
		mScreen(screen),
		mPopper(popper)
	{}

	void watchMovie(std::string movie) {
		std::cout << "Get ready to watch a movie ...\n";
		
		mPopper->on();
		mPopper->pop();
		
		mLights->dim(32);

		mScreen->down();

		mProjector->on();
		mProjector->wideScreenMode();

		mAmp->on();
		mAmp->setStreamingPlayer(mPlayer);
		mAmp->setSurroundSound();
		mAmp->setVolume(5);

		mPlayer->on();
		mPlayer->play(movie);
	}

	void endMovie() {
		std::cout << "Shutting movie theater down ...\n";

		mPopper->off();
		mLights->on();
		mScreen->up();
		mProjector->off();
		mAmp->off();
		mPlayer->stop();
		mPlayer->off();
	}

private:
	Amplifier* mAmp;
	Tuner* mTuner;
	StreamingPlayer* mPlayer;
	Projector* mProjector;
	TheaterLights* mLights;
	Screen* mScreen;
	PopcornPopper* mPopper;
};

#endif