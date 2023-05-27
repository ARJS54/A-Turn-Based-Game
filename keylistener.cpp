#include "keylistener.h"

#include "eventmanager.h"
#include "game.h"

KeyListener::KeyListener(Game *game)
{
    this->game = game;
}

void KeyListener::run(void *)
{
    game->HaveKey = true;
}
