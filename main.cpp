#include<cstdlib> // EXIT_SUCCESS macro.

#include "eventmanager.h"
#include "game.h"
#include "inheritanceboi.h"
#include "inputlistener.h"
#include "overloading.h"
#include "binaryoverloading.h"
#include "dispatch.h"
#include "dispatchthesecondcoming.h"

//3.Template
template<typename T>
void MyMin(T x, T y){
    if (x > y){
        cout << "The minimum value is " << y << endl;
    } else {
        cout << "The minimum value is " << x << endl;;
    }
}

template<typename T>
void templateMan(T value){
std::cout << value << endl;
}

int main()
{
    //10.Dynamic and Static Dispatch
    Dispatch baseForm;
    Dispatch *baseFormPTR = new DispatchTheSecondComing();
    DispatchTheSecondComing SSJ3;
    //Dynamic Dispatch
    baseFormPTR->print();
    //Static Dispatch
    baseForm = SSJ3;
    baseForm.print();
    BinaryOverloading starPlatinum;
    starPlatinum.getPeople();
    starPlatinum = starPlatinum + starPlatinum;
    starPlatinum.getPeople();
    Overloading legendarySuperSaiyan(10,0,10);
    legendarySuperSaiyan.toString();
    ++legendarySuperSaiyan;
    legendarySuperSaiyan.toString();
    MyMin(5.5, 6.4);
    MyMin(4, 50);
    templateMan("ZA WARUDO");
    templateMan(59);
    templateMan(5.9);
    InheritanceBoi Inheritance;
    Game game;
    EventManager::getInstance().listen("input", new InputListener(&game));
    EventManager::getInstance().event_loop();
    return EXIT_SUCCESS;
}
