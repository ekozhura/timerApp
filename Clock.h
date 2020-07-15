#pragma once
#include "windows.h"
#include "timeapi.h"
#include "Ticker.h"

class Clock : public Ticker {
public:
	Clock(double tempo, int tpb);
	~Clock();
	long getCurrentTime();
	void run(long tickTime);
	void start();
private:
	long nextTickTime{ 0 };
	double tempo{ 120.0 };
	int ticksPerBeat{ 4 };
	double tickLength{ 0 };
	MMRESULT timerId;

	void recalculate();
};

