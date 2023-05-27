#include "oldman.h"

OldMan::OldMan()
{
    goodBoi(24);
}

//7.Virtual functions and polymorphism
void OldMan::goodBoi(int memes)
{
    std::cout << "The number is " << memes << endl;
}

void OldMan::goodBoi(int memes, int leMemes){
    std::cout << "the number is not " << memes << " but it is " << leMemes << endl;
}
