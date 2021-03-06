//
// Created by freddy on 11/12/17.
//

#ifndef CSC_454_HW_5A_DISCRETEEVENT_H
#define CSC_454_HW_5A_DISCRETEEVENT_H

using namespace std;

#include <cmath>
#include <climits>
#include <string>
#include <iostream>
class DiscreteEvent {
public:
    DiscreteEvent(int model_id, double rt, int dt, string s);
    int discrete_time;
    string symbol;
    double get_real_time() const;
    int get_real_time_int() const;
    bool is_time_adv() const;
    int get_model_id() const;
    string toString();

    bool operator <(const DiscreteEvent& o) {
        if(get_real_time_int() == o.get_real_time_int()) {
            return discrete_time < o.discrete_time;
        }

        return get_real_time_int() < o.get_real_time_int();
    }

    bool operator ==(const DiscreteEvent& o) {
        return get_real_time_int() == o.get_real_time_int()
                    && discrete_time == o.discrete_time;
    }

    bool operator >(const DiscreteEvent& o) {
        if(get_real_time_int() == o.get_real_time_int()) {
            return discrete_time > o.discrete_time;
        }

        return get_real_time_int() > o.get_real_time_int();
    }

protected:
    double real_time;
    int model_id;
};

#endif //CSC_454_HW_5A_DISCRETEEVENT_H
