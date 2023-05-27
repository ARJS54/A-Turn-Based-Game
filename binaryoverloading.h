#ifndef BINARYOVERLOADING_H
#define BINARYOVERLOADING_H

#include <iostream>

using namespace std;

//5.Binary Operator Overloading
class BinaryOverloading
{
int people = 1;
int chips = 100/people;
int happiness = chips;
public:
    BinaryOverloading();
    bool iWantChips();
    int getPeople();
    void setPeople(int meaniesTakingMyChips);
    BinaryOverloading operator+(const BinaryOverloading& b){
        BinaryOverloading bin;
        bin.people = this->people + b.people;
        bin.chips = this->chips/bin.people;
        bin.happiness = this->chips;
        return bin;
    }
};

#endif // BINARYOVERLOADING_H
