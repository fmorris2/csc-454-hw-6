#include "MemoryModel.h"

vector<string> MemoryModel::lambda() {
    return {to_string(queue[0])};
}

void MemoryModel::delta_int() {
    debug("delta_int for " + get_model_name());
    queue[0] = queue[1];
    queue[1] = 0;
}

void MemoryModel::delta_ext() {
    debug("delta_ext for " + get_model_name());
    for(DiscreteEvent* e : queued_events) {
        if(e->is_time_adv()) {
            continue;
        }

        debug("input token: " + e->symbol);
        queue[1] = e->symbol.compare("1") == 0 ? 1 : 0;
        debug(string("new queue: ") + get_state_string());
    }
}

void MemoryModel::delta_conf() {
    debug("deltaConf for " + get_model_name());
    delta_int();
    delta_ext();
}

DiscreteEvent* MemoryModel::generate_time_advance_event() {
    debug("generate time advance event");
    double rt = Schedulers::CURRENT.get_real_time();
    return new DiscreteEvent(model_id, rt + 1, 0, "time advance");
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
