//
// Created by freddy on 11/27/17.
//

#include "HW5Model.h"


vector<Coupling> HW5Model::init_couplings() {
    return {
        Coupling(0, PRESS), Coupling(PRESS, DRILL),
        Coupling(DRILL, 0),
    };
}

vector<Model *> HW5Model::init_sub_models() {
    return {PRESS, DRILL};
}

vector<string> HW5Model::init_input_symbol_set() {
    return {"Metal Ball"};
}

vector <string> HW5Model::init_output_token_set() {
    return {"Drilled Metal Disk"};
}

string HW5Model::get_state_string() {
    return "N/A";
}