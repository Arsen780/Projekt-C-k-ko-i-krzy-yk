#include <iostream>
#include "SFML/Graphics.hpp"
#include "Gra.h"
#include "Gracz.h"
#include "Plansza.h"

using namespace sf;
using namespace std;

Gracz::Gracz(char symbol) : symbol(symbol){}

bool Gracz :: ruch(Plansza & plansza)
{
	int wiersz, kolumna;
	cin >> wiersz >> kolumna;

	if (wiersz < 0 || kolumna >= plansza.jaki_rozmiar() || kolumna < 0 || kolumna >= plansza.jaki_rozmiar())
	{
		return false;
	}

	if (!plansza.ruch(wiersz, kolumna, symbol)) {
		return false;
	}
	return true;
}
