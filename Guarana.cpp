#define WIELKOSC_PLANSZY 400

#include "Guarana.h"
#include "Roslina.h"
#include "Swiat.h"


namespace RosNameSpace
{
	Guarana::Guarana(int x, int y, int sila, int inicjatywa, char znaczek)
	{
		this->polozenie.x = x;
		this->polozenie.y = y;
		this->sila = sila;
		this->inicjatywa = inicjatywa;
		this->znak = znaczek;
		this->wiek = 1;
	}


	Guarana& Guarana::operator=(Guarana& wzor)
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


	Guarana::Guarana(Guarana& wzorzec)
	{
		this->wiek = wzorzec.wiek;
		this->polozenie.x = wzorzec.polozenie.x;
		this->polozenie.y = wzorzec.polozenie.y;
		this->sila = wzorzec.sila;
		this->inicjatywa = wzorzec.inicjatywa;
		this->znak = wzorzec.znak;
		this->numerOrganizmu = wzorzec.numerOrganizmu;
	}


	Guarana::~Guarana()
	{
		this->polozenie.x = NULL;
		this->polozenie.y = NULL;
		this->sila = NULL;
		this->inicjatywa = NULL;
		this->znak = NULL;
		this->wiek = NULL;
		this->numerOrganizmu = NULL;
	}


	void Guarana::kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac)
	{
		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			if (swiat->organizmy[i] != NULL)
			{
				if (this->podajZnak() != swiat->organizmy[i]->podajZnak() && swiat->organizmy[i]->podajZnak() != 't'  && swiat->organizmy[i]->podajZnak() != 'm' && swiat->organizmy[i]->podajZnak() != 'j')
				{
					if (this->polozenie.x == swiat->organizmy[i]->polozenie.x && this->polozenie.y == swiat->organizmy[i]->polozenie.y)
					{
						swiat->organizmy[i]->zwiekszSile(3);
					}
				}
			}
		}
	}
}