#include <iostream>
#include <vector>
#include "Clock.h"
#include "Sequencer.h"

using namespace std;

int main() {
    Clock* clock = new Clock(100, 1);
    Sequencer* seq = new Sequencer(clock);
    seq->setSequence({ true, true, true, true });
    clock->start();

    int c;
    cin >> c;

    return 0;
}
