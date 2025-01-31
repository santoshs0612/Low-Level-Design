#include "Coins.h"
#include "DespencingState.h"
#include "IdleState.h"
#include "Inventory.h"
#include "Item.h"
#include "ItemShelf.h"
#include "State.h"
#include "VendingMachine.h"
#include "hasMoneyState.h"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
static void fillUpInventry(VendingMachine *vendingMachine) {

  vector<ItemShelf>* itemShelf = vendingMachine->getInventory()->getInventory();

  for (int i = 0; i < (*itemShelf).size(); i++) {

    Item *newItem = new Item();
    if (i >= 0 && i < 3) {
      newItem->setPrice(12);
      // ItemType a = COKE;
      newItem->setType(COKE);
    } else if (i >= 3 && i < 5) {
      newItem->setPrice(9);
      newItem->setType(SODA);
    } else if (i >= 5 && i < 7) {
      newItem->setPrice(13);
      newItem->setType(WATER);
    } else if (i >= 7 && i < 10) {
      newItem->setPrice(10);
      newItem->setType(PEPSI);
    }
    (*itemShelf)[i].setItem(newItem);
    (*itemShelf)[i].setIsSoldOut(true);
  }
}

static void displayInventry(VendingMachine *vendingMachine) {
  vector<ItemShelf> *itemShelf = vendingMachine->getInventory()->getInventory();
  std::cout << "You are in Display" << std::endl;
  for (int i = 0; i < itemShelf->size(); i++) {
    if ((*itemShelf)[i].getItem() != nullptr) {
      std::cout << "Code Number: " << (*itemShelf)[i].getCode()
                << " Item: " << (*itemShelf)[i].getItem()->getName((*itemShelf)[i].getItem()->getType())
                << " Price: " << (*itemShelf)[i].getItem()->getPrice()
                << " Is Available: " << (*itemShelf)[i].getIsSoldOut()
                << std::endl;
    } else {
      std::cout << "No item at code " << (*itemShelf)[i].getCode() << std::endl;
    }
  }
}

int main() {

  VendingMachine *vendingMachine = new VendingMachine();
  try {
    std::cout << "|" << std::endl;
    std::cout << "Filling Up the Inventery" << std::endl;
    std::cout << "|" << std::endl;
    fillUpInventry(vendingMachine);
    displayInventry(vendingMachine);
    std::cout << "|" << std::endl;
    std::cout << "Clicking on Insert Coin Button "<<std::endl;
    std::cout << "|"<<std::endl;
    State * vendingState = vendingMachine->getVendingState();
    vendingState->clickOnInertCoinButton(vendingMachine);
    vendingState = vendingMachine->getVendingState();
    vendingState->insertCoinButton(vendingMachine, Coins::NICKEL);
    vendingState->insertCoinButton(vendingMachine, Coins::QUARTER);
    // vendingState->insertCoinButton(vendingMachine, Coins::DIME);

    std::cout << "|"<<std::endl;
    std::cout << "Clicking on Select Product Button "<<std::endl;
    std::cout << "|"<<std::endl;
    vendingState->startProductSelectButton(vendingMachine);

    vendingState = vendingMachine->getVendingState();
    vendingState->choseProductButton(vendingMachine,102);

      displayInventry(vendingMachine);
  } catch (exception e) {
    std::cout << "Exception occured" << std::endl;
  }
}
