#include "eventmanager.h"

#include<iostream>

/** Converts strings from UPPERCASE or MiXedCasE to lowercase. */
// This is a regular old C-style function not a method.
string tolower(string &s)
{
    string ns;
    for (auto c : s) {
        ns += tolower(c);
    }
    return ns;
}

EventManager::EventManager()
{
    running = true;
}

EventManager &EventManager::getInstance()
{
    // static inside functions creates an instance of this variable for all the calls of this function, and initializes only once.
    static EventManager instance;
    return instance;
}

void EventManager::listen(string event_name, EventListener *listener)
{
    registeredEvents[tolower(event_name)].push_back(listener);
}

void EventManager::trigger(string event_name, void *args)
{
    for (auto listener : registeredEvents[tolower(event_name)]) {
        listener->run(args);
    }
}

bool EventManager::is_running()
{
    return running;
}

void EventManager::stop()
{
    running = false;
}

void EventManager::check_events()
{
    string buffer;
    vector<string> words;

    cout << "> ";               // print prompt
    getline(cin, buffer, '\n');	// read a line from cin to "buffer"
    buffer = tolower(buffer);

    string::size_type pos = 0, last_pos = 0;

    // Break "buffer" up by spaces
    bool finished = false;
    while (!finished) {
        pos = buffer.find_first_of(' ', last_pos);	// find and remember first space.
        if (pos == string::npos ) {			// if we found the last word,
            words.push_back(buffer.substr(last_pos));	// add it to vector "words"
            finished = true;				// and finish searching.
        } else {					// otherwise add to vector and move on to next word.
            words.push_back(buffer.substr(last_pos, pos - last_pos));
            last_pos = pos + 1;
        }
    }

    trigger("input", &words);
}

void EventManager::event_loop()
{
    EventManager &eventManager = EventManager::getInstance();

    while (eventManager.is_running()) {
        eventManager.check_events();
    }
}
