#ifndef RESTARTLISTENER_H
#define RESTARTLISTENER_H

#include "eventlistener.h"

class Game;

// A listener for the good ending
class RestartListener : public EventListener
{
public:
    RestartListener(Game *game);
    void run(void *args) override;
private:
   Game *game;
};

#endif // RESTARTLISTENER_H
