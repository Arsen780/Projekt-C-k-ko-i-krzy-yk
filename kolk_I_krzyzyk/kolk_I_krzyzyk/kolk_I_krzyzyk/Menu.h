#pragma once
#include "SFML/Graphics.hpp"
#include "Komputer_trudny.h"
#include "Komputer_latwy.h"

using namespace sf;
using namespace std;

class Menu
{
public:
	Menu(RenderWindow& window);
	void run();
	int getWybranyPoziom() const { return wybranyPoziom; }
private:
	RenderWindow& window;
	Font czcionka;
	Text tytul;
	Text przycisk_latwy_poziom;
	Text przycisk_trudny_poziom;
	void rysuj();
	void handleEvents();
	int wybranyPoziom;
};

