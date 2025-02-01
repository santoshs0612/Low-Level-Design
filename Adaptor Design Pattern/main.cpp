#include<bits/stdc++.h>

#include "adapter.cpp"
#include "adaptee.cpp"



int main(){

    AdapterWeightMachine *wt = new WeightInKg(new WeightMachineForBabies());
    double wtInKg = wt->getWeightInKg();
    std::cout<< "Weight For the Baby is "<<wtInKg;
    delete wt;
    return 0;
}