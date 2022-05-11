#include "festival.h"
#include "concert_artist.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>


festival* festival::f = nullptr;

festival::festival() : nume("festival 2019"), locatie("elvetia"), oameni(789){
}
festival::~festival(){
	for(int i = 0; i < nr_concert; ++i){
		delete p[i];
		p[i] = nullptr;
	}
	p.clear();
}
//----------------------------------------------------------


void festival::InitPath(){
    imagini[1][0] = "photos/festival1.jpeg";
	imagini[1][1] = "photos/festival2.png";
	imagini[1][2] = "photos/festival3.jpeg";
	imagini[1][3] = "photos/festival4.jpeg";
	imagini[1][4] = "photos/festival5.jpeg";
	imagini[1][5] = "photos/festival6.jpeg";
	imagini[1][6] = "photos/festival6.jpeg";

	imagini[2][0] = "photos/food1.jpeg";
	imagini[2][1] = "photos/food2.jpeg";
	imagini[2][2] = "photos/food8.jpeg";
	imagini[2][3] = "photos/food4.jpeg";
	imagini[2][4] = "photos/food5.jpeg";
	imagini[2][5] = "photos/food6.jpeg";
	imagini[2][6] = "photos/food7.jpeg";
}


void festival::Postpone_f(int nr){
	p[nr]->Postpone();
}

void festival::restart_f(int nr){
    p[nr]->restart();
}

std::ostream &operator <<(std::ostream &out, const festival &f){
	out << "Festival: " << f.nume << ". Locatie: " << f.locatie;
    out << ". Orar: \n";
    for (int i = 0; i < 3; ++i){
        out << "Ziua " << i + 1 << ": " << f.orar[i] << "  ||  " << f.prices[i] << "\n";
    }
	return out;
}
std::istream &operator >> (std::istream &in, festival &f){
	in >> f.nr_concert >> f.nume >> f.oameni;
	
	return in;
}


//----------------------------------------------------------
void festival::QuestA(){
    std::ifstream fin("quest.txt");
    if (fin.is_open()){
        std::string line, word;
        int total = 0, v[5] = {0, 0, 0, 0};
        while (std::getline(fin, line)){
            std::istringstream ss(line);
            while (ss >> word){
                if (word == "friends"){
                    v[1] += 1;
                    total += 1;
                }
                else if (word == "media"){
                    v[2] += 1;
                    total += 1;
                }
                else if (word == "family"){
                    v[3] += 1;
                    total += 1;
                } else {}
            }
        }
        fin.close();
        if (total != 0) {
            std::cout << "Friends: " << v[1] * 100 / total << "%\n";
            std::cout << "Media: " << v[2] * 100 / total << "%\n";
            std::cout << "Family: " << v[3] * 100 / total << "%\n";
        }
    }
}

void festival::read(){
    std::string song_name;
    std::ifstream fin("concert.txt");
    for (int i = 0; i < 6; ++i){
        auto *con = new concert_artist;
        fin >> *con;
        p.push_back(con);
    }

    while (fin >> nr_concert >> song_name)
        this->AddSong(nr_concert, song_name);

}
//-----------------------------------------------------------------
void festival::AddSong(int nr_artist, const std::string &name){
    try {
        auto *concert_a = dynamic_cast<concert_artist*>(p[nr_artist]);
        concert_a->piese.emplace_back(name);
    }
    catch (std::bad_cast &err){
      std::cout << err.what();
    }

}


