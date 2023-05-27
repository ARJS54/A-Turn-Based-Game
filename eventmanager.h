#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include<map>
#include<string>
#include<vector>

#include "eventlistener.h"

using namespace std;

// EventManager.h (Implemented as a Singleton)
/** This class manages the event loop and all the event calls */
struct EventManager // Structs in C++ are the same as classes, but default to "public" instead of "private".
{
    // static inside a class or struct works exactly like in java
    // Only one instance per class.
    static EventManager &getInstance(); // Gets an instance of the class (an object)

    // Making sure I can't have copies of this instance.
    EventManager(EventManager const& copy);            // Not Implemented (Copy constructor)
    EventManager& operator=(EventManager const& copy); // Not Implemented (Assignment operator)

    // Registers an event.
    void listen(string event_name, EventListener *listener);

    // Emits an event
    // "void *" is a generic pointer to anything.
    // !!! Highly unsafe, please don't do this at home without the presence of your parents !!!
    void trigger(string event_name, void *args = nullptr);

    // Returns true if still running
    bool is_running();

    // Stops the event loop
    void stop();

    // Reads the input and calls an input event
    void check_events();

    // constantly checks for new inputs until the program ends.
    void event_loop();

private:
    // True if running
    bool running;

    // map<K, V> is a collection of V's indexed by S.
    // In this case, we have lists/vectors of events indexed by their names.
    map<string, vector<EventListener*>> registeredEvents;

    // Only EventManager can call the constructor, so the only way to get an instance
    // is by calling getInstance.
    EventManager();
};

#endif // EVENTMANAGER_H
