#include "Komputer_trudny.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Plansza.h"

using namespace sf;
using namespace std;

Komputer_trudny::Komputer_trudny(char symbol) : symbol(symbol) {}

void Komputer_trudny::ruch(Plansza& plansza)
{
    //skos1 \ 
    //skos2 /

    if (!atak(plansza))
        if (!obrona(plansza))
            pollosowy(plansza);
}

bool Komputer_trudny::sprawdz_poziom(Plansza& plansza)
{
    bool ruch_wykonany = false;
    int wiersz = 0, kolumna = 0, licznik_poziom;

    for (wiersz = 0; wiersz < rozmiar_planszy; wiersz++)
    {
        licznik_poziom = 0;

        for (kolumna = 0; kolumna < rozmiar_planszy; kolumna++)
        {
            char element = plansza.getElement(wiersz, kolumna);

            if (element == 'X')
            {
                licznik_poziom++;

                if (licznik_poziom == 4)
                {
                    if (kolumna + 1 < rozmiar_planszy && plansza.getElement(wiersz, kolumna + 1) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz, kolumna + 1, 'O');
                        ruch_wykonany = true;
                    }

                    else if (kolumna - 4 >= 0 && plansza.getElement(wiersz, kolumna - 4) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz, kolumna - 4, 'O');
                        ruch_wykonany = true;
                    }

                }
                else if (licznik_poziom == 3)
                {
                    if (kolumna - 3 >= 0 && plansza.getElement(wiersz, kolumna - 3) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz, kolumna - 3, 'O');
                        ruch_wykonany = true;
                    }

                    else if (kolumna + 1 < rozmiar_planszy && plansza.getElement(wiersz, kolumna + 1) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz, kolumna + 1, 'O');
                        ruch_wykonany = true;
                    }

                }
            }
            else if (element == 'O' || element == ' ')
            {
                licznik_poziom = 0;
            }
        }
    }
    return ruch_wykonany;
}



bool Komputer_trudny::sprawdz_pion(Plansza& plansza)
{
    bool ruch_wykonany = false;
    int wiersz = 0, kolumna = 0, licznik_pion;

    for (kolumna = 0; kolumna < rozmiar_planszy; kolumna++)
    {
        licznik_pion = 0;

        for (wiersz = 0; wiersz < rozmiar_planszy; wiersz++)
        {
            char element = plansza.getElement(wiersz, kolumna);

            if (element == 'X')
            {
                licznik_pion++;

                if (licznik_pion == 4)
                {
                    if (wiersz + 1 < rozmiar_planszy && plansza.getElement(wiersz + 1, kolumna) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz + 1, kolumna, 'O');
                        ruch_wykonany = true;
                    }

                    else if (wiersz - 4 >= 0 && plansza.getElement(wiersz - 4, kolumna) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz - 4, kolumna, 'O');
                        ruch_wykonany = true;
                    }

                }
                else if (licznik_pion == 3)
                {
                    if (wiersz - 3 >= 0 && plansza.getElement(wiersz - 3, kolumna) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz - 3, kolumna, 'O');
                        ruch_wykonany = true;
                    }

                    else if (wiersz + 1 < rozmiar_planszy && plansza.getElement(wiersz + 1, kolumna) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz + 1, kolumna, 'O');
                        ruch_wykonany = true;
                    }

                }
            }
            else if (element == 'O' || element == ' ')
            {
                licznik_pion = 0;
            }
        }
    }
    return ruch_wykonany;
}


bool Komputer_trudny::sprawdz_skos1(Plansza& plansza)
{
    bool ruch_wykonany = false;
    int wiersz = 0, kolumna = 0, licznik_skos1;

    for (wiersz = 0; wiersz < rozmiar_planszy; wiersz++)
    {
        for (kolumna = 0; kolumna < rozmiar_planszy; kolumna++)
        {
            char element = plansza.getElement(wiersz, kolumna);
            licznik_skos1 = 0;
            for (int i = 0; i < 4; i++)
            {
                if (wiersz + i < rozmiar_planszy && kolumna + i < rozmiar_planszy)
                {
                    if (plansza.getElement(wiersz + i, kolumna + i) == 'X')
                        licznik_skos1++;
                }
            }

            if (licznik_skos1 == 4)
            {
                if (wiersz + 4 < rozmiar_planszy && kolumna + 4 < rozmiar_planszy && plansza.getElement(wiersz + 4, kolumna + 4) == ' ' && !ruch_wykonany)
                {
                    plansza.ruch(wiersz + 4, kolumna + 4, 'O');
                    ruch_wykonany = true;
                }
            }
            else if (licznik_skos1 == 3)
            {
                if (wiersz < rozmiar_planszy && kolumna < rozmiar_planszy && wiersz >= 0 && kolumna >= 0 && plansza.getElement(wiersz, kolumna) == ' ' && !ruch_wykonany)
                {
                    plansza.ruch(wiersz, kolumna, 'O');
                    ruch_wykonany = true;
                }
            }
        }
    }
    return ruch_wykonany;
}

