#include "XORModel.h"

vector<string> XORModel::lambda() {
    debug("lambda for " + get_model_name());
    return {get_state_string()};
}

void XORModel::delta_int() {
    debug("delta_int for " + get_model_name());
    if(bits.size() >= 2) {
        bits.erase(bits.begin(), bits.begin() + 2);
        debug("erased first 2 bits, size of bits vector is now: " + to_string(bits.size()));
    }
}

void XORModel::delta_ext() {
    debug("delta_ext for " + get_model_name());
    for(DiscreteEvent* e : queued_events) {
        if (e->is_time_adv()) {
            continue;
        }

        bits.push_back(e->symbol.compare("0") == 0 ? 0 : 1);
    }

    debug("size of bits vector: " + to_string(bits.size()));
}

void XORModel::delta_conf() {
    debug("deltaConf for " + get_model_name());
    delta_int();
    delta_ext();
}

DiscreteEvent* XORModel::generate_time_advance_event() {
    debug("generate time advance event");
    double rt = Schedulers::CURRENT.get_real_time();
    return new DiscreteEvent(model_id, rt + 1, 0, "time advance");
}

string XORModel::get_state_string() {
    return bits.size() >= 2 ? to_string(bits[0]^bits[1]) : "0";
}

vector <string> XORModel::init_output_token_set() {
    return {"0","1"};
}

vector<string> XORModel::init_input_symbol_set() {
    return {"0","1"};
}
