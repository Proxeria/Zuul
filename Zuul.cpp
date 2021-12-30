#include <iostream>
#include <cstring>
#include "Room.h"
#include "Item.h"
#include <vector>

using namespace std;

int main() {
  char userIn[50];

  cout << "Welcome to Zuul" << endl
       << "There are 5 parts of a sandwich hidden around this building," << endl
       << "collect them all to craft the best sandwich to ever grace this Earth.";
  
  cout << "Type HELP for a list of commands." << endl;
  
  //store item loactions in a thing
  //store map/room layout in a different thing
  if (strcmp(userIn, "HELP") == 0 || strcmp(userIn, "help") == 0) {
    cout << "Commands: " << endl
	 << directionString(north) << ": Takes you to the room north of this "
      "room if possible" << endl
	 << "EAST: Takes you to the room east of this room if possible" << endl
	 << "SOUTH: Takes you to the room south of this room if possible" << endl
	 << "WEST: Takes you to the room west of this room if possible" << endl;
  }

  Item* bacon = new Item((char*)"Bacon");

  bacon->describe();
  
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

  one->setExit(east, two);
  one->setExit(south, six);
  one->describe();

  two->setExit(east, three);
  two->setExit(west, one);
  two->describe();

  three->setExit(south, eight);
  three->setExit(west, two);
  three->describe();

  four->setExit(east, five);
  four->setExit(south, nine);
  four->describe();

  five->setExit(south, ten);
  five->setExit(west, four);
  five->describe();

  six->setExit(north, one);
  six->setExit(south, eleven);
  six->describe();

  seven->setExit(east, eight);
  seven->setExit(south, twelve);
  seven->describe();

  eight->setExit(north, three);
  eight->setExit(east, nine);
  eight->setExit(south, thirteen);
  eight->setExit(west, seven);
  eight->describe();

  nine->setExit(north, four);
  nine->setExit(east, ten);
  nine->setExit(west, eight);
  nine->describe();

  ten->setExit(north, five);
  ten->setExit(south, fifteen);
  ten->setExit(west, nine);
  ten->describe();

  eleven->setExit(north, six);
  eleven->describe();

  twelve->setExit(north, seven);
  twelve->setExit(east, thirteen);
  twelve->describe();

  thirteen->setExit(north, eight);
  thirteen->setExit(east, fourteen);
  thirteen->setExit(west, twelve);
  thirteen->describe();

  fourteen->setExit(east, fifteen);
  fourteen->setExit(west, thirteen);
  fourteen->describe();

  fifteen->setExit(north, ten);
  fifteen->setExit(south, fourteen);
  fifteen->describe();
}


