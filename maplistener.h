#ifndef MAPLISTENER_H
#define MAPLISTENER_H

#include "eventlistener.h"

class Game;

// A listener for the exit command
class MapListener : public EventListener
{
public:
    MapListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // MAPLISTENER_H
