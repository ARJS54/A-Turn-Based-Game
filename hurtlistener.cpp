#include "hurtlistener.h"

#include "eventmanager.h"
#include "game.h"

HurtListener::HurtListener(Game *game)
{
    this->game = game;
}

void HurtListener::run(void *)
{
    cout << "Picking up the cursed item caused you to remember that time you pee'd your pants in primary school. -10 hp" << endl;
    game->player.health -= 10;
}
