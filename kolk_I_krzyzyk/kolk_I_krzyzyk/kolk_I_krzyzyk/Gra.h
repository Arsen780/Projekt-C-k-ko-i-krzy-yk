#pragma once
#include "Menu.h"
#include "Komputer_latwy.h"
#include "Gracz.h"
#include "Plansza.h"
#include <SFML/Graphics.hpp>
#include "Komputer_trudny.h"

using namespace sf;
using namespace std;

class Gra
{
public:
	Gra(RenderWindow& window, int poziomTrudnosci);
	void run();
private:
	RenderWindow& window;
	Plansza plansza;
	Gracz gracz;
	Komputer_latwy komputer_latwy;
	int poziomTrudnosci;
};

