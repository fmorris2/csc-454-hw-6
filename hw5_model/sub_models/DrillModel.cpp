//
// Created by freddy on 12/3/17.
//

#include "DrillModel.h"
#include "../../framework/event/Schedulers.h"

vector<string> DrillModel::init_input_symbol_set() {
    return {"Undrilled Metal Disk"};
}

vector <string> DrillModel::init_output_token_set() {
    return {"Drilled Metal Disk"};
}

int DrillModel::processing_time() {
    return 2;
}

DiscreteEvent* DrillModel::generate_time_advance_event() {
    double rt = Schedulers::CURRENT.get_real_time();
    double ta = parts_bin.size() > 0 ? time_remaining : INT_MAX;

    return new DiscreteEvent(model_id, rt + ta, 0, "time advance");
}