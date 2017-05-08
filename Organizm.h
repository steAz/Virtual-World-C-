#pragma once

#ifndef Organizm_h
#define Organizm_h

#include "Swiat.h"

namespace SwiatNameSpace
{
	class Swiat;
}

namespace OrgNameSpace
{
	class Organizm
	{
	private:
		int iloscTurOdSpecjUm;
		bool czyMoznaWlSpecjUm;
		bool szybkoscAntylopyON;
		

	protected:

		int sila;
		int wiek;
		char znak;
		int inicjatywa;
		int numerOrganizmu;

		struct PolozeniePoprzednie
		{
			int x;
			int y;
		} polozeniePoprzednie;

		static bool czySciana(SwiatNameSpace::Swiat* swiat, int x, int y);

	public:

		SwiatNameSpace::Swiat* swiat;
		
		struct Polozenie
		{
			int x;
			int y;
		} polozenie;

		enum Kierunek
		{
			UP = 0,
			DOWN = 1,
			LEFT = 2,
			RIGHT = 3,
			LOSOWY
		} kierunek;

		virtual void akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizmKtoryNieMozeIsc, Kierunek kierunek) = 0;
		virtual void kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac) = 0;
		virtual void rysuj(SwiatNameSpace::Swiat* swiat, int x, int y) = 0;
		void ustawInicjatywe(int inicjatywa);
		int podajSile();
		int podajInicjatywe();
		int podajWiek();
		void ustawPolozenie() {}
		char podajZnak();
		void ustawWiek(int wiek);
		int podajNumerOrganizmu();
		void dodajWiek();
		void usunOrganizm(Organizm* organizm);
		bool czyRozmnazac;
		void zwiekszSile(int sila);
		void dodajIloscTurOdSpecjUm();
		int podajIloscTurOdSpecjUm();
		void ustawIloscTurOdSpecjUm(int iloscTurOdSpecjUm);
		bool podajCzySzybkoscAntylopyON();
		bool podajCzyMoznaWlSpecjUm();
		void ustawCzyMoznaWlSpecjUm(bool czyMoznaWlSpecjUm);
		void ustawCzySzybkAntylopyON(bool szybkoscAntylopyON);
		void ustawSile(int sila);
		void Organizm::ustawNumerOrganizmu(int nrOrganizmu);
	};
}

#endif
