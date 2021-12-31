#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

void Item::describe() {
  cout << itemName << endl;
}

Item::Item(char* newItemName) {
  itemName = new char[strlen(newItemName) + 1];
  strcpy(itemName, newItemName);
}

Item::~Item() {
  delete(itemName);
}

const char* Item::getName() {
  return itemName;
}
