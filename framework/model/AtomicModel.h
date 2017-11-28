#include "Model.h"
#ifndef CSC_454_HW_4A_ATOMICMODEL_H
#define CSC_454_HW_4A_ATOMICMODEL_H

class AtomicModel : public Model {
public:
    void time_advance();
    void execute_functions();

protected:
    virtual void deltaInt() = 0;
    virtual void deltaExt() = 0;
    virtual void deltaConf() = 0;
    virtual vector<string> lambda() = 0;
    virtual DiscreteEvent generate_time_advance_event() = 0;

private:
    void handle_lambda();
};

#endif //CSC_454_HW_4A_ATOMICMODEL_H
