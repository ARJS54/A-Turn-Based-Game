#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include "eventlistener.h"

class Game;

class KeyListener : public EventListener
{
friend class Game;

public:
    KeyListener(Game *game);
    void run(void *args) override;

private:
    Game *game;
};

#endif // KEYLISTENER_H
