#include "characterdeathlistener.h"

#include "eventmanager.h"
#include "game.h"

CharacterDeathListener::CharacterDeathListener(Game *game)
{
    this->game = game;
}

void CharacterDeathListener::run(void *args)
{
    if (game->is_over()) {
        return;
    }

    Character *character = (Character *) args;

    if (character->getName() == game->getPlayer().getName()) {
        EventManager::getInstance().trigger("defeat");
    }
}
