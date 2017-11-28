#include "DevsSimulation.h"

#include <iostream>
#include <stdio.h>
#include <vector>

Simulation::Simulation(Model *model) {
    this->model = model;
}

void Simulation::run() {
    while(model->is_running) {
        cout << "[Simulation] Executing tick #" << tick << endl;
        vector<string> output = model->tick();
        cout << "[Simulation] " << model->get_model_name() << " output at simulation tick #" << tick << ": " << endl;
        for(string token : output) {
            cout << "\t" << token << endl;
        }

        tick++;
    }
}

void Simulation::set_debug_mode(bool debug) {
    model->set_debug_mode(debug);
}

void Simulation::cleanup() {
    model->cleanup();
    cout << "[Simulation] Cleaning up " << model->get_model_name() << endl;
    delete(model);
}