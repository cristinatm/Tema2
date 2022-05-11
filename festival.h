#ifndef FESTIVAL_H
#define FESTIVAL_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include "concert.h"
#include "concert_artist.h"

class festival {

private:

	static festival* f;
    std::string imagini[10][10];
    std::string nume;
	std::string orar[3];
    std::string locatie;
    int prices[3]{50, 50, 50};
    int oameni;

	festival();

protected:
	int nr_concert{};
	std::vector<concert*> p;

public:

	~festival();
    static void QuestA();
    void read();
    void AddSong(int nr_concert, const std::string &nume="all i am");
    void draw();
    void InitPath();
	void Postpone_f(int nr);
	void restart_f(int nr);
    friend std::istream &operator >> (std::istream &in, festival &f);
    friend std::ostream &operator <<(std::ostream &out, const festival &f);

    festival(const festival&)=delete;
	festival& operator=(const festival&)=delete;

    static festival* get_festival(){
		if(f == nullptr)
			f = new festival;
		return f;
    }

};

#endif //FESTIVAL_H
