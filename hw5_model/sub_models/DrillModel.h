//
// Created by freddy on 12/3/17.
//

#ifndef CSC_454_HW_6_DRILLMODEL_H
#define CSC_454_HW_6_DRILLMODEL_H

#include "SimpleMachine.h"
class DrillModel : public SimpleMachine {
public:
    vector<string> init_input_symbol_set();
    vector <string> init_output_token_set();
protected:
    DiscreteEvent* generate_time_advance_event();
    int processing_time();
};

#endif //CSC_454_HW_6_DRILLMODEL_H
