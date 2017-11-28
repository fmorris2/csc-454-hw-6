#include "NetworkModel.h"

void NetworkModel::init(string model_name) {
    Model::init(model_name);
    sub_models = init_sub_models();
    couplings = init_couplings();
}

void NetworkModel::run() {

}

void NetworkModel::execute_sub_models_with_events() {

}

void NetworkModel::route_output(Model *model) {

}

void NetworkModel::execute_functions() {

}

void NetworkModel::pass_relevant_events_to_sub_models(vector <DiscreteEvent> events) {

}

void NetworkModel::prepare_next_events() {

}

void NetworkModel::initialize_time_advance() {

}

void NetworkModel::route_output(Model *model) {

}

void NetworkModel::reset_input_and_output() {

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
