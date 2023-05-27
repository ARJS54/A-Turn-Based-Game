#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

// EventListener.h
/** Parent class of all listeners. (It is abstract and can't be instantiated) */
class EventListener
{
public:
    // "void *" is a generic pointer to anything!
    // 10x worse than regular pointers in potential problems
    virtual void run(void *args) = 0;
};

#endif // EVENTLISTENER_H
