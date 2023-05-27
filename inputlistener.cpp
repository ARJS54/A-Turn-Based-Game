#include "inputlistener.h"

// If you're only using something in the ".cpp" file,
// there's no need to include it in the ".h" file.
#include "eventmanager.h"

// Now we include game, as we need to use the
// update_screen() member of the class.
#include "game.h"

InputListener::InputListener(Game *game)
{
    this->game = game;
}

void InputListener::run(void *args_ptr)
{
    // Let's make this thing a bit safer by "translating" the pointer back to what we expect
    // This is exactly what makes this "void *" pointer dangerous.
    vector<string> *args = (vector<string> *) args_ptr;

    EventManager &eventManager = EventManager::getInstance();

    if (args->size() > 0) {
        // If arg[0] is "input", we are going to ignore the input.
        // If we do not ignore the input, it's an infinite loop.
        if (args->at(0) == "input") {
            return;
        }

        eventManager.trigger(args->at(0), args);

        if (eventManager.is_running()) {
            game->update_screen();
        }
    } else {
        eventManager.trigger("no_command", nullptr);
    }
}
