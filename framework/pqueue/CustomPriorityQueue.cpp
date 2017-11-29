//
// Created by freddy on 11/27/17.
//

#include "CustomPriorityQueue.h"

/**
 * Credit to Anton Kaminsky of codeproject.com
 * for some of the heap source code
 */

CustomPriorityQueue::CustomPriorityQueue() {

}

void CustomPriorityQueue::insert(DiscreteEvent e) {
    const int SIZE = size();
    heap[SIZE] = e;

    percolate_up(SIZE);
}

void CustomPriorityQueue::add_all(vector <DiscreteEvent> events) {
    heap.insert(heap.end(), events.begin(), events.end());
    heapify();
}

void CustomPriorityQueue::clear() {
    heap.clear();
}

bool CustomPriorityQueue::is_empty() {
    return size() == 0;
}

DiscreteEvent* CustomPriorityQueue::peek() {
    return size() > 0 ? &heap[0] : 0;
}

void CustomPriorityQueue::delete_min() {
    const int SIZE = heap.size();

    if(SIZE == 0)
    {
        return;
    }

    heap[0] = heap[SIZE - 1];
    heap.pop_back();
    percolate_down(0);
}

int CustomPriorityQueue::size() {
    return heap.size();
}

void CustomPriorityQueue::heapify() {
    for(int i = size() - 1; i >= 0; i--) {
        percolate_down(i);
    }
}

void CustomPriorityQueue::percolate_up(int index) {
    if(index == 0)
        return;

    const int PARENT = (index-1)/2;

    if(heap[PARENT] > heap[index])
    {
        DiscreteEvent temp = heap[PARENT];
        heap[PARENT] = heap[index];
        heap[index] = temp;
        percolate_up(PARENT);
    }
}

void CustomPriorityQueue::percolate_down(int index) {
    const int LEFT_CHILD = get_left_child_index(index);
    const int RIGHT_CHILD = get_right_child_index(index);

    if(LEFT_CHILD >= size()) { //index is a leaf
        return;
    }

    int min_index = index;

    if(heap[index] > heap[LEFT_CHILD]) {
        min_index = LEFT_CHILD;
    }

    if((RIGHT_CHILD < size()) && (heap[min_index] > heap[RIGHT_CHILD])) {
        min_index = RIGHT_CHILD;
    }

    if(min_index != index) { //swap needed
        DiscreteEvent temp = heap[index];
        heap[index] = heap[min_index];
        heap[min_index] = temp;
        percolate_down(min_index);
    }
}

int CustomPriorityQueue::get_left_child_index(int index) {
    return index * 2 + 1;
}

int CustomPriorityQueue::get_right_child_index(int index) {
    return index * 2 + 2;
}

int CustomPriorityQueue::get_parent_index(int index) {
    return (index - 1) / 2;
}

vector<DiscreteEvent> CustomPriorityQueue::get_elements() {
    return heap;
}

double CustomPriorityQueue::get_real_time() {
    DiscreteEvent* current = peek();
    return current == 0 ? 0 : current->get_real_time();
}

string CustomPriorityQueue::get_time_string() {
    DiscreteEvent* current = peek();
    return current == 0 ? "(0,0)"
            : "("+to_string(current->get_real_time())+","+to_string(discrete_time)+")";
}

double CustomPriorityQueue::get_elapsed_time() {
    if(heap.size() == 0) {
        return 0;
    }

    return heap[0].get_real_time() - last_polled_real_time;
}

void CustomPriorityQueue::reset_discrete_time() {
    discrete_time = 0;
}

void CustomPriorityQueue::increment_discrete_time() {
    discrete_time++;
}