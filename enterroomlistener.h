#ifndef ENTERROOMLISTENER_H
#define ENTERROOMLISTENER_H

#include "eventlistener.h"

class Game;

// A listener for the good ending
class EnterRoomListener : public EventListener
{
public:
    EnterRoomListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // ENTERROOMLISTENER_H
