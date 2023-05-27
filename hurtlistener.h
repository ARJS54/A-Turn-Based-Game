#ifndef HURTLISTENER_H
#define HURTLISTENER_H


#include "eventlistener.h"

class Game;

class HurtListener : public EventListener
{
friend class Game;

public:
    HurtListener(Game *game);
    void run(void *args) override;

private:
    Game *game;
};
#endif // HURTLISTENER_H
