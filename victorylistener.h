#ifndef VICTORYLISTENER_H
#define VICTORYLISTENER_H

#include "eventlistener.h"

// VictoryListener.h
class Game;

// A listener for the good ending
class VictoryListener : public EventListener
{
public:
    VictoryListener(Game *game);
    void run(void *args) override;
private:
   Game *game;
};

#endif // VICTORYLISTENER_H
