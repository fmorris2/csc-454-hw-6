#include "MemoryModel.h"

vector<string> MemoryModel::lambda() {
    return {to_string(queue[0])};
}

void MemoryModel::delta(vector<char> input) {
    if(input.size() > 0) {
        char input_token = input[0];
        debug(string("input token: ") + input_token);
        queue[0] = queue[1];
        queue[1] = input_token == '1' ? 1 : 0;
        debug(string("new queue: ") + get_state_string());
    }
}

string MemoryModel::get_state_string() {
    return "(" + to_string(queue[0]) + "," + to_string(queue[1]) + ")";
}

vector <string> MemoryModel::init_output_token_set() {
    return {"0","1"};
}

vector<char> MemoryModel::init_input_symbol_set() {
    return {'0','1'};
}

bool MemoryModel::init_receives_external_input() {
    return false;
}
