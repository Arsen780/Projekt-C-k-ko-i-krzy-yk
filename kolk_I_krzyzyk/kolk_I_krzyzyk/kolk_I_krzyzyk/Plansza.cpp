#include <iostream>
#include "SFML/Graphics.hpp"
#include "Plansza.h"


using namespace sf;
using namespace std;

Plansza::Plansza(int rozmiar) : rozmiar(rozmiar) {
    plansza.resize(rozmiar, vector<char>(rozmiar, ' '));
    wczytaj_tekstury();
}

void Plansza::wczytaj_tekstury()
{
    if (!tekstura_kolo.loadFromFile("Texture/kolko.jpg"))
        cerr << "Nie za³adowano tekstury kolka!" << endl;
    if (!tekstura_krzyzyk.loadFromFile("Texture/krzyzyk.jpg"))
        cerr << "Nie za³adowano tekstury krzy¿yka!" << endl;
}

void Plansza::rysuj(RenderWindow& window)
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            RectangleShape cell(Vector2f(rozmiar_komorki, rozmiar_komorki));
            cell.setPosition(j * rozmiar_komorki, i * rozmiar_komorki);
            cell.setOutlineThickness(2);
            cell.setOutlineColor(Color::Black);

            if (plansza[i][j] == 'X')
            {
                cell.setTexture(&tekstura_krzyzyk);
            }
            else if (plansza[i][j] == 'O')
            {
                cell.setTexture(&tekstura_kolo);
            }
            window.draw(cell);
        }
    }
}

bool Plansza::ruch(int wiersz, int kolumna, char symbol) {
    if (wiersz >= 0 && wiersz < rozmiar && kolumna >= 0 && kolumna < rozmiar && plansza[wiersz][kolumna] == ' ')
    {
        plansza[wiersz][kolumna] = symbol;
        return true;
    }
    return false;
}

char Plansza::check_winner() 
{
    for (int i = 0; i < rozmiar; ++i) 
    {
        for (int j = 0; j < rozmiar - 4; ++j) 
        {
            if (plansza[i][j] != ' ' &&
                plansza[i][j] == plansza[i][j + 1] &&
                plansza[i][j] == plansza[i][j + 2] &&
                plansza[i][j] == plansza[i][j + 3] &&
                plansza[i][j] == plansza[i][j + 4])
                return plansza[i][j];

            if (plansza[j][i] != ' ' &&
                plansza[j][i] == plansza[j + 1][i] &&
                plansza[j][i] == plansza[j + 2][i] &&
                plansza[j][i] == plansza[j + 3][i] &&
                plansza[j][i] == plansza[j + 4][i])
                return plansza[j][i];
        }
    }

    for (int i = 0; i < rozmiar - 4; ++i)
    {
        for (int j = 0; j < rozmiar - 4; ++j) 
        {
            if (plansza[i][j] != ' ' &&
                plansza[i][j] == plansza[i + 1][j + 1] &&
                plansza[i][j] == plansza[i + 2][j + 2] &&
                plansza[i][j] == plansza[i + 3][j + 3] &&
                plansza[i][j] == plansza[i + 4][j + 4])
                return plansza[i][j];

            if (plansza[i][j + 4] != ' ' &&
                plansza[i][j + 4] == plansza[i + 1][j + 3] &&
                plansza[i][j + 4] == plansza[i + 2][j + 2] &&
                plansza[i][j + 4] == plansza[i + 3][j + 1] &&
                plansza[i][j + 4] == plansza[i + 4][j])
                return plansza[i][j + 4];
        }
    }

    return ' ';
}

bool Plansza::czy_pelna()
{
    for(int i = 0;i<rozmiar;i++)
        for (int j = 0; j < rozmiar; j++)
        {
            if (plansza[i][j] == ' ')
                return false;
        }
    return true;
}

int Plansza::jaki_rozmiar()const {
    return rozmiar;
}

char Plansza::getElement(int i, int j) const
{
    return plansza[i][j];
}
