#include <iostream>

#include "RemoteControl.h"
#include "Light.h"
#include "Stereo.h"
#include "GarageDoor.h"
#include "Command.h"

using namespace std;

int main(void) {
	Light* livingRoomLight = new Light("Living Room");
	LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
	LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);

	Light* kitchenLight = new Light("Kitchen");
	LightOnCommand* kitchenLightOn = new LightOnCommand(kitchenLight);
	LightOffCommand* kitchenLightOff = new LightOffCommand(kitchenLight);

	GarageDoor* garageDoor = new GarageDoor("Garage");
	GarageDoorOpenCommand* garageDoorOpen = new GarageDoorOpenCommand(garageDoor);
	GarageDoorCloseCommand* garageDoorClose = new GarageDoorCloseCommand(garageDoor);

	Stereo* stereo = new Stereo("Living Room");
	StereoOnWithCDCommand* stereoOnWithCD = new StereoOnWithCDCommand(stereo);

	RemoteControl* remote = new RemoteControl;

	remote->setCommand(0, livingRoomLightOn, livingRoomLightOff);
	remote->setCommand(1, kitchenLightOn, kitchenLightOff);
	remote->setCommand(2, garageDoorOpen, garageDoorClose);
	remote->setCommand(3, stereoOnWithCD);

	remote->onButtonWasPressed(0);
	remote->offButtonWasPressed(0);
	remote->onButtonWasPressed(1);
	remote->offButtonWasPressed(1);
	remote->onButtonWasPressed(2);
	remote->offButtonWasPressed(2);
	//remote->onButtonWasPressed(3);
	//remote->offButtonWasPressed(3);
	remote->undoButtonWasPressed();

	remote->status();

	return 0;
}