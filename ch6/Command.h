#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "Light.h"
#include "GarageDoor.h"
#include "Stereo.h"

class Command {
public:
	virtual void execute() = 0;
};

class NoCommand : public Command {
public:
	void execute() {}
};

class LightOnCommand : public Command {
public:
	LightOnCommand(Light* light) : mLight(light) {}
	void execute() { mLight->on(); }

private:
	Light* mLight;
};

class LightOffCommand : public Command {
public:
	LightOffCommand(Light* light) : mLight(light) {}
	void execute() { mLight->off(); }

private:
	Light* mLight;
};

class GarageDoorOpenCommand : public Command {
public:
	GarageDoorOpenCommand(GarageDoor* door) : mGarageDoor(door) {}
	void execute() { mGarageDoor->open(); }

private:
	GarageDoor* mGarageDoor;
};

class GarageDoorCloseCommand : public Command {
public:
	GarageDoorCloseCommand(GarageDoor* door) : mGarageDoor(door) {}
	void execute() { mGarageDoor->close(); }

private:
	GarageDoor* mGarageDoor;
};

class StereoOnWithCDCommand : public Command {
public:
	StereoOnWithCDCommand(Stereo* stereo) : mStereo(stereo) {}
	void execute() {
		mStereo->on();
		mStereo->setCD();
		mStereo->setVolume(11);
	}

private:
	Stereo* mStereo;
};

#endif