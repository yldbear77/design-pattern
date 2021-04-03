#include "HomeTheaterFacade.h"

#include "PopcornPopper.h"
#include "Screen.h"
#include "TheaterLights.h"
#include "Projector.h"
#include "StreamingPlayer.h"
#include "Tuner.h"
#include "Amplifier.h"

int main(void) {
	PopcornPopper* popper = new PopcornPopper;
	Screen* screen = new Screen;
	TheaterLights* lights = new TheaterLights;
	Projector* projector = new Projector;
	StreamingPlayer* player = new StreamingPlayer;
	Tuner* tuner = new Tuner;
	Amplifier* amp = new Amplifier;

	HomeTheaterFacade* homeTheater = new HomeTheaterFacade(
		amp,
		tuner,
		player,
		projector,
		lights,
		screen,
		popper
	);

	homeTheater->watchMovie("Raiders of the Lost Ark");
	homeTheater->endMovie();

	return 0;
}