bool Komputer_trudny::sprawdz_skos2(Plansza& plansza)
{

    bool ruch_wykonany = false;
    int wiersz = 0, kolumna = 0, licznik_skos2;

    for (wiersz = 0; wiersz < rozmiar_planszy; wiersz++)
    {
        for (kolumna = 0; kolumna < rozmiar_planszy; kolumna++)
        {
            char element = plansza.getElement(wiersz, kolumna);
            licznik_skos2 = 0;
            for (int i = 0; i < 4; i++)
            {
                if (wiersz + i < rozmiar_planszy && kolumna - i >= 0)
                {
                    if (plansza.getElement(wiersz + i, kolumna - i) == 'X')
                        licznik_skos2++;
                }
            }

            if (licznik_skos2 == 4)
            {
                if (wiersz - 1 < rozmiar_planszy && wiersz - 1 >= 0 && kolumna - licznik_skos2 >= 0 && kolumna - licznik_skos2 < rozmiar_planszy && plansza.getElement(wiersz - 1, kolumna + 1) == ' ' && !ruch_wykonany)
                {
                    plansza.ruch(wiersz - 1, kolumna + 1, 'O');
                    ruch_wykonany = true;
                }
            }
            else if (licznik_skos2 == 3)
            {
                if (wiersz + licznik_skos2 < rozmiar_planszy && kolumna - licznik_skos2 >= 0 && plansza.getElement(wiersz + licznik_skos2, kolumna - licznik_skos2) == ' ' && !ruch_wykonany)
                {
                    plansza.ruch(wiersz + licznik_skos2, kolumna - licznik_skos2, 'O');
                    ruch_wykonany = true;
                }
            }
        }
    }
    return ruch_wykonany;
}

void Komputer_trudny::pollosowy(Plansza& plansza)
{
    int wiersz, kolumna;
    bool licznik_blokowan = 0;

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
                        licznik_blokowan = 1;
                    }
                }
            }
        }

    } while (licznik_blokowan == 0);
}


///////////////////////////////////////////////////////
//////////////////////////////////////////////////////
/////////////////////////////////////////////////////

bool Komputer_trudny::sprawdz_poziom_atak(Plansza& plansza)
{
    bool ruch_wykonany = false;
    int wiersz = 0, kolumna = 0, licznik_poziom;

    for (wiersz = 0; wiersz < rozmiar_planszy; wiersz++)
    {
        licznik_poziom = 0;

        for (kolumna = 0; kolumna < rozmiar_planszy; kolumna++)
        {
            char element = plansza.getElement(wiersz, kolumna);

            if (element == 'O')
            {
                licznik_poziom++;

                if (licznik_poziom == 4)
                {
                    if (kolumna + 1 < rozmiar_planszy && plansza.getElement(wiersz, kolumna + 1) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz, kolumna + 1, 'O');
                        ruch_wykonany = true;
                    }

                    else if (kolumna - 4 >= 0 && plansza.getElement(wiersz, kolumna - 4) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz, kolumna - 4, 'O');
                        ruch_wykonany = true;
                    }

                    else if (kolumna - 3 >= 0 && plansza.getElement(wiersz, kolumna - 3) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz, kolumna - 3, 'O');
                        ruch_wykonany = true;
                    }

                    else if (kolumna + 1 <rozmiar_planszy && plansza.getElement(wiersz, kolumna + 1) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz, kolumna + 1, 'O');
                        ruch_wykonany = true;
                    }
                }
            }
            else if (element == 'O' || element == ' ')
            {
                licznik_poziom = 0;
            }
        }
    }
    return ruch_wykonany;
}



bool Komputer_trudny::sprawdz_pion_atak(Plansza& plansza)
{
    bool ruch_wykonany = false;
    int wiersz = 0, kolumna = 0, licznik_pion;

    for (kolumna = 0; kolumna < rozmiar_planszy; kolumna++)
    {
        licznik_pion = 0;

        for (wiersz = 0; wiersz < rozmiar_planszy; wiersz++)
        {
            char element = plansza.getElement(wiersz, kolumna);

            if (element == 'O')
            {
                licznik_pion++;

                if (licznik_pion == 4)
                {
                    if (wiersz + 1 < rozmiar_planszy && plansza.getElement(wiersz + 1, kolumna) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz + 1, kolumna, 'O');
                        ruch_wykonany = true;
                    }

                    else if (wiersz - 4 >= 0 && plansza.getElement(wiersz - 4, kolumna) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz -4, kolumna, 'O');
                        ruch_wykonany = true;
                    }

                    else if (wiersz - 3 >= 0 && plansza.getElement(wiersz - 3, kolumna) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz - 3, kolumna, 'O');
                        ruch_wykonany = true;
                    }

                    else if (wiersz + 1 < rozmiar_planszy && plansza.getElement(wiersz + 1, kolumna) == ' ' && !ruch_wykonany)
                    {
                        plansza.ruch(wiersz + 1, kolumna, 'O');
                        ruch_wykonany = true;
                    }
                }
            }
            else if (element == 'O' || element == ' ')
            {
                licznik_pion = 0;
            }
        }
    }
    return ruch_wykonany;
}


