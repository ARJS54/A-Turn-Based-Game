#ifndef TELEPORTLISTENER_H
#define TELEPORTLISTENER_H

#include "eventlistener.h"

class Game;

// A listener for the Teleport command
class TeleportListener : public EventListener
{
public:
    TeleportListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // TELEPORTLISTENER_H
