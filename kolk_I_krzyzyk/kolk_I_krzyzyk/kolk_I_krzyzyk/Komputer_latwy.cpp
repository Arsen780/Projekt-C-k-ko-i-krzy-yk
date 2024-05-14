#include <iostream>
#include "SFML/Graphics.hpp"
#include "Gra.h"
#include "Komputer_latwy.h"
#include "Plansza.h"


using namespace sf;
using namespace std;

Komputer_latwy::Komputer_latwy(char symbol):symbol(symbol){}

void Komputer_latwy::ruch(Plansza& plansza)
{
    int wiersz, kolumna;
    bool licznik_blokowan = false;

    do {
        wiersz = rand() % rozmiar_planszy;
        kolumna = rand() % rozmiar_planszy;

        if (plansza.getElement(wiersz, kolumna) == ' ')
        {
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int nowy_wiersz = wiersz + i;
                    int nowa_kolumna = kolumna + j;

                    if (nowy_wiersz >= 0 && nowy_wiersz < rozmiar_planszy && nowa_kolumna >= 0 && nowa_kolumna < rozmiar_planszy &&
                        plansza.getElement(nowy_wiersz, nowa_kolumna) != ' ')
                    {
                        plansza.ruch(wiersz, kolumna, 'O');
                        licznik_blokowan = true;
                    }
                }
            }
        }

    } while (licznik_blokowan == 0);

}