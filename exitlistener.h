#ifndef EXITLISTENER_H
#define EXITLISTENER_H

#include "eventlistener.h"

class Game;

// A listener for the exit command
class ExitListener : public EventListener
{
public:
    ExitListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // EXITLISTENER_H
