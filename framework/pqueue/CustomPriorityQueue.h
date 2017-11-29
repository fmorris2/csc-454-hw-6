//
// Created by freddy on 11/27/17.
//

#ifndef CSC_454_HW_6_CUSTOMPRIORITYQUEUE_H
#define CSC_454_HW_6_CUSTOMPRIORITYQUEUE_H

#include <vector>
#include "../event/DiscreteEvent.h"
using namespace std;
class CustomPriorityQueue {
public:
    CustomPriorityQueue();
    void add_all(vector<DiscreteEvent> events);
    void insert(DiscreteEvent e);
    void clear();
    int size();
    bool is_empty();
    DiscreteEvent* peek();
    void delete_min();

private:
    vector<DiscreteEvent> heap;
    void percolate_down(int index);
    void percolate_up(int index);
    void heapify();
    int get_left_child_index(int index);
    int get_right_child_index(int index);
    int get_parent_index(int index);
};

#endif //CSC_454_HW_6_CUSTOMPRIORITYQUEUE_H
