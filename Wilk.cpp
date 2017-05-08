#include "Wilk.h"
#include "Zwierze.h"
#include "Swiat.h"
#include "funkcjeConio.h"
#include <iostream>

using namespace std;


namespace ZwNameSpace
{
	Wilk::Wilk(int x, int y, int sila, int inicjatywa, char znaczek)
	{
		this->polozenie.x = x;
		this->polozenie.y = y;
		this->sila = sila;
		this->inicjatywa = inicjatywa;
		this->znak = znaczek;
		this->wiek = 1;
	}

	Wilk& Wilk::operator=(Wilk& wzor)
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

	Wilk::Wilk(Wilk& wzorzec)
	{
		this->wiek = wzorzec.wiek;
		this->polozenie.x = wzorzec.polozenie.x;
		this->polozenie.y = wzorzec.polozenie.y;
		this->sila = wzorzec.sila;
		this->inicjatywa = wzorzec.inicjatywa;
		this->znak = wzorzec.znak;
		this->numerOrganizmu = wzorzec.numerOrganizmu;
	}
	

	Wilk::~Wilk()
	{
		this->polozenie.x = NULL;
		this->polozenie.y = NULL;
		this->sila = NULL;
		this->inicjatywa = NULL;
		this->znak = NULL;
		this->wiek = NULL;
		this->numerOrganizmu = NULL;
	}
}