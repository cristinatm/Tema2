#include "user.h"
#include "eroare.h"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>


user::user(std::string lastname, std::string firstname, std::string email, int age) :
    lastname(std::move(lastname)), firstname(std::move(firstname)), email(std::move(email)), age(age){}

std::ostream &operator<<(std::ostream &out, const user &u) {
	out << "User: " << u.lastname << " " << u.firstname << ". Email: ." << u.email << "Age: "<< u.age << ".\n";
	return out;
}

std::istream &operator>>(std::istream &in, user &u) {
	std::string email;
    int age;
	std::cout << "Please enter your first and last name: ";
	in >> u.firstname >> u.lastname;
	std::cout << "Please enter your email: ";

	while (true) {
		in >> email;
			if (email.find('@') >= email.length())
				std::cout <<"Invalid input! Please enter a real email.\n";
			break;
	}
	u.email = email;
	std::cout << "Please enter your age: ";
    while (true){
        in >> age;
            if (age <= 0)
                std::cout << "Invalid input! Your age should be greater than zero.\n";
            break;
    }
    u.age = age;
	return in;
}


void user::Quest(){
    std::string ans, name, fname;
    std::ofstream fout("quest.txt", std::ios::app);

    std::cout << "Where did you find out about our festival?\n";
    std::cout << "1) friends.   2) media.  3)family.\n";
    while (true){
        std::cin >> ans;
        if (ans != "friends" && ans != "media" && ans != "family")
            std::cout << "Choose one of the options from above.\n";
        else
            break;
    }
    if (age < 16){
        std::cout << "All under 16’s must be accompanied by an adult ticket holder, (parent or guardian) who is over 18 years old.\n";
        std::cout << "Please introduce the following information:\n";
        std::cout << "Adult's firstname: ";
        std::cin >> fname;
        std::cout << "Adult's lastname: ";
        std::cin >> name;
    }
	fout << firstname + " " + lastname << " " << ans << " ";
    if (age < 16)
        fout << age << " " << name << " " << fname;

    std::ofstream fout1("unu.txt");
    fout1 << firstname;
    fout1.close();
    fout.close();
}