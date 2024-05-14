#include <iostream>
#include "SFML/Graphics.hpp"
#include "Gra.h"
#include "Komputer_latwy.h"
#include "Komputer_trudny.h"
#include "Wygrana.h"
#include <Windows.h>
#include "Przegrana.h"
#include "Remis.h"

using namespace sf;
using namespace std;

Gra::Gra(RenderWindow& window, int poziomTrudnosci) : window(window), plansza(11), gracz('X'), komputer_latwy('O'), poziomTrudnosci(poziomTrudnosci) {}

void Gra::run()
{
    setlocale(LC_CTYPE, "Polish");

    Komputer_trudny komputer_trudny('O');

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int wiersz = event.mouseButton.y / (660 / 11);
                    int kolumna = event.mouseButton.x / (660 / 11);

                    if (plansza.ruch(wiersz, kolumna, 'X'))
                    {
                        if (plansza.check_winner() == 'X')
                        {
                            cout << L"Gracz X wygra³!" << endl;
                            window.close();
                            RenderWindow window(VideoMode(400, 250), "WYNIK");
                            Wygrana wygrana(window);
                            wygrana.run();
                        }
                        else if (plansza.czy_pelna())
                        {
                            cout << L"Remis!" << endl;
                            window.close();
                            RenderWindow window(VideoMode(400, 250), "WYNIK");
                            Remis remis(window);
                            remis.run();
                        }
                        else
                        {
                            if (poziomTrudnosci == 1)
                            {
                                komputer_latwy.ruch(plansza);
                            }
                            else if (poziomTrudnosci == 2)
                            {
                                komputer_trudny.ruch(plansza);
                            }

                            if (plansza.check_winner() == 'O')
                            {
                                cout << L"Gracz O wygra³!" << endl;
                                window.close();
                                RenderWindow window(VideoMode(400, 250), "WYNIK");
                                Przegrana przegrana(window);
                                przegrana.run();
                            }
                            else if (plansza.czy_pelna())
                            {
                                cout << L"Remis!" << endl;
                                window.close();
                                RenderWindow window(VideoMode(400, 250), "WYNIK");
                                Remis remis(window);
                                remis.run();
                            }
                        }
                    }
                }
            }
        }

        window.clear(Color::White);
        plansza.rysuj(window);
        window.display();
    }
}
