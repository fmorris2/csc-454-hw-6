#include "Model.h"
#include <algorithm>
#include <iostream>

#include "../event/Schedulers.cpp"
string SENTINEL = "halt.";

int Model::num_models = 0;

void Model::init(string model_name) {
    Model::num_models++;
    model_id = Model::num_models;
    input_symbol_set = init_input_symbol_set();
    output_token_set = init_output_token_set();
    this->model_name = model_name;
}

void Model::queue_events(vector <DiscreteEvent> events) {
    queued_events.insert(queued_events.end(), events.begin(), events.end());
    debug("queued up " + to_string(events.size()) + " events for " + model_name
          + "... model now has " + to_string(queued_events.size()) + " queued events.");
    elapsed_time = Schedulers::CURRENT.get_real_time() - last_event_time;
    last_event_time = events.back().get_real_time();
}

void Model::reset_input_and_output() {
    queued_events.clear();
    output.clear();
}

void Model::cleanup() {}

bool Model::queued_events_has_time_adv() {
    for(DiscreteEvent e : queued_events) {
        if(e.is_time_adv()) {
            return true;
        }
    }

    return false;
}
void Model::set_debug_mode(bool mode) {
    debug_mode = mode;
}

void Model::log(string str) {
    cout << "[" << model_name << "] - " << str << endl;
}

void Model::debug(string str) {
    if(debug_mode) {
        log(str);
    }
}

string Model::get_model_name() {
    return model_name;
}