#include <iostream>
#include <fstream>
#include <string>
#include "festival.h"
#include "concert_artist.h"
#include "user.h"


void postp(int nr){
    auto f = festival::get_festival();
    f->Postpone1(nr);
}

int main(){
    user u;
	auto f = festival::get_festival();
    concert_artist c("eu", 15, true);
    c.setPret(175);

    std::ifstream fin("festival.txt");
    fin >> *f;
    f->read();
    postp(1);
    f->reStart1(1);
    f->AddSong(2, "lights out!");
    std::cin >> u;
    u.Quest();
    f->draw();
    festival::QuestA();
    return 0;
}