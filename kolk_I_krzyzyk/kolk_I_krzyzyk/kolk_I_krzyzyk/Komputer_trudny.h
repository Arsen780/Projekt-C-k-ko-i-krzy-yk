#pragma once
#include "Plansza.h"

class Komputer_trudny
{
public:
    Komputer_trudny(char symbol);
    void ruch(Plansza& plansza);

private:
    char symbol;
    const int rozmiar_planszy = 11;
    bool sprawdz_pion(Plansza& plansza);
    bool sprawdz_poziom(Plansza& plansza);
    bool sprawdz_skos1(Plansza& plansza);
    bool sprawdz_skos2(Plansza& plansza);
    bool sprawdz_pion_atak(Plansza& plansza);
    bool sprawdz_poziom_atak(Plansza& plansza);
    bool sprawdz_skos1_atak(Plansza& plansza);
    bool sprawdz_skos2_atak(Plansza& plansza);
    void pollosowy(Plansza& plansza);
    bool atak(Plansza& plansza);
    bool obrona(Plansza& palnsza);
};
