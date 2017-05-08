#define WIELKOSC_PLANSZY 400

#include "Lis.h"
#include "Zwierze.h"

namespace ZwNameSpace
{
	Lis::Lis(int x, int y, int sila, int inicjatywa, char znaczek)
	{
		this->polozenie.x = x;
		this->polozenie.y = y;
		this->sila = sila;
		this->inicjatywa = inicjatywa;
		this->znak = znaczek;
		this->wiek = 1;
	}


	Lis& Lis::operator=(Lis& wzor)
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


	Lis::Lis(Lis& wzorzec)
	{
		this->wiek = wzorzec.wiek;
		this->polozenie.x = wzorzec.polozenie.x;
		this->polozenie.y = wzorzec.polozenie.y;
		this->sila = wzorzec.sila;
		this->inicjatywa = wzorzec.inicjatywa;
		this->znak = wzorzec.znak;
		this->numerOrganizmu = wzorzec.numerOrganizmu;
	}


	Lis::~Lis()
	{
		this->polozenie.x = NULL;
		this->polozenie.y = NULL;
		this->sila = NULL;
		this->inicjatywa = NULL;
		this->znak = NULL;
		this->wiek = NULL;
		this->numerOrganizmu = NULL;
	}


	bool Lis::czyObokSilniejszyPrzeciwnik(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy)
	{
		for (int j = 0; j < WIELKOSC_PLANSZY + 1; j++)
		{
			if (swiat->organizmy[j] != NULL)
			{
				if ((this->polozenie.x + dx == swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy == swiat->organizmy[j]->polozenie.y))
				{
					if (this->podajSile() < swiat->organizmy[j]->podajSile())
					{
						return true;
					}
				}
			}
		}

		return false;
	}


	void Lis::idz(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy)
	{
		this->kierunek = kierunek;
	
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

	
	void Lis::akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek)
	{
		int losuj;
		losuj = rand() % 4;

		if (losuj == UP)
		{
			if (!czyObokSilniejszyPrzeciwnik(swiat, organizm, kierunek, 0, -1))
			{
				idz(swiat, organizm, UP, 0, -1);
			}
		}
		else if (losuj == DOWN)
		{
			if (!czyObokSilniejszyPrzeciwnik(swiat, organizm, kierunek, 0, 1))
			{
				idz(swiat, organizm, DOWN, 0, 1);
			}
		}
		else if (losuj == RIGHT)
		{
			if (!czyObokSilniejszyPrzeciwnik(swiat, organizm, kierunek, 1, 0))
			{
				idz(swiat, organizm, RIGHT, 1, 0);
			}
		}
		else if (losuj == LEFT)
		{
			if (!czyObokSilniejszyPrzeciwnik(swiat, organizm, kierunek, -1, 0))
			{
				idz(swiat, organizm, LEFT, -1, 0);
			}
		}
	}
}