#include "maplistener.h"

#include "game.h"

MapListener::MapListener(Game *game)
{
    this->game = game;
}

void MapListener::run(void *)
{
    game->map();
}
