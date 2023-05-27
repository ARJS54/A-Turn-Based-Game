#include "game.h"

#include<ctime>
#include<iostream>
#include <algorithm>

#include "eventmanager.h"
#include "room.h"
#include "hurtlistener.h"
#include "keylistener.h"
#include "takelistener.h"
#include "golistener.h"
#include "maplistener.h"
#include "infolistener.h"
#include "restartlistener.h"
#include "teleportlistener.h"
#include "exitlistener.h"
#include "characterdeathlistener.h"
#include "enterroomlistener.h"
#include "victorylistener.h"
#include "defeatlistener.h"
#include "attacklistener.h"

Game::Game() :
    player("Hero")
{
    srand(time(nullptr
               ));

    // Commands
    EventManager::getInstance().listen("go",        new GoListener(this));
    EventManager::getInstance().listen("map",       new MapListener(this));
    EventManager::getInstance().listen("info",      new InfoListener(this));
    EventManager::getInstance().listen("restart",   new RestartListener(this));
    EventManager::getInstance().listen("teleport",  new TeleportListener(this));
    EventManager::getInstance().listen("exit",      new ExitListener(this));
    EventManager::getInstance().listen("take",      new TakeListener(this));
    EventManager::getInstance().listen("attack",    new AttackListener(this));

    // State changes
    EventManager::getInstance().listen("characterDeath", new CharacterDeathListener(this));
    EventManager::getInstance().listen("enterRoom",      new EnterRoomListener(this));
    EventManager::getInstance().listen("victory",        new VictoryListener(this));
    EventManager::getInstance().listen("defeat",         new DefeatListener(this));
    EventManager::getInstance().listen("key acquired",   new KeyListener(this));
    EventManager::getInstance().listen("hurt",           new HurtListener(this));

    rooms.push_back(new Room("A")); // 0
    rooms.push_back(new Room("B")); // 1
    rooms.push_back(new Room("C")); // 2
    rooms[2]->addItem(new Item("cursed_item", 10, 100));
    rooms.push_back(new Room("D")); // 3
    rooms[3]->addItem(new Item("key", 1, 1));
    rooms.push_back(new Room("E")); // 4
    rooms.push_back(new Room("F")); // 5
    rooms.push_back(new Room("G")); // 6
    rooms.push_back(new Room("H")); // 7
    rooms.push_back(new Room("I")); // 8
    rooms[8]->addItem(new Item("potion", 5, 100));
    rooms.push_back(new Room("J")); // 9

    mapOfRooms.push_back(rooms[0]->getName());//0
    mapOfRooms.push_back(rooms[1]->getName());//1
    mapOfRooms.push_back(rooms[2]->getName());//2
    mapOfRooms.push_back(rooms[3]->getName());//3
    mapOfRooms.push_back(rooms[4]->getName());//4
    mapOfRooms.push_back(rooms[5]->getName());//5
    mapOfRooms.push_back(rooms[6]->getName());//6
    mapOfRooms.push_back(rooms[7]->getName());//7
    mapOfRooms.push_back(rooms[8]->getName());//8
    mapOfRooms.push_back(rooms[9]->getName());//9

    //                 N         E         S         W
    rooms[0]->setExits(rooms[4], rooms[2], rooms[7], rooms[1]);
    rooms[1]->setExits(nullptr,  rooms[0], nullptr,  nullptr);
    rooms[2]->setExits(nullptr,  nullptr,  nullptr,  rooms[0]);
    rooms[3]->setExits(nullptr,  rooms[4], nullptr,  nullptr);
    rooms[4]->setExits(nullptr,  rooms[5], rooms[0], rooms[3]);
    rooms[5]->setExits(nullptr,  nullptr,  nullptr,  rooms[4]);
    rooms[6]->setExits(nullptr,  rooms[7], nullptr,  nullptr);
    rooms[7]->setExits(rooms[0], rooms[8], rooms[9], rooms[6]);
    rooms[8]->setExits(nullptr,  nullptr,  nullptr,  rooms[7]);
    rooms[9]->setExits(rooms[7], nullptr,  nullptr,  nullptr);

    deadGuy = new Character("Plant Boi");
    walker = new Character("Moving Boi");

    reset();
}

