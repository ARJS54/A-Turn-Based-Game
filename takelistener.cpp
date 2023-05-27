#include "takelistener.h"

#include<iostream>
#include<vector>

#include "game.h"

TakeListener::TakeListener(Game *game)
{
    this->game = game;
    itemToTake = "";
}

void TakeListener::run(void *args_ptr)
{
    vector<string> *args = (vector<string> *) args_ptr;

    if (args->size() > 1) {
        game->takeItem(args->at(1));
    } else {
        cout << "Need an item name!" << endl;
    }


}
