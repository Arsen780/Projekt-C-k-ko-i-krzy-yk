#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Plansza
{
public:
	Plansza(int rozmiar);
	void rysuj(RenderWindow& window);
	bool ruch(int wiersz, int kolumna, char symbol);
	char check_winner();
	bool czy_pelna();
	int jaki_rozmiar() const;
	char getElement(int i, int j) const;

private:
	vector<vector<char>> plansza;
	int rozmiar;
	const float rozmiar_komorki = 60.0f;
	Texture tekstura_kolo;
	Texture tekstura_krzyzyk;
	void wczytaj_tekstury();
};

