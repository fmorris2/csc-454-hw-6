#ifndef CSC_454_HW_4A_MEMORYMODEL_H
#define CSC_454_HW_4A_MEMORYMODEL_H

#include "../../framework/model/AtomicModel.h"
class MemoryModel : public AtomicModel {
public:
    vector<string> init_input_symbol_set();
    vector <string> init_output_token_set();
    string get_state_string();

protected:
    void deltaInt();
    void deltaExt();
    void deltaConf();
    vector<string> lambda();
    DiscreteEvent generate_time_advance_event();

    int queue[2] = {0,0};
};

#endif //CSC_454_HW_4A_MEMORYMODEL_H
