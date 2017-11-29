#include "DevsSimulation.h"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include "../event/Schedulers.cpp"

DevsSimulation::DevsSimulation(NetworkModel *model, vector<DiscreteEvent> input_trajectory) {
    this->model = model;
    Schedulers::GLOBAL.add_all(input_trajectory);
    model->initialize_time_advance();
}

void DevsSimulation::run() {
    while(should_execute()) {
        model->run();
        Schedulers::CURRENT.reset_discrete_time();
    }
}

bool DevsSimulation::should_execute() {
    return !(has_all_inf_time_advance(Schedulers::CURRENT.get_elements())
                && event_queue_has_no_input()
                && has_all_inf_time_advance(Schedulers::GLOBAL.get_elements()));
}

bool DevsSimulation::event_queue_has_no_input() {
    for(DiscreteEvent e : Schedulers::GLOBAL.get_elements()) {
        if(!e.is_time_adv()) {
            return false;
        }
    }
    return true;
}

bool DevsSimulation::has_all_inf_time_advance(vector <DiscreteEvent> events) {
    for(DiscreteEvent e : events) {
        if(e.is_time_adv() && e.get_real_time() < INT_MAX) {
            return false;
        }
    }
    return true;
}

void DevsSimulation::set_debug_mode(bool debug) {
    model->set_debug_mode(debug);
}

void DevsSimulation::cleanup() {
    model->cleanup();
    cout << "[Simulation] Cleaning up " << model->get_model_name() << endl;
    delete(model);
}