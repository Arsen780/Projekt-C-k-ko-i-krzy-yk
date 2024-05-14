#include <iostream>
#include "SFML/Graphics.hpp"
#include "Menu.h"
#include <locale.h>

using namespace std;
using namespace sf;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    RenderWindow window(VideoMode(660, 660), L"Kó³ko i krzy¿yk");
    Menu menu(window);
    menu.run();

    return 0;
}