bool Komputer_trudny::sprawdz_skos1_atak(Plansza& plansza)
{
    bool ruch_wykonany = false;
    int wiersz = 0, kolumna = 0, licznik_skos1;

    for (wiersz = 0; wiersz < rozmiar_planszy; wiersz++)
    {
        for (kolumna = 0; kolumna < rozmiar_planszy; kolumna++)
        {
            char element = plansza.getElement(wiersz, kolumna);
            licznik_skos1 = 0;
            for (int i = 0; i < 4; i++)
            {
                if (wiersz + i < rozmiar_planszy && kolumna + i < rozmiar_planszy)
                {
                    if (plansza.getElement(wiersz + i, kolumna + i) == 'O')
                        licznik_skos1++;
                }
            }

            if (licznik_skos1 == 4)
            {
                if (wiersz + licznik_skos1 + 1 < rozmiar_planszy && kolumna + licznik_skos1 + 1 < rozmiar_planszy && plansza.getElement(wiersz + licznik_skos1, kolumna + licznik_skos1) == ' ' && !ruch_wykonany)
                {
                    plansza.ruch(wiersz + licznik_skos1, kolumna + licznik_skos1, 'O');
                    ruch_wykonany = true;
                }
                else if (wiersz - licznik_skos1 < rozmiar_planszy && kolumna - licznik_skos1 && wiersz - licznik_skos1 >= 0 && kolumna - licznik_skos1 >= 0 && plansza.getElement(wiersz - licznik_skos1 + 2, kolumna - licznik_skos1 + 2) == ' ' && !ruch_wykonany)
                {
                    plansza.ruch(wiersz - licznik_skos1 + 2, kolumna - licznik_skos1 + 2, 'O');
                    ruch_wykonany = true;
                }
            }
        }
    }
    return ruch_wykonany;
}

bool Komputer_trudny::sprawdz_skos2_atak(Plansza& plansza)
{

    bool ruch_wykonany = false;
    int wiersz = 0, kolumna = 0, licznik_skos2;

    for (wiersz = 0; wiersz < rozmiar_planszy; wiersz++)
    {
        for (kolumna = 0; kolumna < rozmiar_planszy; kolumna++)
        {
            char element = plansza.getElement(wiersz, kolumna);
            licznik_skos2 = 0;
            for (int i = 0; i < 4; i++)
            {
                if (wiersz + i < rozmiar_planszy && kolumna - i >= 0)
                {
                    if (plansza.getElement(wiersz + i, kolumna - i) == 'O')
                        licznik_skos2++;
                }
            }

            if (licznik_skos2 == 4)
            {
                if (wiersz - 1 < rozmiar_planszy && wiersz - 1 >= 0 && kolumna - licznik_skos2 >= 0 && kolumna - licznik_skos2 < rozmiar_planszy && plansza.getElement(wiersz - 1, kolumna + 1) == ' ' && !ruch_wykonany)
                {
                    plansza.ruch(wiersz - 1, kolumna + 1, 'O');
                    ruch_wykonany = true;
                }
                else if (wiersz + licznik_skos2 < rozmiar_planszy && kolumna - licznik_skos2 >= 0 && plansza.getElement(wiersz + licznik_skos2, kolumna - licznik_skos2) == ' ' && !ruch_wykonany)
                {
                    plansza.ruch(wiersz + licznik_skos2, kolumna - licznik_skos2, 'O');
                    ruch_wykonany = true;
                }
            }
        }
    }
    return ruch_wykonany;
}

bool Komputer_trudny::atak(Plansza& plansza)
{
    bool ruch_wykonany = false;
    if (sprawdz_poziom_atak(plansza))
    {
        return ruch_wykonany = true;
    }
    else
    {
        if (sprawdz_pion_atak(plansza))
        {
            return ruch_wykonany = true;
        }
        else
        {
            if (sprawdz_skos1_atak(plansza))
            {
                return ruch_wykonany = true;
            }
            else
            {
                if (sprawdz_skos2_atak(plansza))
                {
                    return ruch_wykonany = true;
                }
            }
        }
    }
    return ruch_wykonany;
}

bool Komputer_trudny::obrona(Plansza& plansza)
{
    bool ruch_wykonany = false;
    if (sprawdz_poziom(plansza))
    {
        return ruch_wykonany = true;
    }
    else
    {
        if (sprawdz_pion(plansza))
        {
            return ruch_wykonany = true;
        }
        else
        {
            if (sprawdz_skos1(plansza))
            {
                return ruch_wykonany = true;
            }
            else
            {
                if (sprawdz_skos2(plansza))
                {
                    return ruch_wykonany = true;
                }
            }
        }
    }
    return ruch_wykonany;
}