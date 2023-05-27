#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

#include<string>
#include<vector>

#include "eventlistener.h"

using namespace std;

// No need to include if we're just using pointers.
class Game;

// A listener that gets called when a new input is received.
struct InputListener : EventListener // Structs default to public even in inheritance.
{
    InputListener(Game *game);
    void run(void *args) override;

private:
    // We store a game pointer for easy access.
    Game *game;
    vector<string> args;
};

#endif // INPUTLISTENER_H
