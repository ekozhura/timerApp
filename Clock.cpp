#include "Clock.h"

void CALLBACK timerFunction(
	UINT uID, UINT uMsg, DWORD_PTR dwUser,
	DWORD_PTR dw1, DWORD_PTR dw2) {

	Clock* ticker = (Clock*)dwUser;
	ticker->run(ticker->getCurrentTime());
}

Clock::Clock(double tempo, int tpb) : tempo(tempo), ticksPerBeat(tpb) {
	recalculate();
};

void Clock::recalculate() {
	double beatsPerSecond = tempo / 60.0;
	double ticksPerSecond = beatsPerSecond * ticksPerBeat;
	tickLength = 1.0 / ticksPerSecond;
}

void Clock::start() {
	timeBeginPeriod(0);
	nextTickTime = timeGetTime();
	timerId = timeSetEvent(static_cast<int>(tickLength * 1000), 1, timerFunction,
		(DWORD_PTR)this, TIME_PERIODIC | TIME_CALLBACK_FUNCTION);
}

void Clock::run(long tickTime) {
	doTick(tickTime);
}

long Clock::getCurrentTime() {
	return timeGetTime() - nextTickTime;
}

Clock::~Clock() {
	timeKillEvent(timerId);
	timeEndPeriod(0);
}