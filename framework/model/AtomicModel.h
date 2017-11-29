#include "Model.h"
#ifndef CSC_454_HW_4A_ATOMICMODEL_H
#define CSC_454_HW_4A_ATOMICMODEL_H

class AtomicModel : public Model {
public:
    void execute_functions();
    void time_advance();
protected:
    virtual void delta_int() = 0;
    virtual void delta_ext() = 0;
    virtual void delta_conf() = 0;
    virtual vector<string> lambda() = 0;
    virtual DiscreteEvent generate_time_advance_event() = 0;

private:
    void handle_lambda();
};

#endif //CSC_454_HW_4A_ATOMICMODEL_H
