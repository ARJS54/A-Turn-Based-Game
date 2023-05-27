#ifndef OLDMAN_H
#define OLDMAN_H

#include<iostream>
//7.Virtual functions and polymorphism
using namespace std;

class OldMan
{
public:
    OldMan();
    virtual void goodBoi(int memes);
    void goodBoi(int memes, int leMemes);
};

#endif // OLDMAN_H
