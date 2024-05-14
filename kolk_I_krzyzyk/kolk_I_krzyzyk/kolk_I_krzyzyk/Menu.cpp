#include <iostream>
#include "SFML/Graphics.hpp"
#include "Gra.h"
#include "Menu.h"
#include <locale.h>

using namespace sf;
using namespace std;

Menu::Menu(RenderWindow& window) : window(window)
{
	setlocale(LC_CTYPE, "Polish");

	if (!czcionka.loadFromFile("Fonts/Bitter-Regular.ttf"))
	{
		cerr << "Nie za³adowano czcionki!" << endl;
	}

	tytul.setFont(czcionka);
	tytul.setString(L"WYBIERZ POZIOM TRUDNOŒCI!");
	tytul.setCharacterSize(36);
	tytul.setFillColor(Color::Black);
	tytul.setStyle(Text::Bold);
	float szerokosc_tytlu = tytul.getGlobalBounds().width;
	tytul.setPosition((window.getSize().x - szerokosc_tytlu) / 2, 0);

	przycisk_latwy_poziom.setFont(czcionka);
	przycisk_latwy_poziom.setString(L"POZIOM £ATWY");
	przycisk_latwy_poziom.setCharacterSize(28);
	przycisk_latwy_poziom.setFillColor(Color::Black);
	przycisk_latwy_poziom.setStyle(Text::Bold);
	float szerokosc_latwy = przycisk_latwy_poziom.getGlobalBounds().width;
	przycisk_latwy_poziom.setPosition((window.getSize().x - szerokosc_latwy) / 2, 200);

	przycisk_trudny_poziom.setFont(czcionka);
	przycisk_trudny_poziom.setString(L"POZIOM TRUDNY");
	przycisk_trudny_poziom.setCharacterSize(28);
	przycisk_trudny_poziom.setFillColor(Color::Black);
	przycisk_trudny_poziom.setStyle(Text::Bold);
	float szerokosc_trudny = przycisk_trudny_poziom.getGlobalBounds().width;
	przycisk_trudny_poziom.setPosition((window.getSize().x - szerokosc_trudny) / 2, 300);
}

void Menu::rysuj()
{
	setlocale(LC_CTYPE, "Polish");
	window.clear(Color::White);
	window.draw(tytul);
	window.draw(przycisk_latwy_poziom);
	window.draw(przycisk_trudny_poziom);
	window.display();
}

void Menu::handleEvents() {
	setlocale(LC_CTYPE, "Polish");
	Event event;
	while (window.pollEvent(event)) 
	{
		if (event.type == Event::Closed) 
		{
			window.close();
		}
		else if (event.type == Event::MouseButtonPressed) 
		{
			if (event.mouseButton.button == Mouse::Left) 
			{
				Vector2i mousePos = Mouse::getPosition(window);

				if (przycisk_latwy_poziom.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
				{
					cout << "Wybrano poziom ³atwy." <<endl;
					wybranyPoziom = 1;
					window.close();
					RenderWindow window(VideoMode(660, 660), L"Kó³ko i krzy¿yk");
					Gra gra(window, 1);
					gra.run();

				}
				else if (przycisk_trudny_poziom.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
				{

					cout << "Wybrano poziom trudny." <<endl;
					wybranyPoziom = 2;
					window.close();
					RenderWindow window(VideoMode(660, 660), L"Kó³ko i krzy¿yk");
					Gra gra(window, 2);
					gra.run();
				}
			}
		}
	}
}

void Menu::run() {
	while (window.isOpen()) 
	{
		handleEvents();
		rysuj();
	}
}