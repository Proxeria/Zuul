#include <iostream>
#include <cstring>
#include <map>
#include "Item.h"
#include <vector>

using namespace std;

//from cppreference.com
enum direction {north, east, south, west};

const char* directionString(direction d);
  
class room {
 public:
  room(char* Description);
  ~room();
  void setExit(direction, room*);
  void describe();
  void addItem(Item*);
  Item* remItem(char* itemName);
  room* moveRoom(direction);
  
 protected:
  char* roomDescription;
  std::map<direction, room*> exits;
  std::vector<Item*> items;
};
