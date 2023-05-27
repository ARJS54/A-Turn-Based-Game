#ifndef DEFEATLISTENER_H
#define DEFEATLISTENER_H

#include "eventlistener.h"

// DefeatListener.h
class Game;

// A listener for the bad ending
class DefeatListener : public EventListener
{
public:
    DefeatListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // DEFEATLISTENER_H
