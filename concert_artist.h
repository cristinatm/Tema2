#ifndef CONCERT_ARTIST_H
#define CONCERT_ARTIST_H

#include "concert.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class concert_artist : public concert{

    std::vector<std::shared_ptr<concert>> chestii;
    std::string artist;
    double ora{};
    std::vector <std::string> piese;
    bool acces_culise{};

public:
    concert_artist();
    concert_artist(const std::string &artist, double ora, bool acces_culise);
	~concert_artist() override = default;
    concert_artist(const concert_artist& c);
    concert_artist& operator=(concert_artist&&) = default;

    void Postpone() override;
    friend void swap(concert_artist& c1, concert_artist& c2);
    std::shared_ptr <concert> clone() const override;
    friend std::ostream &operator << (std::ostream &os, const concert_artist &c);
    friend std::istream &operator >> (std::istream &in, concert_artist &c);
    concert_artist& operator=(const concert_artist& other);
    friend class festival;

};

#endif // CONCERT_ARTIST_H
