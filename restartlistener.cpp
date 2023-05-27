#include "restartlistener.h"

#include "game.h"

RestartListener::RestartListener(Game *game)
{
    this->game = game;
}

void RestartListener::run(void *)
{
    game->reset(false);
}
