#include "overloading.h"

//4.Unary Operator Overloading
void Overloading::toString(){
cout << "The three values are " << x << ", " << y << " and " << z << endl;
}

Overloading Overloading::operator++()
{
    return Overloading(++(this->x),++(this->y),++(this->z));
}
