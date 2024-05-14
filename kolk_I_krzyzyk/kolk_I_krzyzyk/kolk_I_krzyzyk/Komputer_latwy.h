#pragma once
#include "Plansza.h"

class Komputer_latwy
{
public:
	Komputer_latwy(char symbol);
	void ruch(Plansza& plansza);
private:
	char symbol;
	const int rozmiar_planszy = 11;
};

