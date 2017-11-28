#include "XORModel.h"

vector<string> XORModel::lambda() {
    return {to_string(bit)};
}

void XORModel::delta(vector<char> input) {
    if(input.size() >= 2) {
        int first_bit = (int)input[0];
        int second_bit = (int)input[1];
        bit = first_bit ^ second_bit;
    }
}

string XORModel::get_state_string() {
    return to_string(bit);
}

vector <string> XORModel::init_output_token_set() {
    return {"0","1"};
}

vector<char> XORModel::init_input_symbol_set() {
    return {'0','1'};
}

bool XORModel::init_receives_external_input() {
    return false;
}
