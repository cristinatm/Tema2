#include <iostream>
#include <fstream>
#include <string>
#include "festival.h"
//#include "concert_artist.h"
//#include "concert.h"
#include "user.h"


void postp(int nr){
    auto f = festival::get_festival();
    f->Postpone1(nr);
}


int main(){
    user u;
	auto f = festival::get_festival();
    std::ifstream fin("festival.txt");
    fin >> *f;
    f->read();
    postp(1);
    f->reStart1(1);
    f->AddSong(2, "lights out!");
    std::cin >> u;
    u.Quest();
    f->Start();
    festival::QuestA();
    return 0;
}