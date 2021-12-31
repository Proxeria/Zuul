#include <iostream>
#include <cstring>
#include "Room.h"
#include "Item.h"
#include <vector>

using namespace std;

int main() {
  char userIn[50];
  room* playerLocation = nullptr;

  std::vector<Item*> inventory;

  bool gotBacon = false;
  bool gotBread = false;
  bool gotMayo = false;
  bool gotCheese = false;
  bool gotHam = false;
  
  
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

  Item* bacon = new Item((char*)"bacon");
  Item* bread = new Item((char*)"bread");
  Item* mayo = new Item((char*)"mayo");
  Item* cheese = new Item((char*)"cheese");
  Item* ham = new Item((char*)"ham");
  
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
  //one->describe();

  two->setExit(east, three);
  two->setExit(west, one);
  two->addItem(mayo);
  //two->describe();

  three->setExit(south, eight);
  three->setExit(west, two);
  //three->describe();

  four->setExit(east, five);
  four->setExit(south, nine);
  //four->describe();

  five->setExit(south, ten);
  five->setExit(west, four);
  five->addItem(bread);
  //five->describe();

  six->setExit(north, one);
  six->setExit(south, eleven);
  six->addItem(bacon);
  //six->describe();

  seven->setExit(east, eight);
  seven->setExit(south, twelve);
  //seven->describe();

  eight->setExit(north, three);
  eight->setExit(east, nine);
  eight->setExit(south, thirteen);
  eight->setExit(west, seven);
  //eight->describe();

  nine->setExit(north, four);
  nine->setExit(east, ten);
  nine->setExit(west, eight);
  //nine->describe();

  ten->setExit(north, five);
  ten->setExit(south, fifteen);
  ten->setExit(west, nine);
  //ten->describe();

  eleven->setExit(north, six);
  //eleven->describe();

  twelve->setExit(north, seven);
  twelve->setExit(east, thirteen);
  twelve->addItem(ham);
  //twelve->describe();

  thirteen->setExit(north, eight);
  thirteen->setExit(east, fourteen);
  thirteen->setExit(west, twelve);
  //thirteen->describe();

  fourteen->setExit(east, fifteen);
  fourteen->setExit(west, thirteen);
  //fourteen->describe();

  fifteen->setExit(north, ten);
  fifteen->setExit(south, fourteen);
  fifteen->addItem(cheese);
  // fifteen->describe();

  //GAME STARTS HERE

  cout << "Welcome to Zuul" << endl
       << "There are 5 parts of a sandwich hidden around this building," << endl
       << "collect them all to craft the best sandwich to ever grace this Earth.";
  
  cout << "Type HELP for a list of commands." << endl;
  
  playerLocation = eight;
  while (true) {
    playerLocation->describe();

    cout << "COMMANDS MUST BE LOWERCASE" << endl;
    cout << "Input a command: " << endl;

    cin.getline(userIn, 50, '\n');
    //strlwr(userIn);

    if (strcmp(userIn, "move") == 0) {
      cout << "What direction do you want to move? (n/e/s/w)" << endl;
      cin.getline(userIn, 50, '\n');
      direction moveDirection;
      
      if (strcmp(userIn, "n") == 0) {
	moveDirection = north;
      }
      else if (strcmp(userIn, "e") == 0) {
	moveDirection = east;
      }
      else if (strcmp(userIn, "s") == 0) {
	moveDirection = south;
      }
      else if (strcmp(userIn, "w") == 0) {
	moveDirection = west;
      }
      else {
	cout << "Invalid direction" << endl;
	break;
      }
      if (playerLocation->moveRoom(moveDirection) != nullptr) {
	playerLocation = playerLocation->moveRoom(moveDirection);
      }
      else {
	cout << "You can't move there!" << endl;
      }
    }
    else if (strcmp(userIn, "quit") == 0) {
      break;
    }
    else if (strcmp(userIn, "help") == 0) {
      cout << "Commands: " << endl
	   << "move: "
	   << "north: Takes you to the room north of this room if possible" << endl
	   << "east: Takes you to the room east of this room if possible" << endl
	   << "south: Takes you to the room south of this room if possible" << endl
	   << "west: Takes you to the room west of this room if possible" << endl
	   << "inventory: Displays your current inventory" << endl
	   << "get: pick up an item in the room" << endl
	   << "drop: drop an item from your inventory into the room" << endl
	   << "quit: exits the program" << endl;
    }
    else if (strcmp(userIn, "inventory") == 0) {
      for (auto it = inventory.begin(); it != inventory.end(); it++) {
	(*it)->describe();
      }
    }
    else if (strcmp(userIn, "get") == 0) {
      cout << "What item do you want to pick up?" << endl;
      cin.getline(userIn, 50, '\n');
      Item* roomItem = playerLocation->remItem((char*) userIn);
      if (nullptr == roomItem) {
	cout << "That item isn't there!" << endl;
      }
      else {
	inventory.push_back(roomItem);
	cout << "Iten retrieved!" << endl;
      }
    }
    else if (strcmp(userIn, "drop") == 0) {
      cout << "What item do you want to drop?" << endl;
      Item* dropItem = nullptr;
      cin.getline(userIn, 50, '\n');
      for (auto it = inventory.begin(); it != inventory.end();) {
	if (strcmp(userIn, (*it)->getName()) == 0) {
	  dropItem = *it;
	  it = inventory.erase(it);
	  break;
	}
	else {
	  it++;
	}
      }
      if (nullptr == dropItem) {
	cout << "You do not have that item!" << endl;
      }
      else {
	playerLocation->addItem(dropItem);
      }
    }
    //test for win
    gotBacon = false;
    gotBread = false;
    gotMayo = false;
    gotCheese = false;
    gotHam = false;
    for (auto it = inventory.begin(); it != inventory.end(); it++) {
      if (strcmp("bacon", (*it)->getName()) == 0) {
	gotBacon = true;
      }
      else if (strcmp("bread", (*it)->getName()) == 0) {
	gotBread = true;
      }
      else if (strcmp("mayo", (*it)->getName()) == 0) {
	gotMayo = true;
      }
      else if (strcmp("cheese", (*it)->getName()) == 0) {
	gotCheese = true;
      }
      else if (strcmp("ham", (*it)->getName()) == 0) {
	gotHam = true;
      }
    }
    if (gotBacon && gotBread && gotMayo && gotCheese && gotHam) {
      cout << "You have made a sanwich." << endl
	   << "You win." << endl;
      break;
    }
  }
}