void Game::reset(bool show_update)
{
    //6.Friends
    HaveKey = false;
    gameOver = false;
    deadGuy = new Character("Plant Boi");
    walker = new Character("Moving Boi");

    mapOfRooms.clear();
    mapOfRooms.push_back(rooms[0]->getName());
    mapOfRooms.push_back(rooms[1]->getName());
    mapOfRooms.push_back(rooms[2]->getName());
    mapOfRooms.push_back(rooms[3]->getName());
    mapOfRooms.push_back(rooms[4]->getName());
    mapOfRooms.push_back(rooms[5]->getName());
    mapOfRooms.push_back(rooms[6]->getName());
    mapOfRooms.push_back(rooms[7]->getName());
    mapOfRooms.push_back(rooms[8]->getName());
    mapOfRooms.push_back(rooms[9]->getName());

    if(rooms[2]->isItemInRoom("cursed_item")==-1){
            rooms[2]->addItem(new Item("cursed_item", 10, 100));
        }
        if(rooms[3]->isItemInRoom("key")==-1){
            rooms[3]->addItem(new Item("key", 1, 1));
            HaveKey = false;
        }
        if(rooms[8]->isItemInRoom("potion")==-1){
           rooms[8]->addItem(new Item("potion", 5, 100));
        }

    player.setCurrentRoom(rooms[0]);
    mapOfRooms[0] = ("[" + mapOfRooms[0] + "]");
    player.setHealth(100);
    player.setStamina(100);

    deadGuy->setCurrentRoom(rooms[0]);
    mapOfRooms[0] = ("!" + mapOfRooms[0] + "!");
    deadGuy->setHealth(100);
    deadGuy->setStamina(100);

    walker->setCurrentRoom(rooms[0]);
    mapOfRooms[0] = ("!" + mapOfRooms[0] + "!");
    walker->setHealth(100);
    walker->setStamina(100);

    cout << "Welcome to Zork!" << endl;
    if (show_update) {
        update_screen();
    }
}

void Game::setOver(bool over)
{
    this->gameOver = over;
}

void Game::map()
{
    cout << mapOfRooms[3] << "-" << mapOfRooms[4] << "-" << mapOfRooms[5] << endl;
    cout << "  |  " << endl;
    cout << mapOfRooms[1] << "-" << mapOfRooms[0] << "-" << mapOfRooms[2] << endl;
    cout << "  |  " << endl;
    cout << mapOfRooms[6] << "-" << mapOfRooms[7] << "-" << mapOfRooms[8] << endl;
    cout << "  |  " << endl;
    cout << "  " << mapOfRooms[9] << endl;
}

void Game::info()
{
    cout << "Available commands:" << endl;
    cout << " - go <direction>"   << endl;
    cout << " - teleport"         << endl;
    cout << " - map"              << endl;
    cout << " - info"             << endl;
    cout << " - take <item name>" << endl;
    cout << " - attack"           << endl;
    cout << " - restart"          << endl;
    cout << " - exit"             << endl;
}

int Game::findCurrentRoom(Character chara){
    int x = 1;
    for (int i = 0; i<10;i++){
        if(chara.currentRoom == rooms[i]){
            x = i;
        }
    }
return x;
}

void Game::takeItem(string itemTT)
{
    int r = findCurrentRoom(player);
    int x = rooms[r]->isItemInRoom(itemTT);
    if (x < 0){
        cout <<  itemTT + " is not in room" << endl;
    } else {
        if(itemTT == "key"){
            EventManager::getInstance().trigger("key acquired");
        }
        if(itemTT == "cursed_item"){
            EventManager::getInstance().trigger("hurt");
        }
        rooms[r]->removeItemFromRoom(x, itemTT);
    }
}

void Game::go(string direction)
{
    Room *next = player.getCurrentRoom()->getExit(direction);

    if(next == rooms[9] && HaveKey == false){
        cout << "You don't have a key." << endl;
    } else if (next != nullptr) {
        std::vector<Room *>::iterator itrtr = std::find(rooms.begin(), rooms.end(), player.getCurrentRoom()); //getting index as int
        int x = std::distance(rooms.begin(), itrtr);

        std::string chars = "[]";              // removing []
        for (char c: chars) {
            mapOfRooms[x].erase(std::remove(mapOfRooms[x].begin(), mapOfRooms[x].end(), c), mapOfRooms[x].end());
        }


        player.setCurrentRoom(next);

        std::vector<Room *>::iterator itr = std::find(rooms.begin(), rooms.end(), next); //getting index as int
        int i = std::distance(rooms.begin(), itr);

        mapOfRooms[i] = "[" + next->getName() + "]"; // adding [] to next room

        player.setStamina(player.getStamina() - 1);
        EventManager::getInstance().trigger("enterRoom", next);
    } else {
        cout << "You hit a wall" << endl;
    }

    if(walker){
    moveEnemy();
    }
}

