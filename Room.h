#include <iostream>
#include <cstring>
#include <map>

using namespace std;

//from cppreference.com
enum direction {north, east, south, west};

const char* directionString(direction d);
  
class room {
 public:
  room(char* Description);
  ~room();
  
 protected:
  char roomDescription[100];
  //items
  std::map<char*, room*> exits;
};
