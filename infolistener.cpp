#include "infolistener.h"

#include "game.h"

InfoListener::InfoListener(Game *game)
{
    this->game = game;
}

void InfoListener::run(void *)
{
    game->info();
}
