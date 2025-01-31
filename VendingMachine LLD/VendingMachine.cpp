#include "VendingMachine.h" // Include the header file
#include "IdleState.h"

// Implementation of VendingMachine methods
VendingMachine::VendingMachine() {
  state = nullptr;
  inventory = new Inventory(10);
  coinList = std::vector<Coins>();
  state = new IdleState(this);
}

VendingMachine::~VendingMachine() {
  delete state;
  delete inventory;
}

State *VendingMachine::getVendingState() { return state; }

void VendingMachine::setVendingState(State *state) {
  if (this->state) {
    delete this->state;
  }
  this->state = state;
}

Inventory *VendingMachine::getInventory() { return inventory; }

void VendingMachine::setInventory(Inventory *inventory) {
  this->inventory = inventory;
}

std::vector<Coins> *VendingMachine::getCoinList() { return &coinList; }

void VendingMachine::setCoinList(std::vector<Coins> coinList) {
  this->coinList = coinList;
}