#include "golistener.h"

#include<iostream>
#include<vector>

#include "game.h"

GoListener::GoListener(Game *game)
{
    this->game = game;
    direction  = "";
}

void GoListener::run(void *args_ptr)
{
    if (game->is_over()) {
        return;
    }

    vector<string> *args = (vector<string> *) args_ptr;

    if (args->size() > 1) {
        game->go(args->at(1));
    } else {
        cout << "Need a direction!" << endl;
    }
}
