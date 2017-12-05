#include "HW3Model.h"

vector<Coupling> HW3Model::init_couplings() {
    return {
        Coupling(0, XOR_1), Coupling(XOR_1, XOR_2),
        Coupling(XOR_2, 0), Coupling(XOR_2, MEM_MODEL),
        Coupling(MEM_MODEL, XOR_2)
    };
}

vector<Model *> HW3Model::init_sub_models() {
    return {XOR_1, XOR_2, MEM_MODEL};
}

vector<string> HW3Model::init_input_symbol_set() {
    return {"0", "1"};
}

vector <string> HW3Model::init_output_token_set() {
    return {"0", "1"};
}

string HW3Model::get_state_string() {
    return "N/A";
}