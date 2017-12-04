//
// Created by freddy on 11/29/17.
//

#ifndef CSC_454_HW_6_SIMPLEMACHINE_H
#define CSC_454_HW_6_SIMPLEMACHINE_H

#include "../../framework/model/AtomicModel.h"
class SimpleMachine : public AtomicModel{
public:
    virtual vector<string> init_input_symbol_set() = 0;
    virtual vector <string> init_output_token_set() = 0;
    string get_state_string();

protected:
    virtual int processing_time() = 0;
    virtual DiscreteEvent* generate_time_advance_event() = 0;

    void delta_int();
    void delta_ext();
    void delta_conf();
    vector<string> lambda();

    vector<string> parts_bin;
    double time_remaining;
};

#endif //CSC_454_HW_6_SIMPLEMACHINE_H
