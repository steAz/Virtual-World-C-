#pragma once

#include "KontenerOrganizmow.h"
#include "Organizm.h"
#include <iostream>


namespace OrgNameSpace
{
	class Organizm;
	class KontenerOrganizmow;
}


namespace ZwNameSpace
{
	class Zwierze;
	class Czlowiek;
}

namespace SwiatNameSpace
{
	class Swiat
	{
	private:
		int tura;
		int zn;

		void init();
		void laduj(const char* sciezka);
		void ustawRozmiar(int width, int height);
		char podaj(int x, int y); // odzwierciedlenie metody get() Klasy i obiektu 
		void rysujSwiat();
		void zapisz(const char* sciezka);
		void wykonajTure(int obsluga);
		void rysujOrganizmy();
		int podajNajwiekszaInicjatywe();
		int podajNajwiekszyWiek();
		OrgNameSpace::Organizm* organizmOtejSamejInicjatywie(OrgNameSpace::Organizm* sprawdzanyOrganizm);
		void dodajWiek();
		void wykonajKolizje();
		bool czyOrganizmMozeIsc;
		void dodajTure();
		void zapiszDoPliku();
		int  podajTure();
		void wczytaj(const char* sciezka);
		void wczytajZpliku();
		bool weryfikacja(int x, int y);
		
		
	protected:


	public:
		OrgNameSpace::Organizm** organizmy; // przedstawiona KOMPOZYCJA - > dane typy organizmow ( czlowiek, wilk, zolw .... ) nie moga istniec bez obiektu zwierze, 
		int wysokosc;                                                      // KOMPOZYCJA TO SK£ADANIE SIE OBIEKTU Z OBIEKTÓW SK£ADOWYCH, KTÓRE NIE MOG¥ ISTNIEC BEZ OBIEKTU G£ÓWNEGO
		int szerokosc;                                                         // USUNIECIE CALOSCI ( WSKAZINKOW NA OBIEKTY LUB ZWIERZAT) , TO AUTOMATYCZNY BRAK DZIALANIA WSZYSTKICH TYPOW ORGANIZMU ( czlowieka, wilka, zolwia .... )
		char** tab;
		int licznik; // do wyswietlania stanu swiata
		bool czyCzlowiekZywy;
		bool ON;
		bool programON;

		Swiat();
		~Swiat();
		OrgNameSpace::Organizm* dodajOrganizm(int x, int y, char znak);
		void menu();
		void rysowanie();
	};
}