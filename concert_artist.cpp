#include "concert_artist.h"
#include "eroare.h"
#include <iostream>
#include <string>
#include <algorithm>

concert_artist::concert_artist(const std::string &artist, double ora, bool acces_culise) : concert(){
    if (ora > 24)
        throw eroare_constr("Constructor invalid. Ora invalida\n");
    else this->ora = ora;
    this->acces_culise = acces_culise;
    this->artist = artist;
}

void concert_artist::Postpone(){
//    std::cout << "The concert will be postponed for an hour.\n";
    //se schimba si zona si ora
    ora += 1;
}

std::ostream &operator<< (std::ostream &os, const concert_artist &c){
    os << "Concert: " << c.artist << ". \nAcces culise: " << c.acces_culise << "\n";
    os << "Pret: " << c.pret << "\n";
    os << "Ora: " << c.ora << "\n";
    os << "Zona: " << c.zona << "\n";
    os << "Piese: \n";
    for (auto const &piesa: c.piese){
        os << "\t" << piesa << "\n";
    }
    os << "\n---------------------------------------------\n";
    return os;
}

std::istream &operator>> (std::istream &in, concert_artist &c) {
	in >> c.artist >> c.zona >> c.acces_culise >> c.ora;
	return in;
}

concert_artist::concert_artist(const concert_artist& c) : concert(c) {
    zona = c.zona;
    pret = c.pret;
    bratara_food = c.bratara_food;
    std::for_each(c.concerte.begin(), c.concerte.end(), [&](auto &chestie){ concerte.push_back(chestie->clone()); });
}

std::shared_ptr<concert> concert_artist::clone() const {
    return std::make_shared <concert_artist>(*this);
}

void swap(concert_artist& c1, concert_artist& c2){
    using std::swap;
    swap(c1.concerte, c2.concerte);
}
concert_artist& concert_artist::operator=(const concert_artist& other) {
    auto copie{other};
    swap(copie, *this);
    return *this;
}

concert_artist::concert_artist() : concert(){
    ora = 16;
    acces_culise = false;
}