#ifndef CSC_454_HW_4A_NETWORKMODEL_H
#define CSC_454_HW_4A_NETWORKMODEL_H

#include <vector>
#include "Model.h"
#include "Coupling.h"
class NetworkModel : public Model {
public:
    void cleanup();
    void time_advance();

    //abstract methods
    virtual vector<Model*> init_sub_models() = 0;
    virtual vector<Coupling> init_couplings() = 0;

    void init(string model_name);
    void initialize_time_advance();
    void run();
    void execute_functions();
    void reset_input_and_output();

    //setters
    void set_debug_mode(bool mode);

    template<typename T>
    static NetworkModel* create_network_model(string model_name) {
        T* t = new T();
        NetworkModel* m = dynamic_cast<NetworkModel*>(t);
        m->init(model_name);
        return t;
    }
protected:
    vector<Model*> sub_models;
    vector<Coupling> couplings;

private:
    void route_output(Model* model);
    void route_network_input(vector<char> input);
    void execute_sub_models_with_events();
    void pass_relevant_events_to_sub_models(vector<DiscreteEvent*> events);
    void prepare_next_events();
    Model* get_model_for_id(int id);
};

#endif //CSC_454_HW_4A_NETWORKMODEL_H
