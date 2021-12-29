#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

int main() {
  char userIn[50];
  //store item loactions in a thing
  //store map/room layout in a different thing

  cout << "Commands: " << endl
       << directionString(north) << ": Takes you to the room north of this "
       "room if possible" << endl
       << "EAST: Takes you to the room east of this room if possible" << endl
       << "SOUTH: Takes you to the room south of this room if possible" << endl
       << "WEST: Takes you to the room west of this room if possible" << endl;

  //might want to put this in a loop if code gets structured this way
  cout << "Type HELP for list of commands" << endl
       << "Enter a command to perform an action" << endl;
  
}
