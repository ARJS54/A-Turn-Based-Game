#ifndef OVERLOADING_H
#define OVERLOADING_H

#include <iostream>
using namespace std;

//4.Unary Operator Overloading
class Overloading
{
    int x;
    int z;
    int y;
public:
                    //10.Initializer List
    Overloading() : x(0), z(0), y(0){}
    Overloading(int X, int Z, int Y) : x(X), z(Z), y(Y) {}
    void toString();
    Overloading operator++();


};

#endif // OVERLOADING_H