void festival::draw(){
    int first = 0, nr = 0, maxt = 0;
    std::string day, result;
    day = "";
	festival::InitPath();

	sf::RenderWindow window(sf::VideoMode(1024, 622), "2019 FESTIVAL", sf::Style::Default);
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	if (!font.loadFromFile("times.ttf")){ std::cout << "Can't find the font file" << std::endl; }

	sf::Texture button1, button2, button3;
	sf::Sprite bi1, bi2, bi3;
	if (!button1.loadFromFile("photos/concert.png"))
		std::cout << "Can't find the image" << std::endl;
	bi1.setPosition(100.0f, 300.0f);
	bi1.setTexture(button1);

	button2.loadFromFile("photos/restaurant.png");
	bi2.setPosition(400.0f, 300.0f);
	bi2.setTexture(button2);

	button3.loadFromFile("photos/bronare.png");
	bi3.setPosition(700.0f, 300.0f);
	bi3.setTexture(button3);

	sf::Texture before, next, options, background, goconcert, gorest, gobronare , day1, day2, day3, unu;
	sf::Sprite b1, n1, o1, back1, gc1, gr1, gb1, d1, d2, d3, poza1;
	before.loadFromFile("photos/back.png");
	b1.setPosition(50.0f, 500.0f);
	b1.setTexture(before);

    day1.loadFromFile("photos/day1.png");
    d1.setPosition(120.0f, 300.0f);
    d1.setTexture(day1);

    day2.loadFromFile("photos/day2.png");
    d2.setPosition(420.0f, 300.0f);
    d2.setTexture(day2);

    day3.loadFromFile("photos/day3.png");
    d3.setPosition(720.0f, 300.0f);
    d3.setTexture(day3);

	next.loadFromFile("photos/next.png");
	n1.setPosition(900.0f, 500.0f);
	n1.setTexture(next);

	options.loadFromFile("photos/options.png");
	o1.setPosition(410.0f, 50.0f);
	o1.setTexture(options);

	background.loadFromFile("photos/white.jpg");
	back1.setTexture(background);
	gc1.setPosition(145.0f, 200.0f);
	
	gobronare.loadFromFile("photos/gobronare.png");
	gb1.setTexture(gobronare);
	gb1.setPosition(660.0f, 200.0f);

	sf::Text startText, nume1, book, book1;
	startText.setFont(font);
	startText.setStyle(sf::Text::Bold);
	startText.setString(nume + " Preview 2019");
	startText.setFillColor(sf::Color::White);
	startText.setCharacterSize(64);
	startText.setPosition(220.0f, 100.0f);

    std::ifstream fin("unu.txt");
    fin >> result;
    nume1.setFont(font);
    nume1.setStyle(sf::Text::Bold);
    nume1.setString("Welcome, " + result + "!");
    nume1.setFillColor(sf::Color(30,144,255));
    nume1.setCharacterSize(64);
    nume1.setPosition(180.0f, 60.0f);

    book.setStyle(sf::Text::Bold);
    book.setString("Choose the day concert you want to attend:");
    book.setFont(font);
    book.setFillColor(sf::Color::White);
    book.setCharacterSize(37);
    book.setPosition(100.0f, 170.0f);

    book1.setStyle(sf::Text::Bold);
    book1.setFont(font);
    book1.setFillColor(sf::Color(0, 199, 127));
    book1.setCharacterSize(37);
    book1.setPosition(50.0f, 400.0f);

    std::ofstream fo("quest.txt", std::ios::app);

  	while (window.isOpen()){
		sf::Event Event{};
		while (window.pollEvent(Event)){ 
            if (Event.type == sf::Event::Closed)
                window.close();
            if (Event.type == sf::Event::MouseMoved){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
//                hover pe buton, se schimba culoarea
                if (first == 0){
                    if (bi1.getGlobalBounds().contains(mousePosF))
                        bi1.setColor(sf::Color(255, 244, 206));
                    else
                        bi1.setColor(sf::Color::White);
                    if (bi2.getGlobalBounds().contains(mousePosF))
                        bi2.setColor(sf::Color(255, 244, 206));
                    else
                        bi2.setColor(sf::Color::White);
                    if (bi3.getGlobalBounds().contains(mousePosF))
                        bi3.setColor(sf::Color(255, 244, 206));
                    else
                        bi3.setColor(sf::Color::White);
                }

            }
            if (Event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (first == 0){
//                    click pe butonul 'concert', 'restaurant' sau 'book'
                    if (bi1.getGlobalBounds().contains(mousePosF)){
                        nr = 0;
                        first = 1;
                        unu.loadFromFile(imagini[first][0]);
                        poza1.setPosition(250.0f, 0.0f);
                        poza1.setTexture(unu);
                    } else if (bi2.getGlobalBounds().contains(mousePosF)){
                        first = 2;
                        unu.loadFromFile(imagini[first][0]);
                        poza1.setPosition(250.0f, 0.0f);
                        poza1.setTexture(unu);
                        nr = 0;
                    } else if (bi3.getGlobalBounds().contains(mousePosF)){
                        first = 3;
                        nr = 7;
                    }
                } else if (nr < 6 && first != 3){
//                    back si next la poze + afisarea pozelor
                    if (b1.getGlobalBounds().contains(mousePosF)){
                        if (nr > 0){
                            nr--;
                            unu.loadFromFile(imagini[first][nr]);
                            poza1.setPosition(250.0f, 0.0f);
                            poza1.setTexture(unu);
                        } else if (nr == 0)
                            window.close();
                    } else if (n1.getGlobalBounds().contains(mousePosF)){
                        nr++;
                        unu.loadFromFile(imagini[first][nr]);
                        poza1.setPosition(250.0f, 0.0f);
                        poza1.setTexture(unu);
//                        dupa ultima poza apar iar optiunile
                        if (nr == 6){
                            if (first == 2)
                                goconcert.loadFromFile("photos/goconcert.png");
                            if(first == 1)
                                goconcert.loadFromFile("photos/gorest.png");
                            gc1.setTexture(goconcert);
                        }
                    }
                } else if (nr == 6){
//                    reafisarea pozelor
                    if ((first == 2) && gc1.getGlobalBounds().contains(mousePosF)){
                        nr = 0;
                        first = 1;
                        unu.loadFromFile(imagini[first][0]);
                        poza1.setPosition(250.0f, 0.0f);
                        poza1.setTexture(unu);
                    } else
                    if ((first == 1) && gc1.getGlobalBounds().contains(mousePosF)){
                        first = 2;
                        unu.loadFromFile(imagini[first][0]);
                        poza1.setPosition(250.0f, 0.0f);
                        poza1.setTexture(unu);
                        nr = 0;
                    } else
                    if (gb1.getGlobalBounds().contains(mousePosF)){
                        first = 3;
                        nr = 7;
                    }
//                    bronare bilet
                } else if (nr == 7){
                    if (d1.getGlobalBounds().contains(mousePosF)){
                        day = "day 1";
                    } else if (d2.getGlobalBounds().contains(mousePosF)){
                        day = "day 2";
                    } else if (d3.getGlobalBounds().contains(mousePosF)){
                        day = "day 3";
                    }
                    if ((d1.getGlobalBounds().contains(mousePosF)) || (d2.getGlobalBounds().contains(mousePosF)) || (d3.getGlobalBounds().contains(mousePosF))) {
                        maxt++;
                        if (maxt == 2) {
                            fo.close();
                            window.close();
                            std::cout << "You can not book more than 1 ticket.\n";
                        }
                        fo << day;
                        oameni--;
                        book1.setString(
                                "You have successfully booked your ticket!\nThere are still " +
                                std::to_string(oameni) + " tickets available for this concert.");
                    }
                    fo << "\n";
                }
            }
    	}
		window.clear();
		if (first == 0){
			window.draw(startText);
			window.draw(bi1);
			window.draw(bi2);
			window.draw(bi3);
		} else if (nr < 6){
			window.draw(poza1);
			window.draw(b1);
			window.draw(n1);
		} else if (nr == 6){
			window.draw(back1);
			window.draw(gc1);
			window.draw(gb1);
			window.draw(o1);
		} else if (nr == 7){
			window.draw(nume1);
            window.draw(book);
            window.draw(d1);
            window.draw(d2);
            window.draw(d3);
            if (!day.empty())
                window.draw(book1);
        }
		window.display();
  	}
}