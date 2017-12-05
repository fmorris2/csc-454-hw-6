#include "AtomicModel.h"
#include "../event/Schedulers.h"

void AtomicModel::execute_functions() {
    const bool TIME_ADVANCE_NEEDED = queued_events_has_time_adv();

    if(TIME_ADVANCE_NEEDED) {
        handle_lambda();
    }

    if(queued_events.size() >= 2 && TIME_ADVANCE_NEEDED) {
        delta_conf();
        time_advance();
    }
    else if(queued_events.size() >= 1 && !TIME_ADVANCE_NEEDED) {
        delta_ext();
        time_advance();
    }
    else if(TIME_ADVANCE_NEEDED) {
        delta_int();
        time_advance();
    }

    Schedulers::CURRENT.increment_discrete_time();
}

void AtomicModel::handle_lambda() {
    log("output at " + Schedulers::CURRENT.get_time_string() + " - ");
    vector<string> lambda_result = lambda();
    output.insert(output.end(), lambda_result.begin(), lambda_result.end());
    for(string token : output) {
        cout << "\t\t\t" << token << endl;
    }
}

void AtomicModel::time_advance() {
    vector<DiscreteEvent*> temp;
    vector<DiscreteEvent*> global = Schedulers::GLOBAL.get_elements();

    //get rid of any old time adv event for this model
    for(int i = 0; i < global.size(); i++) {
        if(!global[i]->is_time_adv() || global[i]->get_model_id() != model_id) {
            temp.push_back(global[i]);
        }
    }

    //schedule new time adv
    DiscreteEvent* new_time_adv = generate_time_advance_event();
    temp.push_back(new_time_adv);
    Schedulers::GLOBAL.clear();
    Schedulers::GLOBAL.add_all(temp);
    debug("new time advance has been scheduled: " + new_time_adv->toString());
}