#ifndef TAKELISTENER_H
#define TAKELISTENER_H

#include "eventlistener.h"
#include "room.h"
#include<string>

using namespace std;

class Game;

class TakeListener : public EventListener
{
public:
    TakeListener(Game *game);
    void run(void *args) override;

private:
    Game *game;
    string itemToTake;
};

#endif // TAKELISTENER_H
