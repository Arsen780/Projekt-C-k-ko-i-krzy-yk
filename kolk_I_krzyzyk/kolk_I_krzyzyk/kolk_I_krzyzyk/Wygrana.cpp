#include "Wygrana.h"
#include <iostream>

using namespace sf;
using namespace std;

Wygrana::Wygrana(RenderWindow& window) : window(window)
{
    setlocale(LC_CTYPE, "Polish");

    if (!czcionka.loadFromFile("Fonts/Bitter-Regular.ttf"))
    {
        cerr << "Nie za³adowano czcionki!" << endl;
    }

    napis.setFont(czcionka);
    napis.setString(L"WYGRA£ GRACZ X");
    napis.setCharacterSize(25);
    napis.setFillColor(Color::Black);
    napis.setOrigin(napis.getGlobalBounds().width/2,napis.getGlobalBounds().height/2);
    float szerokosc_okna = static_cast<float>(window.getSize().x);
    float wysokosc_okna = static_cast<float>(window.getSize().y);
    napis.setPosition(szerokosc_okna / 2.0f, wysokosc_okna / 2.0f);
}

void Wygrana::rysuj()
{
    window.clear(Color::White);
    window.draw(napis);
    window.display();
}

void Wygrana::run() {
    while (window.isOpen()) {
        handleEvents();
        rysuj();
    }
}

void Wygrana::handleEvents()
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
