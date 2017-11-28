#ifndef CSC_454_HW_4A_COUPLING_H
#define CSC_454_HW_4A_COUPLING_H

#include "Model.h"
class Coupling {
public:
    Coupling(Model* first, Model* second);
    Model* first;
    Model* second;
};


#endif //CSC_454_HW_4A_COUPLING_H
