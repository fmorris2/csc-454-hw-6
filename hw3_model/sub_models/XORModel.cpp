#include "XORModel.h"

vector<string> XORModel::lambda() {
    return {to_string(bit)};
}

void XORModel::delta_int() {

}

void XORModel::delta_ext() {

}

void XORModel::delta_conf() {

}

DiscreteEvent XORModel::generate_time_advance_event() {

}

string XORModel::get_state_string() {
    return to_string(bit);
}

vector <string> XORModel::init_output_token_set() {
    return {"0","1"};
}

vector<string> XORModel::init_input_symbol_set() {
    return {"0","1"};
}
