#include <iostream>
#include <cstring>
#include "Room.h"
#include "Item.h"

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

void room::describe() {
  cout << "You are in " << roomDescription << "." << endl;
  cout << "There are exits ";
  for (auto it = exits.begin(); it != exits.end(); it++) {
    cout << directionString(it->first) << " ";
  }
  cout << endl;
  cout << "There are items: ";
  for (auto it = items.begin(); it != items.end(); it++) {
    (*it)->describe();
    cout << " ";
  }
  cout << endl;
}

void room::setExit(direction exitDirection, room* probablyNotThisRoom) {
  exits.insert({exitDirection, probablyNotThisRoom});
}

void room::addItem(Item* newAddItem) {
  items.push_back(newAddItem);
}
