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

  room* one = new room((char*)"room one");
  room* two = new room((char*)"room two");
  room* three = new room((char*)"room three");
  room* four = new room((char*)"room four");
  room* five = new room((char*)"room five");
  room* six = new room((char*)"room six");
  room* seven = new room((char*)"room seven");
  room* eight = new room((char*)"room eight");
  room* nine = new room((char*)"room nine");
  room* ten = new room((char*)"room ten");
  room* eleven = new room((char*)"room eleven");
  room* twelve = new room((char*)"room twelve");
  room* thirteen = new room((char*)"room thirteen");
  room* fourteen = new room((char*)"room fourteen");
  room* fifteen = new room((char*)"room fifteen");

  one->describe();
  
}


