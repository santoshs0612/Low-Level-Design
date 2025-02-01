#ifndef WEIGHT_MACHINE_FOR_BABIES_H
#define WEIGHT_MACHINE_FOR_BABIES_H
#include "adaptee.h"


class WeightMachineForBabies: public AdapteeWeightMachine{

    public:
    WeightMachineForBabies *wt;
        WeightMachineForBabies(){

        }
        double getWeightInPound()override {
            return 28;
        }
}; 

#endif