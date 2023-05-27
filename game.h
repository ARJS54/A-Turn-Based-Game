#ifndef GAME_H
#define GAME_H

#include<string>
#include<vector>

#include "character.h"
#include "room.h"

using namespace std;

class Game
{


//6.Friends
friend class Room;
friend class Character;
friend class KeyListener;
friend class HurtListener;
friend class AttackListener;

public:
    Game();
    void reset(bool show_update = true);
    void map();
    void info();
    void go(string direction);
    void takeItem(string itemTT);
    void teleport();
    void update_screen();
    Character &getPlayer();
    void setOver(bool over);
    bool is_over();
    void setCurrentRoom(Room *next);
    int findCurrentRoom(Character chara);
    void hurtEnemy();

private:
    Character      player;
    Character      *deadGuy;
    Character      *walker;
    vector<Room *> rooms;
    vector<string> mapOfRooms;
    bool           gameOver;
    bool HaveKey = false;
    void moveEnemy();
    void enemyDeathCheck(Character *&enemy);
};
#endif // GAME_H
