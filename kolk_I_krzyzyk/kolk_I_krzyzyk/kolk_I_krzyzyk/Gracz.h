#pragma once
#include "Plansza.h"
#include <SFML/Graphics.hpp>
#include "Komputer_trudny.h"
class Gracz
{
public:
	Gracz(char symbol);
	bool ruch(Plansza& plansza);

private:
	char symbol;
};


