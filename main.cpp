#include <stdlib.h>
#include "framework/simulation/DevsSimulation.h"
#include "hw5_model/HW5Model.h"
int main() {
    NetworkModel* model = NetworkModel::create_network_model<HW5Model> ("HW5 Model");

    const vector<DiscreteEvent> INPUT_TRAJECTORY = {};

    DevsSimulation simulation = DevsSimulation(model, INPUT_TRAJECTORY);
    simulation.set_debug_mode(true);

    simulation.run();

    simulation.cleanup();
    return EXIT_SUCCESS;
}

