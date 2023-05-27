#include "binaryoverloading.h"

//5.Binary Operator Overloading

BinaryOverloading::BinaryOverloading()
{

}

bool BinaryOverloading::iWantChips(){
    if (this->chips == 0){
        cout << "I want chips!!!!!" << endl;
        return true;
    } else {
        cout << "Your chips are already mine." << endl;
        return false;
    }
}
int BinaryOverloading::getPeople(){
    cout << "The number of people is " << people << endl;
    return people;
}
void BinaryOverloading::setPeople(int meaniesTakingMyChips){
    this->people = meaniesTakingMyChips;
}

