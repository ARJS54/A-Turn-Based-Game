#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>

using namespace std;

// No need to include room since we're only working with pointers.
// This is how we tell the compiler "there will be a room eventually".
// This is called a "forward declaration".
class Room;

class Character
{

friend class Game;
friend class HurtListener;
friend class AttackListener;

public:
    Character(string name);
    ~Character();

    string getName();
    int    getHealth();
    int    getStamina();
    Room  *getCurrentRoom();

    void setName(string name);
    void setHealth(int setHealth);
    void setStamina(int stamina);
    void setCurrentRoom(Room *next);

private:
    string name;
    int health;
    int stamina;
    Room *currentRoom;
};

#endif // CHARACTER_H
