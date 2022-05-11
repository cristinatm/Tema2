#ifndef CONCERT_ALL_H
#define CONCERT_ALL_H
#include "concert.h"

class concert_all : public concert{
    std::string nume;
    std::vector <std::string> artisti;
    bool acces_culise{};
    std::vector<std::shared_ptr<concert>> concerte_all;


public:
    concert_all();
    ~concert_all() override = default;
    concert_all(const concert_all& c);
    concert_all& operator=(concert_all&&) = default;

    friend void swap(concert_all& c1, concert_all& c2);
    std::shared_ptr <concert> clone() const override;
    friend std::ostream &operator << (std::ostream &os, const concert_all &c);
    concert_all& operator=(const concert_all& other);
    friend class festival;

};


#endif //CONCERT_ALL_H
