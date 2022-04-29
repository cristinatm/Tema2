//
// Created by cristina on 29.04.2022.
//

#ifndef INC_22APRIL_EROARE_H
#define INC_22APRIL_EROARE_H
#include <iostream>

class eroare : public std::invalid_argument{
public:
    explicit eroare(const std::string &arg) : invalid_argument(arg){}
};
class eroare_mail : public eroare{
public:
    explicit eroare_mail(const std::string &arg) : eroare(arg){}
};


class eroare_age : public eroare{
public:
    explicit eroare_age(const std::string &arg) : eroare(arg){}
};


#endif //INC_22APRIL_EROARE_H
