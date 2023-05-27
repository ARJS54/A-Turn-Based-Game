#ifndef INFOLISTENER_H
#define INFOLISTENER_H

#include "eventlistener.h"

class Game;

class InfoListener : public EventListener
{
public:
    InfoListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // INFOLISTENER_H
