#include <iostream>
#include <cstring>
#pragma once

using namespace std;

class Item {
 public:
  Item(char* itemName);
  ~Item();
  void describe();
  
 protected:
  char* itemName;
};

