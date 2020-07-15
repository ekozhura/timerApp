#include "Ticker.h"

void Ticker::doTick(long tickTime) {
	if (ticker != nullptr) {
		ticker->tickHandler(tickTime);
	}
}

void Ticker::attach(Ticker* t) {
	ticker = t;
}

void Ticker::detach() {
	ticker = nullptr;
}