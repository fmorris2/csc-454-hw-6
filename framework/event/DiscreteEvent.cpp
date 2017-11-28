//
// Created by freddy on 11/12/17.
//

#include "DiscreteEvent.h"

const double REAL_TIME_MODIFIER = 100.0;

DiscreteEvent::DiscreteEvent(double rt, int dt, char s) {
    real_time = rt;
    discrete_time = dt;
    symbol = s;
}

bool DiscreteEvent::is_time_adv() const {
    return symbol == 't';
}

double DiscreteEvent::get_real_time() const {
    return real_time;
}

int DiscreteEvent::get_real_time_int() const {
    int to_return = round(real_time * REAL_TIME_MODIFIER);
    return to_return < 0 ? INT_MAX : to_return;
}

string DiscreteEvent::toString() {
    return "(" + to_string(real_time) + "," + to_string(discrete_time) + ")"
            + ", symbol: " + symbol;
}