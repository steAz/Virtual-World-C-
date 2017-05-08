#define WIELKOSC_PLANSZY 400

#include "Mlecz.h"
#include "Roslina.h"
#include "Swiat.h"
#include <time.h>


namespace RosNameSpace
{
	Mlecz::Mlecz(int x, int y, int sila, int inicjatywa, char znaczek)
	{
		this->polozenie.x = x;
		this->polozenie.y = y;
		this->sila = sila;
		this->inicjatywa = inicjatywa;
		this->znak = znaczek;
		this->wiek = 1;
	}


	Mlecz& Mlecz::operator=(Mlecz& wzor)
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


	Mlecz::Mlecz(Mlecz& wzorzec)
	{
		this->wiek = wzorzec.wiek;
		this->polozenie.x = wzorzec.polozenie.x;
		this->polozenie.y = wzorzec.polozenie.y;
		this->sila = wzorzec.sila;
		this->inicjatywa = wzorzec.inicjatywa;
		this->znak = wzorzec.znak;
		this->numerOrganizmu = wzorzec.numerOrganizmu;
	}


	Mlecz::~Mlecz()
	{
		this->polozenie.x = NULL;
		this->polozenie.y = NULL;
		this->sila = NULL;
		this->inicjatywa = NULL;
		this->znak = NULL;
		this->wiek = NULL;
		this->numerOrganizmu = NULL;
	}


	void Mlecz::akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek)
	{
		int dx = 0;
		int dy = 0;
		int procent;
		int prawdopodobienstwo;
		

		for (int i = 0; i < 3; i++) // 3 proby
		{
			procent = rand() % 100;
			prawdopodobienstwo = rand() % 65;
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
	}
}