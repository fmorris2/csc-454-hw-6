//
// Created by freddy on 11/29/17.
//

#include "SimpleMachine.h"

void SimpleMachine::delta_int() {
    debug("deltaInt for " + get_model_name());
    parts_bin.pop_back();
    time_remaining = processing_time();
}

vector<string> SimpleMachine::lambda() {
    debug("lambda for " + get_model_name());
    return output_token_set;
}

void SimpleMachine::delta_ext() {
    debug("deltaExt for " + get_model_name());
    if(parts_bin.empty()) {
        time_remaining = processing_time();
    }
    else {
        debug("deltaExt elapsed_time: " + to_string(elapsed_time));
        time_remaining = time_remaining - elapsed_time;
        debug("deltaExt, time_remaining: " + to_string(time_remaining));
    }

    for(DiscreteEvent* e : queued_events) {
        if(!e->is_time_adv()) {
            parts_bin.push_back(e->symbol);
            debug("part added to bin.. parts bin now has " + to_string(parts_bin.size()) + " parts");
        }
    }
}

void SimpleMachine::delta_conf() {
    debug("deltaConf for " + get_model_name());
    delta_int();
    delta_ext();
}

string SimpleMachine::get_state_string() {
    return "Parts Bin: " + to_string(parts_bin.size()) + ", Time Remaining: " + to_string(time_remaining);
}