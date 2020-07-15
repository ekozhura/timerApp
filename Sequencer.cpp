#include <iostream>
#include "Sequencer.h"

Sequencer::Sequencer(Ticker* ticker) : ticker(ticker) {
	if (ticker != nullptr) {
		ticker->attach(this);
	}
};

void Sequencer::tickHandler(long tickTime) {

	int numOfSteps = steps.size();
	Step step = steps[currentTick];

	if (step.active) {
		std::cout << "play some note" << std::endl;
	}

	doTick(tickTime);
	currentTick = (currentTick + 1) % numOfSteps;
}

void Sequencer::setSequence(std::vector<bool> newSteps) {
	for (bool active: newSteps) {
		steps.push_back(Step(active));
	}
}

Sequencer::~Sequencer() {
	if (ticker != nullptr) {
		ticker->detach();
	}
	ticker = nullptr;
}