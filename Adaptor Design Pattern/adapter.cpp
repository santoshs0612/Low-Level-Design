#include "adapter.h"
#include "adaptee.cpp"

class WeightInKg : public AdapterWeightMachine {

    WeightMachineForBabies* wtInPound;
    double wt;

public:
    WeightInKg(WeightMachineForBabies* wtinPound) {
        wtInPound = wtinPound;
        wt = wtInPound ? wtInPound->getWeightInPound() : 0;
    }

    double getWeightInKg() {
        return wt * 0.45;
    }
};
