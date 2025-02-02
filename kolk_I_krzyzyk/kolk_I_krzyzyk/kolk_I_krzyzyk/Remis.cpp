#include "Remis.h"
#include <iostream>

using namespace sf;
using namespace std;

Remis::Remis(RenderWindow& window) : window(window)
{


    if (!czcionka.loadFromFile("Fonts/Bitter-Regular.ttf"))
    {
        cerr << "Nie załadowano czcionki!" << endl;
    }

    napis.setFont(czcionka);
    napis.setString("REMIS");
    napis.setCharacterSize(25);
    napis.setFillColor(Color::Black);
    napis.setOrigin(napis.getGlobalBounds().width / 2, napis.getGlobalBounds().height / 2);
    float szerokosc_okna = static_cast<float>(window.getSize().x);
    float wysokosc_okna = static_cast<float>(window.getSize().y);
    napis.setPosition(szerokosc_okna / 2.0f, wysokosc_okna / 2.0f);
}

void Remis::rysuj()
{
    window.clear(Color::White);
    window.draw(napis);
    window.display();
}

void Remis::run() {
    while (window.isOpen()) {
        handleEvents();
        rysuj();
    }
}

void Remis::handleEvents()
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
        }
        else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
        {
            if (event.mouseButton.x >= window.getSize().x - 20 && event.mouseButton.y <= 20)
            {
                window.close();
            }
        }
    }
}

