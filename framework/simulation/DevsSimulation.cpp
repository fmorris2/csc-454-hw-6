#include "DevsSimulation.h"

#include <iostream>
#include <stdio.h>
#include <vector>

DevsSimulation::DevsSimulation(NetworkModel *model, vector<DiscreteEvent> input_trajectory) {
    this->model = model;
}

void DevsSimulation::run() {

}

bool DevsSimulation::should_execute() {
    return false;
}

bool DevsSimulation::event_queue_has_no_input() {
    return false;
}

bool DevsSimulation::has_all_inf_time_advance(vector <DiscreteEvent> events) {
    return false;
}

void DevsSimulation::set_debug_mode(bool debug) {
    model->set_debug_mode(debug);
}

void DevsSimulation::cleanup() {
    model->cleanup();
    cout << "[Simulation] Cleaning up " << model->get_model_name() << endl;
    delete(model);
}