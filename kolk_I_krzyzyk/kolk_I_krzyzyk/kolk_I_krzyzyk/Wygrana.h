#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class Wygrana
{
public:
    Wygrana(RenderWindow& window);
    void run();
private:
    RenderWindow& window;
    Font czcionka;
    Text napis;
    void handleEvents();
    void rysuj();
};
