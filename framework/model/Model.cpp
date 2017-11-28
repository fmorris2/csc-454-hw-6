#include "Model.h"
#include <algorithm>
#include <iostream>

string SENTINEL = "halt.";

void Model::init(string model_name) {
    input_symbol_set = init_input_symbol_set();
    output_token_set = init_output_token_set();
    this->model_name = model_name;
}

void Model::queue_events(vector <DiscreteEvent> events) {

}

void Model::execute_delta() {
    for(int i = 0; i < internal_ticks; i++) {
        execute_delta_once();
    }
}

void Model::reset_input_and_output() {
    queued_events.clear();
    output.clear();
}

void Model::cleanup() {}


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