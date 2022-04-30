#ifndef CONCERT_H
#define CONCERT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class concert {
protected:
	int pret;
	bool bratara_food;
	int zona; //zona depinde de ziua 1/2/3

    concert(const concert& other) = default;
    concert& operator=(const concert& c) = default;
public:
    virtual std::shared_ptr <concert> clone() const = 0;
    explicit concert(int pret=50, bool bratara_food=false, int zona=1);
	virtual ~concert() = default;
	virtual void Postpone();
	void reStart();
    friend std::ostream &operator << (std::ostream &os, const concert &c);
    void setPret(int p);
};


#endif //CONCERT_H
