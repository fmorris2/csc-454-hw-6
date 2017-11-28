//
// Created by freddy on 11/27/17.
//

#include "CustomPriorityQueue.h"

CustomPriorityQueue::CustomPriorityQueue() {

}

void CustomPriorityQueue::insert(DiscreteEvent e) {

}

void CustomPriorityQueue::add_all(vector <DiscreteEvent> events) {

}

void CustomPriorityQueue::clear() {

}

bool CustomPriorityQueue::is_empty() {
    return size() == 0;
}

DiscreteEvent CustomPriorityQueue::peek() {
    DiscreteEvent e = DiscreteEvent(0,5,"");
    return e;
}

DiscreteEvent CustomPriorityQueue::poll() {
    DiscreteEvent e = DiscreteEvent(0,5,"");
    return e;
}

int CustomPriorityQueue::size() {
    return -1;
}