void Game::moveEnemy(){
    string direction;
    vector<Room *> temp;

    Room *north =walker->getCurrentRoom()->getExit("north");
    Room *east =walker->getCurrentRoom()->getExit("east");
    Room *south =walker->getCurrentRoom()->getExit("south");
    Room *west =walker->getCurrentRoom()->getExit("west");

    if(north != nullptr)temp.push_back(north);
    if(east != nullptr)temp.push_back(east);
    if(south != nullptr)temp.push_back(south);
    if(west != nullptr)temp.push_back(west);

    srand(time(0));
    int z = rand()%(temp.size());

    Room *next = temp[z];

        std::vector<Room *>::iterator itrtr = std::find(rooms.begin(), rooms.end(), walker->getCurrentRoom()); //getting index as int
        int x = std::distance(rooms.begin(), itrtr);
        mapOfRooms[x] =  mapOfRooms[x].substr(1, mapOfRooms[x].size() - 2); // removing !!

        walker->setCurrentRoom(next);

        std::vector<Room *>::iterator itr = std::find(rooms.begin(), rooms.end(), next); //getting index as int
        int i = std::distance(rooms.begin(), itr);

        mapOfRooms[i] = "!" + mapOfRooms[i] + "!"; // adding !! to next room
        walker->setStamina(walker->getStamina() - 1);

}


void Game::teleport()
{
    int selected = rand() % rooms.size();
        if(selected == 9 && HaveKey == false){
            cout << "You tried entering J through teleporting." << endl;
            cout << "Shame on you noob." << endl;
            cout << "You can't teleport in here without a key hehe." << endl;
            cout << "I threw you into H." << endl;
            cout << "Get rekt." << endl;
            selected = 7;
        }
        std::vector<Room *>::iterator itrtr = std::find(rooms.begin(), rooms.end(), player.getCurrentRoom()); //getting index as int
        int x = std::distance(rooms.begin(), itrtr);

        std::string chars = "[]";              // removing []
        for (char c: chars) {
            mapOfRooms[x].erase(std::remove(mapOfRooms[x].begin(), mapOfRooms[x].end(), c), mapOfRooms[x].end());
        }

        player.setCurrentRoom(rooms[selected]);
        player.setStamina(player.getStamina() - 10);
        EventManager::getInstance().trigger("enterRoom", rooms[selected]);

        std::vector<Room *>::iterator itr = std::find(rooms.begin(), rooms.end(), rooms[selected]);
        int i = std::distance(rooms.begin(), itr);

        mapOfRooms[i] = "[" + rooms[selected]->getName() + "]"; // adding [] to next room

        if(walker){
            moveEnemy();
        }
}

void Game::enemyDeathCheck(Character *&enemy)
{
    if (enemy->health <= 0){
        std::vector<Room *>::iterator itrtr = std::find(rooms.begin(), rooms.end(), enemy->getCurrentRoom()); //getting index as int
                    int x = std::distance(rooms.begin(), itrtr);
                    mapOfRooms[x] =  mapOfRooms[x].substr(1, mapOfRooms[x].size() - 2); // removing !!
        delete enemy;
        enemy = nullptr;
    }
}

void Game::hurtEnemy(){
    if (player.getCurrentRoom() == deadGuy->getCurrentRoom()){
        deadGuy->health -= 10;
        enemyDeathCheck(deadGuy);
    }
    if (player.getCurrentRoom() == walker->getCurrentRoom()){
        walker->health -= 10;
        enemyDeathCheck(walker);
    }
}

bool Game::is_over()
{
    return gameOver;
}

Character &Game::getPlayer()
{
    return player;
}

void Game::update_screen()
{
    if (!gameOver) {
        Room *currentRoom = player.getCurrentRoom();

        cout << endl;
        cout << "You are in " << currentRoom->getName() << endl;

        cout << "Exits:";
        if (currentRoom->getExit("north") != nullptr) { cout << " north"; }
        if (currentRoom->getExit("east")  != nullptr) { cout << " east";  }
        if (currentRoom->getExit("south") != nullptr) { cout << " south"; }
        if (currentRoom->getExit("west")  != nullptr) { cout << " west";  }
        cout << endl;
        cout << player.currentRoom->displayItem() << endl;

        cout << "Your Stats: " << player.getHealth() << " HP - " << player.getStamina() << " ST" << endl;

        if(walker && deadGuy){
            if (player.getCurrentRoom() == deadGuy->getCurrentRoom() || player.getCurrentRoom() == walker->getCurrentRoom()){
                cout << "Enemies in the room:" << endl;
            }
        }
        if(deadGuy){
            if (player.getCurrentRoom() == deadGuy->getCurrentRoom()){
                cout << deadGuy->getName() << ": " << deadGuy->getHealth() << " HP - " << deadGuy->getStamina() << " ST" << endl;
            }
        }
        if(walker){
            if (player.getCurrentRoom() == walker->getCurrentRoom()){
                cout << walker->getName() << ": " << walker->getHealth() << " HP - " << walker->getStamina() << " ST" << endl;
            }
        }

    } else {
        cout << "Type \"restart\" or \"exit\"." << endl;
    }
}
