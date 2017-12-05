#include <stdlib.h>
#include "framework/simulation/DevsSimulation.h"
#include "hw5_model/HW5Model.h"
#include "hw3_model/HW3Model.h"
#include "framework/pqueue/CustomPriorityQueue.h"

int main() {
    /*
    NetworkModel* model = NetworkModel::create_network_model<HW5Model> ("HW5 Model");

    const vector<DiscreteEvent*> INPUT_TRAJECTORY = {
        new DiscreteEvent(0, 0.3,0,"Metal Ball"),
        new DiscreteEvent(0, 0.7,0,"Metal Ball"),
        new DiscreteEvent(0, 1.0,0,"Metal Ball"),
        new DiscreteEvent(0, 1.5,0,"Metal Ball"),
        new DiscreteEvent(0, 3.5,0,"Metal Ball")
    };
    */

    NetworkModel* model = NetworkModel::create_network_model<HW3Model> ("HW3 Model");

    const vector<DiscreteEvent*> INPUT_TRAJECTORY = {
            new DiscreteEvent(0, 0.0,0,"0"),
            new DiscreteEvent(0, 0.0,1,"1"),
    };

    CustomPriorityQueue p_queue;
    p_queue.add_all(INPUT_TRAJECTORY);

    DevsSimulation simulation = DevsSimulation(model, INPUT_TRAJECTORY);
    simulation.set_debug_mode(false);

    simulation.run();

    simulation.cleanup();
    return EXIT_SUCCESS;
}

