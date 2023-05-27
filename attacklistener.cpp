#include "attacklistener.h"
#include "game.h"

AttackListener::AttackListener(Game *game)
{
    this->game = game;
}

void AttackListener::run(void *)
{
    game->hurtEnemy();
}
