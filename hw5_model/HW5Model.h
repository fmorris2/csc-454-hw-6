//
// Created by freddy on 11/27/17.
//

#ifndef CSC_454_HW_6_HW5MODEL_H
#define CSC_454_HW_6_HW5MODEL_H

#include "../framework/model/NetworkModel.h"
class HW5Model : public NetworkModel {
public:
    HW5Model(){}
    void execute_functions();
protected:
    vector<string> init_input_symbol_set();
    vector <string> init_output_token_set();
    string get_state_string();

    vector<Model*> init_sub_models();
    vector<Coupling> init_couplings();
};

#endif //CSC_454_HW_6_HW5MODEL_H
