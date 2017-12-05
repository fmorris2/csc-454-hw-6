#ifndef CSC_454_HW_4A_HW3MODEL_H
#define CSC_454_HW_4A_HW3MODEL_H

#include "../framework/model/NetworkModel.h"
#include "sub_models/MemoryModel.h"
#include "sub_models/XORModel.h"
class HW3Model : public NetworkModel {
public:
    HW3Model(){}
protected:
    vector<string> init_input_symbol_set();
    vector <string> init_output_token_set();
    string get_state_string();

    vector<Model*> init_sub_models();
    vector<Coupling> init_couplings();
    bool has_reached_special_ending_conditions();
private:
    Model* XOR_1 = Model::create<XORModel> ("XOR1");
    Model* XOR_2 = Model::create<XORModel> ("XOR2");
    Model* MEM_MODEL = Model::create<MemoryModel> ("M");

    int ticks_after_empty = 0;
};

#endif //CSC_454_HW_4A_HW3MODEL_H
