#include "concert_artist.h"
#include <iostream>
#include <string>
#include <algorithm>

concert_artist::concert_artist() : concert(){
    ora = 16;
    acces_culise = false;
}

void concert_artist::Postpone(){
//    std::cout << "The concert will be postponed for an hour.\n";
    ora += 1;
}

std::ostream &operator << (std::ostream &os, const concert_artist &c){
    os << "Concert: " << c.artist << ". Acces culise: " << c.acces_culise << "\n";
    return os;
}

std::istream &operator>>(std::istream &in, concert_artist &c) {
	in >> c.artist >> c.zona;
	return in;
}

concert_artist::concert_artist(const concert_artist& c) : concert(c) {
    zona = c.zona;
    pret = c.pret;
    bratara_food = c.bratara_food;
//    for (const auto &chestie: c.chestii)
//        chestii.push_back(chestie->clone());
    std::for_each(c.chestii.begin(), c.chestii.end(), [&](auto &chestie){ chestii.push_back(chestie->clone()); });



}

std::shared_ptr<concert> concert_artist::clone() const {
    return std::make_shared <concert_artist>(*this);
}


void swap(concert_artist& c1, concert_artist& c2){
    using std::swap;
    swap(c1.chestii, c2.chestii);
}
concert_artist& concert_artist::operator=(const concert_artist& other) {
    auto copie{other};
    swap(copie, *this);
    return *this;
}

