#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item(char* itemName);
  ~Item();
  void describe();
  
 protected:
  char* itemName;
};

