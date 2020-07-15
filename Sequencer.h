#pragma once
#include <vector>
#include "Ticker.h"

class Sequencer : public Ticker {
public:
	Sequencer(Ticker* ticker);
	~Sequencer();

	class Step {
	public:
		Step(bool active) : active(active) {};
		bool active;
	};

	void setSequence(std::vector<bool>);

private:
	Ticker* ticker;
	std::vector<Step> steps;
	int currentTick = 0;
	void tickHandler(long tickTime);
};

