#ifndef GOLISTENER_H
#define GOLISTENER_H

#include<string>

#include "eventlistener.h"

using namespace std;

class Game;

// A listener for the Go command
class GoListener : public EventListener
{
public:
    GoListener(Game *game);
    void run(void *args) override;
private:
    Game  *game;
    string direction;
};

#endif // GOLISTENER_H
