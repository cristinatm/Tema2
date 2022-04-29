#include "concert.h"
#include <iostream>
#include <string>

concert::concert(int pret, bool bratara_food, int zona) :
    pret(pret), bratara_food(bratara_food), zona(zona)
{}

void concert::Postpone(){
    //se schimba si zona/scena
    zona -= 10;
    std::cout << "inchis\n";
}

void concert::reStart(){
    zona += 10;
}
std::ostream &operator << (std::ostream &os, const concert &c){
    os << "Concert: " << c.zona << ". Pret: " << c.pret <<".\n";
    return os;
}




