#ifndef CHARACTERDEATHLISTENER_H
#define CHARACTERDEATHLISTENER_H

#include "eventlistener.h"

class Game;

// A listener for the bad ending
class CharacterDeathListener : public EventListener
{
public:
    CharacterDeathListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};
#endif // CHARACTERDEATHLISTENER_H
