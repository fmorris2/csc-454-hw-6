#include "NetworkModel.h"

#include "../event/Schedulers.cpp"
void NetworkModel::init(string model_name) {
    Model::init(model_name);
    sub_models = init_sub_models();
    couplings = init_couplings();
}

void NetworkModel::run() {
    debug("state at " + Schedulers::CURRENT.get_time_string() + " - " + get_state_string());
    debug("elapsed time: " + to_string(Schedulers::CURRENT.get_elapsed_time()));
    debug("event queue size at " + Schedulers::CURRENT.get_time_string() + " - "
          + to_string(Schedulers::GLOBAL.size()));
    debug("current events queue size at " + Schedulers::CURRENT.get_time_string()
          + " - " + to_string(Schedulers::CURRENT.size()));

    pass_relevant_events_to_sub_models(Schedulers::CURRENT.get_elements());
    execute_sub_models_with_events();

    Schedulers::CURRENT.clear();
    prepare_next_events();
    cout << endl;
}

void NetworkModel::execute_sub_models_with_events() {

}

void NetworkModel::route_output(Model *model) {

}

void NetworkModel::pass_relevant_events_to_sub_models(vector <DiscreteEvent> events) {
    
}

void NetworkModel::execute_functions() {
    pass_relevant_events_to_sub_models(queued_events);
    execute_sub_models_with_events();
}

void NetworkModel::prepare_next_events() {
    if(!Schedulers::GLOBAL.is_empty()) {
        do {
            DiscreteEvent* event = Schedulers::GLOBAL.peek();
            Schedulers::GLOBAL.delete_min();
            debug("Adding event from event queue to current events: " + event->toString());
            Schedulers::CURRENT.insert(*event);

        }while(!Schedulers::GLOBAL.is_empty()
               && Schedulers::GLOBAL.peek()->get_real_time()
                  <= Schedulers::CURRENT.get_real_time());
    }
}

void NetworkModel::initialize_time_advance() {
    for(Model* m : sub_models) {
        m->time_advance();
    }
}

void NetworkModel::time_advance() {
    initialize_time_advance();
}

void NetworkModel::reset_input_and_output() {
    Model::reset_input_and_output();
    for(Model* m : sub_models) {
        m->reset_input_and_output();
    }
}

void NetworkModel::cleanup() {
    for(int i = 0; i < sub_models.size(); i++) {
        debug("cleaning up " + sub_models[i]->get_model_name());
        sub_models[i]->cleanup();
        delete(sub_models[i]);
    }
}

void NetworkModel::set_debug_mode(bool mode) {
    Model::set_debug_mode(mode);
    for(Model* m : sub_models) {
        m->set_debug_mode(mode);
    }
}
