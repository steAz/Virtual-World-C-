#define WIELKOSC_PLANSZY 400

#include "Swiat.h"
#include "Roslina.h"
#include "funkcjeConio.h"
#include <time.h>

namespace RosNameSpace
{
	Roslina::Roslina(int x, int y, int sila, int inicjatywa, char znaczek)
	{
		this->sila = sila;
		this->inicjatywa = inicjatywa;  
		this->znak = znak;
		this->polozenie.x = x;
		this->polozenie.y = y;
	}


	void Roslina::kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac)
	{
		
	}


	void Roslina::akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek)
	{
		int dx = 0;
		int dy = 0;
		int procent = rand() % 100;
		int prawdopodobienstwo = rand() % 65; // losujemy prawdopodobienstwo od 0 do 65
		srand(rand() % 1000);

		if (procent < prawdopodobienstwo)
		{
			int losuj;
			for (int j = 0; j < WIELKOSC_PLANSZY + 1; j++)
			{
				if (swiat->organizmy[j] != NULL)
				{
					losuj = 0;
					if (losuj == 0)
					{
						dx = 1;
						dy = 0;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 1)
					{
						dx = 1;
						dy = -1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 2)
					{
						dx = 0;
						dy = -1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 3)
					{
						dx = -1;
						dy = -1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 4)
					{
						dx = -1;
						dy = 0;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 5)
					{
						dx = -1;
						dy = 1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 6)
					{
						dx = 0;
						dy = 1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 7)
					{
						dx = 1;
						dy = 1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{

						}
					}
				}
			}
		}


	}


	void Roslina::rysuj(SwiatNameSpace::Swiat* swiat, int x, int y)
	{
		gotoxy(x, y);
		switch (this->znak)
		{
		case 't':
			putchar('t');
			break;

		case 'm':
			putchar('m');
			break;

		case 'g':
			putchar('g');
			break;

		case 'j':
			putchar('j');
			break;
		}
	}
}