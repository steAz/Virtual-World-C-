#define WIELKOSC_PLANSZY 400

#include "Czlowiek.h"
#include "Swiat.h"
#include "funkcjeConio.h"
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


namespace ZwNameSpace
{
	Czlowiek::Czlowiek(int x, int y, char znaczek)
	{
		this->polozenie.x = x;
		this->polozenie.y = y;
		this->znak = znaczek;
		this->sila = 5;
		this->inicjatywa = 4;
		this->kierunek = DOWN;
		this->numerOrganizmu = WIELKOSC_PLANSZY; // CZLOWIEK MA USTALONY NUMER ORGANIZMU Z GORY, NIECH BEDIZE TO 400
		this->wiek = 1;
		this->ustawCzySzybkAntylopyON(false);
		this->ustawCzyMoznaWlSpecjUm(true);
	}


	Czlowiek& Czlowiek::operator=(Czlowiek& wzor)
	{
		if (&wzor == this)
		{
			return *this;
		}

		this->wiek = wzor.wiek;
		this->polozenie.x = wzor.polozenie.x;
		this->polozenie.y = wzor.polozenie.y;
		this->sila = wzor.sila;
		this->inicjatywa = wzor.inicjatywa;
		this->znak = wzor.znak;
		this->numerOrganizmu = wzor.numerOrganizmu;

		return *this;
	}


	Czlowiek::Czlowiek(Czlowiek& wzorzec)
	{
		this->wiek = wzorzec.wiek;
		this->polozenie.x = wzorzec.polozenie.x;
		this->polozenie.y = wzorzec.polozenie.y;
		this->sila = wzorzec.sila;
		this->inicjatywa = wzorzec.inicjatywa;
		this->znak = wzorzec.znak;
		this->numerOrganizmu = wzorzec.numerOrganizmu;
	}


	Czlowiek::~Czlowiek()
	{
		this->polozenie.x = NULL;
		this->polozenie.y = NULL;
		this->znak = NULL;
		this->sila = NULL;
		this->inicjatywa = NULL;
		this->wiek = NULL;
		this->numerOrganizmu = NULL;
	}


	void Czlowiek::rysuj(SwiatNameSpace::Swiat* swiat, int x, int y)
	{
		gotoxy(x, y);

		switch (this->kierunek)
		{
		case UP:
			putchar(CHAR_UP);
			break;

		case DOWN:
			putchar(CHAR_DOWN);
			break;

		case LEFT:
			putchar(CHAR_LEFT);
			break;

		case RIGHT:
			putchar(CHAR_RIGHT);
			break;
		}

	}


	void Czlowiek::przesun(Kierunek kierunek, int* dx, int* dy)
	{
		switch (kierunek)
		{
		case UP:
			*dy = -1;

			if (this->podajCzySzybkoscAntylopyON())
			{
				*dy = -2;

				if (this->podajIloscTurOdSpecjUm() >= 3)
				{
					int procent = rand() % 100;
					srand(time(NULL));

					if (procent < 50)
					{
						*dy = -1;
					}
					else
					{
						*dy = -2;
					}
				}
			}
			break;

		case DOWN:
			*dy = 1;

			if (this->podajCzySzybkoscAntylopyON())
			{
				*dy = 2;

				if (this->podajIloscTurOdSpecjUm() >= 3)
				{
					int procent = rand() % 100;
					srand(time(NULL));

					if (procent < 50)
					{
						*dy = 1;
					}
					else
					{
						*dy = 2;
					}
				}
			}
			break;

		case RIGHT:
			*dx = 1;

			if (this->podajCzySzybkoscAntylopyON())
			{
				*dx = 2;

				if (this->podajIloscTurOdSpecjUm() >= 3)
				{
					int procent = rand() % 100;
					srand(time(NULL));

					if (procent < 50)
					{
						*dx = 1;
					}
					else
					{
						*dx = 2;
					}
				}
			}
			break;

		case LEFT:
			*dx = -1;

			if (this->podajCzySzybkoscAntylopyON())
			{
				*dx = -2;

				if (this->podajIloscTurOdSpecjUm() >= 3)
				{
					int procent = rand() % 100;
					srand(time(NULL));

					if (procent < 50)
					{
						*dx = -1;
					}
					else
					{
						*dx = -2;
					}
				}
				break;
			}
		}
	}


	void Czlowiek::idz(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy)
	{
		this->kierunek = kierunek;
		przesun(kierunek, &dx, &dy);

		if (czyMozeIsc(swiat, this, dx, dy))
		{
			if (!czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
			{
				this->polozeniePoprzednie.x = polozenie.x;
				this->polozeniePoprzednie.y = polozenie.y;

				this->czyRozmnazac = false;
				this->polozenie.x += dx;
				this->polozenie.y += dy;
			}
		}
		else if (!czyMozeIsc(swiat, this, dx, dy))
		{
			this->czyRozmnazac = true;
		}

	}


	void Czlowiek::akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek)
	{
		idz(swiat, organizm, kierunek, 0, 0);
	}
}