#include "victorylistener.h"

#include<iostream>

#include "game.h"

VictoryListener::VictoryListener(Game *game)
{
    this->game = game;
}

void VictoryListener::run(void *)
{
    cout << endl;
    cout << "Victory!" << endl;
    game->setOver(true);
}
