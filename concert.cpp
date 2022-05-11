#include "concert.h"


concert::concert(int pret, bool bratara_food, int zona) :
    pret(pret), bratara_food(bratara_food), zona(zona)
{}

void concert::Postpone(){
    //se schimba si zona si ora
    zona -= 1;
    if (zona < 0)
        zona = 1;
    std::cout << "Concert amanat.\n";
}

void concert::restart(){
    zona += 1;
    if (zona > 3)
        zona = 1;
}
std::ostream &operator << (std::ostream &os, const concert &c){
    os << "Nr. Concert: " << c.zona << ". Pret: " << c.pret <<".\n";
    return os;
}

void concert::setPret(int p){
    this->pret = p;
}



