#include "MemoryModel.h"

vector<string> MemoryModel::lambda() {
    return {to_string(queue[0])};
}

void MemoryModel::delta_int() {

}

void MemoryModel::delta_ext() {

}

void MemoryModel::delta_conf() {

}

DiscreteEvent* MemoryModel::generate_time_advance_event() {

}

string MemoryModel::get_state_string() {
    return "(" + to_string(queue[0]) + "," + to_string(queue[1]) + ")";
}

vector <string> MemoryModel::init_output_token_set() {
    return {"0","1"};
}

vector<string> MemoryModel::init_input_symbol_set() {
    return {"0","1"};
}
