#ifndef ROOM_H
#define ROOM_H

#include<map>
#include<string>
#include <vector>

#include "item.h"

using namespace std;
using std::vector;

class Room
{

friend class Game;

public:
    Room(string name);
    string getName();
    void setExits(Room *north, Room *east, Room *south, Room *west);
    Room *getExit(string direction);
    vector <Item> itemsInRoom;


private:
    int numberOfItems();
    string name;
    map<string, Room *> exits;
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location, string inString);
};

#endif // ROOM_H
