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
    DiscreteEvent(double rt, int dt, string s);
    int discrete_time;
    string symbol;
    double get_real_time() const;
    int get_real_time_int() const;
    bool is_time_adv() const;
    string toString();
protected:
    double real_time;
};

struct DiscreteEventCompare
{
    bool operator()(DiscreteEvent &t1, DiscreteEvent &t2)
    {
        if(t1.get_real_time_int() == t2.get_real_time_int()) {
            return t1.discrete_time > t2.discrete_time;
        }

        return t1.get_real_time_int() > t2.get_real_time_int();
    }
};

#endif //CSC_454_HW_5A_DISCRETEEVENT_H
