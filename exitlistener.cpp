#include "exitlistener.h"

#include "eventmanager.h"
#include "game.h"

ExitListener::ExitListener(Game *game)
{
    this->game = game;
}

void ExitListener::run(void *)
{
    EventManager::getInstance().stop();
}
