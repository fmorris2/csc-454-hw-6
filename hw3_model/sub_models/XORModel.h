#ifndef CSC_454_HW_4A_XORMODEL_H
#define CSC_454_HW_4A_XORMODEL_H

#include "../../framework/model/AtomicModel.h"
class XORModel : public AtomicModel {
public:
    vector<string> init_input_symbol_set();
    vector <string> init_output_token_set();
    string get_state_string();

protected:
    int bit = 0;

    void delta_int();
    void delta_ext();
    void delta_conf();
    vector<string> lambda();
    DiscreteEvent generate_time_advance_event();
};

#endif //CSC_454_HW_4A_XORMODEL_H
