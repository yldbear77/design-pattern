#include <iostream>

#include "RemoteControl.h"
#include "Light.h"
#include "GarageDoor.h"
#include "Command.h"

using namespace std;

int main(void) {
	RemoteControl* remote = new RemoteControl;

	Light* light = new Light;
	LightOnCommand* lightOn = new LightOnCommand(light);

	GarageDoor* door = new GarageDoor;
	GarageDoorOpenCommand* doorOpen = new GarageDoorOpenCommand(door);

	return 0;
}