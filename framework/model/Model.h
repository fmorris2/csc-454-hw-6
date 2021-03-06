#ifndef CSC_454_HW_4A_MODEL_H
#define CSC_454_HW_4A_MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include "../event/DiscreteEvent.h"
using namespace std;
class Model {
public:
    vector <string> execute_lambda();
    void queue_events(vector<DiscreteEvent*> events);
    void execute_delta();
    void debug(string str);
    int get_model_id();
    virtual void reset_input_and_output();
    virtual void execute_functions() = 0;
    virtual void time_advance() = 0;
    virtual void cleanup();
    virtual void init(string model_name);

    //setters
    virtual void set_debug_mode(bool mode);

    //getters
    string get_model_name();
    vector<string> get_output();
    vector<DiscreteEvent*> get_queued_events();
    bool is_running = true;

    //factory method
    template<typename T>
    static Model* create(string model_name) {
        T *t = new T();
        Model *m = dynamic_cast<Model *>(t);
        m->init(model_name);
        return t;
    }

protected:
    static int num_models;
    void log(string str);
    bool queued_events_has_time_adv();

    vector <DiscreteEvent*> queued_events;
    vector <string> input_symbol_set;
    vector <string> output_token_set;
    vector <string> output;
    double elapsed_time, last_event_time;
    int model_id;

    virtual vector <string> init_input_symbol_set() = 0;
    virtual vector <string> init_output_token_set() = 0;
    virtual string get_state_string() = 0;

private:
    string model_name;
    bool debug_mode;
};

#endif //CSC_454_HW_4A_MODEL_H
