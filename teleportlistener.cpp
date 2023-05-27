#include "teleportlistener.h"

#include "game.h"

TeleportListener::TeleportListener(Game *game)
{
    this->game = game;
}

void TeleportListener::run(void *)
{
    if (game->is_over()) {
        return;
    }

    this->game->teleport();
}
