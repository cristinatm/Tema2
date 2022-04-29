#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>


class user {
	std::string lastname, firstname;
	std::string email; 
    int age;
public:
    explicit user(std::string lastname="-", std::string firstname="-", std::string email="-", int age=18);
    virtual ~user() = default;
    void Quest();
    friend std::ostream &operator<<(std::ostream &out, const user &u);
    friend std::istream &operator>>(std::istream &in, user &u);

};

#endif //USER_H
