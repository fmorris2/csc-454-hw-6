//
// Created by freddy on 12/3/17.
//

#include "PressModel.h"
#include "../../framework/event/Schedulers.h"

vector<string> PressModel::init_input_symbol_set() {
    return {"Metal Ball"};
}

vector <string> PressModel::init_output_token_set() {
    return {"Undrilled Metal Disk"};
}

int PressModel::processing_time() {
    return 1;
}

DiscreteEvent* PressModel::generate_time_advance_event() {
    double rt = Schedulers::CURRENT.get_real_time();
    double ta = parts_bin.size() > 0 ? time_remaining : INT_MAX;
    return new DiscreteEvent(model_id, rt + ta, 0, "time advance");
}