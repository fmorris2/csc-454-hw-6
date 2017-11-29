#include <stdlib.h>
#include "framework/simulation/DevsSimulation.h"
#include "hw5_model/HW5Model.h"
#include "hw3_model/HW3Model.h"
#include "framework/pqueue/CustomPriorityQueue.h"

int main() {
    NetworkModel* model = NetworkModel::create_network_model<HW3Model> ("HW5 Model");

    const vector<DiscreteEvent> INPUT_TRAJECTORY = {
            DiscreteEvent(0.7,0,"took"),
            DiscreteEvent(0,7,"hi"), DiscreteEvent(0,2,"took"),
            DiscreteEvent(1,2,"test"), DiscreteEvent(0.5,3,"poop"),
            DiscreteEvent(3,1,"hello"), DiscreteEvent(3,0,"yup")
    };

    CustomPriorityQueue p_queue;
    p_queue.add_all(INPUT_TRAJECTORY);
    while(!p_queue.is_empty()) {
        DiscreteEvent* e = p_queue.peek();
        cout << e->get_real_time() << ", " << e->discrete_time << endl;
        p_queue.delete_min();
    }

    DevsSimulation simulation = DevsSimulation(model, INPUT_TRAJECTORY);
    simulation.set_debug_mode(true);

    simulation.run();

    simulation.cleanup();
    return EXIT_SUCCESS;
}

