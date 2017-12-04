#include "../model/NetworkModel.h"
#include "../event/DiscreteEvent.h"
using namespace std;

#ifndef CSC_454_HW_4A_SIMULATION_H
#define CSC_454_HW_4A_SIMULATION_H

class DevsSimulation {
public:
    DevsSimulation(NetworkModel *model, vector<DiscreteEvent*> input_trajectory);
    void run();
    void set_debug_mode(bool debug);
    void cleanup();
private:
    NetworkModel *model;
    bool should_execute();
    bool has_no_input(vector<DiscreteEvent*> events);
    bool has_all_inf_time_advance(vector<DiscreteEvent*> events);
};

#endif //CSC_454_HW_4A_SIMULATION_H
