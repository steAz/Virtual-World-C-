#include "Organizm.h"
#include <conio.h>
#include <windows.h>

namespace OrgNameSpace
{
	int Organizm::podajSile()
	{
		return this->sila;

	}


	int Organizm::podajInicjatywe()
	{
		return this->inicjatywa;
	}


	char Organizm::podajZnak()
	{
		return this->znak;
	}


	int Organizm::podajWiek()
	{
		return this->wiek;
	}


	void Organizm::ustawWiek(int wiek)
	{
		this->wiek = wiek;
	}


	void Organizm::dodajWiek()
	{
		this->wiek += 1;
	}


	void Organizm::ustawInicjatywe(int inicjatywa)
	{
		this->inicjatywa = inicjatywa;
	}


	void Organizm::usunOrganizm(Organizm* organizm)
	{
		organizm = NULL;
	}


	bool Organizm::czySciana(SwiatNameSpace::Swiat* swiat, int x, int y)
	{
		if (x<1 || x>swiat->szerokosc)
			return true;
		if (y<1 || y>swiat->wysokosc)
			return true;

		return (swiat->tab[x][y] != ' ');
	}


	void Organizm::zwiekszSile(int sila)
	{
		this->sila += sila;
	}


	int Organizm::podajIloscTurOdSpecjUm()
	{
		return this->iloscTurOdSpecjUm;
	}


	void Organizm::dodajIloscTurOdSpecjUm()
	{
		this->iloscTurOdSpecjUm += 1;
	}


	void Organizm::ustawIloscTurOdSpecjUm(int iloscTurOdSpecjUm)
	{
		this->iloscTurOdSpecjUm = iloscTurOdSpecjUm;
	}


	bool Organizm::podajCzySzybkoscAntylopyON()
	{
		return this->szybkoscAntylopyON;
	}


	bool Organizm::podajCzyMoznaWlSpecjUm()
	{
		return this->czyMoznaWlSpecjUm;
	}


	void Organizm::ustawCzySzybkAntylopyON(bool szybkoscAntylopyON)
	{
		this->szybkoscAntylopyON = szybkoscAntylopyON;
	}


	void Organizm::ustawCzyMoznaWlSpecjUm(bool czyMoznaWlSpecjUm)
	{
		this->czyMoznaWlSpecjUm = czyMoznaWlSpecjUm;
	}


	void Organizm::ustawSile(int sila)
	{
		this->sila = sila;
	}


	int Organizm::podajNumerOrganizmu()
	{
		return this->numerOrganizmu;
	}

	void Organizm::ustawNumerOrganizmu(int nrOrganizmu)
	{
		this->numerOrganizmu = nrOrganizmu;
	}
}