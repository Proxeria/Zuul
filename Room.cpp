#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

//from cppreference.com
const char* directionString(direction d) {
  switch(d) {
  case north : return "North";
  case east : return "East";
  case south : return "South";
  case west : return "West";
  default: return "Invalid Direction.";
  }
}

room::room(char* newDescription) {
  roomDescription = new char[strlen(newDescription) + 1];
  strcpy(roomDescription, newDescription);
}

room::~room() {
  delete(roomDescription);
}
