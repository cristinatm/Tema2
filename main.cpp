//era un const neinit in constr/ solutie il face ne const/ il initializezi in lista de constr

#include <iostream>
#include <fstream>
#include <string>
#include "festival.h"
#include "concert_artist.h"
#include "user.h"

void postp(int nr){
    auto f = festival::get_festival();
    f->Postpone_f(nr);
}

int main(){
    user u;
	auto f = festival::get_festival();
    try {
        concert_artist c("avicii", 15, true);
        c.setPret(175);
    }
    catch (const std::invalid_argument &err){
        std::cout << err.what();
    }

    std::ifstream fin("festival.txt");
    fin >> *f;
    f->read();
    postp(1);
    f->restart_f(1);
    f->AddSong(2, "lights out!");
    std::cin >> u;
    u.Quest();
    f->draw();
    festival::QuestA();
    return 0;
}