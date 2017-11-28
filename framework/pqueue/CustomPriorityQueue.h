//
// Created by freddy on 11/27/17.
//

#ifndef CSC_454_HW_6_CUSTOMPRIORITYQUEUE_H
#define CSC_454_HW_6_CUSTOMPRIORITYQUEUE_H

#include <vector>
#include "../event/DiscreteEvent.h"
class CustomPriorityQueue {
public:
    CustomPriorityQueue();
    void add_all(vector<DiscreteEvent> events);
    void insert(DiscreteEvent e);
    void clear();
    int size();
    bool is_empty();
    DiscreteEvent peek();
    DiscreteEvent poll();

};

#endif //CSC_454_HW_6_CUSTOMPRIORITYQUEUE_H
