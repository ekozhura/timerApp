#pragma once
#include <iostream>

class Ticker {
public:
	virtual void tickHandler(long tickTime) {};
	
	void doTick(long tickTime);

	void attach(Ticker* t);

	void detach();

protected:
	Ticker* ticker = nullptr;
};

