#include "DevsSimulation.h"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include "../event/Schedulers.h"

DevsSimulation::DevsSimulation(NetworkModel *model, vector<DiscreteEvent*> input_trajectory) {
    this->model = model;
    Schedulers::GLOBAL.add_all(input_trajectory);
    model->initialize_time_advance();
}

void DevsSimulation::run() {
    while(should_execute() && !model->has_reached_special_ending_conditions()) {
        cout << "Simulation currently at time " << Schedulers::CURRENT.get_time_string() << endl;
        model->run();
        for(string network_output_token : model->get_output()) {
            cout << "Network Output for " << model->get_model_name() << ": " << network_output_token << endl;
        }
        model->reset_input_and_output();
        Schedulers::CURRENT.reset_discrete_time();
    }
}

bool DevsSimulation::should_execute() {
    return !(Schedulers::CURRENT.has_all_inf_time_advance()
                && Schedulers::CURRENT.has_no_input()
                && Schedulers::GLOBAL.has_no_input()
                && Schedulers::GLOBAL.has_all_inf_time_advance());
}

void DevsSimulation::set_debug_mode(bool debug) {
    model->set_debug_mode(debug);
}

void DevsSimulation::cleanup() {
    model->cleanup();
    cout << "[Simulation] Cleaning up " << model->get_model_name() << endl;
    delete(model);

    Schedulers::CURRENT.cleanup();
    Schedulers::GLOBAL.cleanup();
}