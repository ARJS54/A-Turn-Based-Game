#include "defeatlistener.h"

#include<iostream>

#include "game.h"

// DefeatListener.cpp
DefeatListener::DefeatListener(Game *game)
{
    this->game = game;
}

void DefeatListener::run(void *)
{
    cout << endl;
    cout << "Defeat!" << endl;
    game->setOver(true);
}
