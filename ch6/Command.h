#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "Light.h"
#include "GarageDoor.h"
#include "Stereo.h"
#include "CeilingFan.h"

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class NoCommand : public Command {
public:
	void execute() {}
	void undo() {}
};

class LightOnCommand : public Command {
public:
	LightOnCommand(Light* light) : mLight(light) {}
	void execute() { mLight->on(); }
	void undo() { mLight->off(); }

private:
	Light* mLight;
};

class LightOffCommand : public Command {
public:
	LightOffCommand(Light* light) : mLight(light) {}
	void execute() { mLight->off(); }
	void undo() { mLight->on(); }

private:
	Light* mLight;
};

class GarageDoorOpenCommand : public Command {
public:
	GarageDoorOpenCommand(GarageDoor* door) : mGarageDoor(door) {}
	void execute() { mGarageDoor->open(); }
	void undo() { mGarageDoor->close(); }

private:
	GarageDoor* mGarageDoor;
};

class GarageDoorCloseCommand : public Command {
public:
	GarageDoorCloseCommand(GarageDoor* door) : mGarageDoor(door) {}
	void execute() { mGarageDoor->close(); }
	void undo() { mGarageDoor->open(); }

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

	void undo() {

	}

private:
	Stereo* mStereo;
};

class CeilingFanHighCommand : public Command {
public:
	CeilingFanHighCommand(CeilingFan* ceilingFan) { mCeilingFan = ceilingFan; }

	void execute() {
		prevSpeed = mCeilingFan->getSpeed();
		mCeilingFan->high(); 
	}

	void undo() {
		if (prevSpeed == CeilingFan::HIGH) mCeilingFan->high();
		else if (prevSpeed == CeilingFan::MEDIUM) mCeilingFan->medium();
		else if (prevSpeed == CeilingFan::LOW) mCeilingFan->low();
		else if (prevSpeed == CeilingFan::OFF) mCeilingFan->off();
	}

private:
	CeilingFan* mCeilingFan;
	int prevSpeed;
};

class CeilingFanMediumCommand : public Command {
public:
	CeilingFanMediumCommand(CeilingFan* ceilingFan) { mCeilingFan = ceilingFan; }

	void execute() {
		prevSpeed = mCeilingFan->getSpeed();
		mCeilingFan->medium();
	}

	void undo() {
		if (prevSpeed == CeilingFan::HIGH) mCeilingFan->high();
		else if (prevSpeed == CeilingFan::MEDIUM) mCeilingFan->medium();
		else if (prevSpeed == CeilingFan::LOW) mCeilingFan->low();
		else if (prevSpeed == CeilingFan::OFF) mCeilingFan->off();
	}

private:
	CeilingFan* mCeilingFan;
	int prevSpeed;
};

class CeilingFanOffCommand : public Command {
public:
	CeilingFanOffCommand(CeilingFan* ceilingFan) { mCeilingFan = ceilingFan; }

	void execute() {
		prevSpeed = mCeilingFan->getSpeed();
		mCeilingFan->off();
	}

	void undo() {
		if (prevSpeed == CeilingFan::HIGH) mCeilingFan->high();
		else if (prevSpeed == CeilingFan::MEDIUM) mCeilingFan->medium();
		else if (prevSpeed == CeilingFan::LOW) mCeilingFan->low();
		else if (prevSpeed == CeilingFan::OFF) mCeilingFan->off();
	}

private:
	CeilingFan* mCeilingFan;
	int prevSpeed;
};

#endif