#define _CRT_SECURE_NO_WARNINGS
#define POMOCZNICZA_DO_NR_ORGANIZMU 10
#define WIELKOSC_PLANSZY 400  // wielkosc pola ze scianami -> szerokosc*wysokosc=400 

#include "Swiat.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "funkcjeConio.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;



class ZlyZnak
{
private:

public:
	const char* tekst;
	ZlyZnak(const char* tekst);
};


ZlyZnak::ZlyZnak(const char* tekst)
{
	this->tekst = tekst;
}


class ZlyRozmiarMapy
{
private:

	public:
		const char* tekst;
		ZlyRozmiarMapy(const char* tekst);
};


ZlyRozmiarMapy::ZlyRozmiarMapy(const char* tekst)
{
	this->tekst = tekst;
}


namespace SwiatNameSpace
{
	Swiat::~Swiat()
	{
		for (int i = 0; i < szerokosc; i++)
		{
			delete[] tab[i];
		}

		delete[] tab;
		tab = NULL;
	}


	Swiat::Swiat()
	{
		tab = NULL;
		wysokosc = 0;
		szerokosc = 0;
		tura = 0;
	}


	void Swiat::ustawRozmiar(int width, int height)
	{
		if (tab != NULL)
		{
			for (int i = 0; i < width; i++)
			{
				delete[] tab[i];
			}

			delete[] tab;
			tab = NULL;
		}

		tab = new char*[width]; 

		for (int i = 0; i < width; i++)
		{
			tab[i] = new char[height];  
		}

		szerokosc = width;
		wysokosc = height;
	}


	char Swiat::podaj(int x, int y)
	{
		return tab[x][y];
	}


	void Swiat::init()
	{
		this->organizmy = NULL;
		this->organizmy = new OrgNameSpace::Organizm*[WIELKOSC_PLANSZY];

		for (int i = 0; i < WIELKOSC_PLANSZY; i++)
		{
			this->organizmy[i] = NULL;
		}
	}


	void Swiat::zapisz(const char * sciezka)
	{
		fstream plik;
		plik.open(sciezka, ios::out | ios::trunc);
		plik << this->podajTure() << "\n";
		plik << this->szerokosc << " " << this->wysokosc << "\n";

		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			if (this->organizmy[i] != NULL)
			{
				plik << this->organizmy[i]->podajZnak() << " ";
				plik << this->organizmy[i]->podajWiek() << " ";
				plik << this->organizmy[i]->podajSile() << " ";
				plik << this->organizmy[i]->podajInicjatywe() << " ";
				plik << this->organizmy[i]->polozenie.x << " ";
				plik << this->organizmy[i]->polozenie.y << " ";

				if (this->organizmy[i]->podajZnak() == 'C')
				{
					plik << this->organizmy[i]->podajIloscTurOdSpecjUm() << " ";
				}
				plik << "\n";
			}
			else
			{
				plik << "X\n";
			}
		}
	}


	void Swiat::zapiszDoPliku()
	{
		char nazwa[32];
		gotoxy(29, 21);
		_cputs("Podaj nazwe do zapisu: ");
		cin >> nazwa;
		zapisz(nazwa);
	}


	void Swiat::wczytaj(const char* sciezka)
	{
		fstream plik;
		plik.open(sciezka, ios::in);

		if (!plik.good())
		{
			return;
		}

		plik >> this->tura;
		plik >> this->szerokosc;
		plik >> this->wysokosc;

		init();

		char znak;
		int x, y, wiek, inicjatywa, sila, iloscTurOdSpecjUm;


		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			plik >> znak;

			if (znak == 'C')
			{
				plik >> wiek;
				plik >> sila;
				plik >> inicjatywa;
				plik >> x;
				plik >> y;
				plik >> iloscTurOdSpecjUm;
				dodajOrganizm(x, y, znak);
				organizmy[WIELKOSC_PLANSZY]->ustawInicjatywe(inicjatywa);
				organizmy[WIELKOSC_PLANSZY]->ustawWiek(wiek);
				organizmy[WIELKOSC_PLANSZY]->ustawSile(sila);
				organizmy[WIELKOSC_PLANSZY]->ustawIloscTurOdSpecjUm(iloscTurOdSpecjUm);
			}
			else if (znak != 'C' && znak != 'X')
			{
				plik >> wiek;
				plik >> sila;
				plik >> inicjatywa;
				plik >> x;
				plik >> y;
				dodajOrganizm(x, y, znak);
				int nrOrganizmu = (x * POMOCZNICZA_DO_NR_ORGANIZMU) + y;
				organizmy[nrOrganizmu]->ustawInicjatywe(inicjatywa);
				organizmy[nrOrganizmu]->ustawWiek(wiek);
				organizmy[nrOrganizmu]->ustawSile(sila);
			}
			else if (znak == 'X')
			{

			}
			else
			{
				printf("Error! Nie Mozesz dostac sie do pliku");
			}
		}
	}


	void Swiat::wczytajZpliku()
	{
		char nazwa[32];
		gotoxy(29, 21);
		_cputs("Podaj nazwe pliku wczytywanego: ");
		cin >> nazwa;
		wczytaj(nazwa);
	}


	bool Swiat::weryfikacja(int x, int y)
	{
		if (x < 6 || y < 6)
		{
			return false;
		}
	}

	void Swiat::laduj(const char* sciezka)
	{
		FILE * plik = fopen(sciezka, "r");

		if (plik)
		{
			char liniaTekstu[256];
			char tabBuffor[100][100];        //tablica buforowa maksymalna
			char znak[] = { '#', '$', '&' , '*', '@' };
			int y = 0;
			int x = 0;

			while (fscanf(plik, "%s", liniaTekstu) != EOF)
			{
				x = 0;
				while (liniaTekstu[x] != '\0')  //czytaj, az nie najedziesz na znak konca linii
				{
					if (liniaTekstu[x] == '1')
					{
						tabBuffor[x][y] = '#';  //losowanie sciany gdy element tablicy bedzie jedynka
					}
					else
					{
						tabBuffor[x][y] = ' ';        

						if (liniaTekstu[x] == 'C')
						{
							dodajOrganizm(x, y, 'C');
						}
						if (liniaTekstu[x] == 'W')
						{
							dodajOrganizm(x, y, 'W');
						}
						if (liniaTekstu[x] == 'S')
						{
							dodajOrganizm(x, y, 'S');
						}
						if (liniaTekstu[x] == 'L')
						{
							dodajOrganizm(x, y, 'L');
						}
						if (liniaTekstu[x] == 'Z')
						{
							dodajOrganizm(x, y, 'Z');
						}
						if (liniaTekstu[x] == 'A')
						{
							dodajOrganizm(x, y, 'A');
						}
						if (liniaTekstu[x] == 't')
						{
							dodajOrganizm(x, y, 't');
						}
						if (liniaTekstu[x] == 'm')
						{
							dodajOrganizm(x, y, 'm');
						}
						if (liniaTekstu[x] == 'g')
						{
							dodajOrganizm(x, y, 'g');
						}
						if (liniaTekstu[x] == 'j')
						{
							dodajOrganizm(x, y, 'j');
						}
					}
					x++;
				}
				y++;
			}
			try
			{
				int width = x;
				int height = y;

				if (!weryfikacja(width,height))
				{
					throw ZlyRozmiarMapy("Probujesz ustawic rozmiar planszy o zlych rozmiarach(");
				}

				ustawRozmiar(width, height);

				for (x = 0; x < width; x++)
				{
					for (y = 0; y < height; y++)
					{
						tab[x][y] = tabBuffor[x][y];
					}
				}

			}
			catch(ZlyRozmiarMapy& zlyRozmiarMapy)
			{
				cout << endl << "Zlapany wyjatek" << endl << zlyRozmiarMapy.tekst << endl;
				system("pause");
			}
			fclose(plik);
		}
		else
		{
			printf(sciezka);
			printf("Error! Nie mozesz dostac sie do pliku");
			system("Pause");
		}
	}


	void Swiat::rysujSwiat()
	{
		for (int y = 0; y < wysokosc; y++)
		{
			for (int x = 0; x < szerokosc; x++)
			{
				gotoxy(x, y);
				putchar(podaj(x, y));
			}
		}
	}


	OrgNameSpace::Organizm* Swiat::dodajOrganizm(int x, int y, char znak)
	{
		int nrOrganizmu = (x * POMOCZNICZA_DO_NR_ORGANIZMU) + y;

		OrgNameSpace::Organizm* organizm;
		organizm = NULL;

		try
		{
			switch (znak)
			{
			case 'C':
				organizm = new ZwNameSpace::Czlowiek(x, y, 'C');
				break;

			case 'W':
				organizm = new ZwNameSpace::Wilk(x, y, 9, 5, 'W');
				break;

			case 'S':
				organizm = new ZwNameSpace::Owca(x, y, 4, 4, 'S');
				break;

			case 'L':
				organizm = new ZwNameSpace::Lis(x, y, 3, 7, 'L');
				break;

			case 'Z':
				organizm = new ZwNameSpace::Zolw(x, y, 2, 1, 'Z');
				break;

			case 'A':
				organizm = new ZwNameSpace::Antylopa(x, y, 4, 4, 'A');
				break;

			case 't':
				organizm = new RosNameSpace::Trawa(x, y, 0, 1, 't');
				break;

			case 'm':
				organizm = new RosNameSpace::Mlecz(x, y, 0, 1, 'm');
				break;

			case 'g':
				organizm = new RosNameSpace::Guarana(x, y, 0, 1, 'g');
				break;

			case 'j':
				organizm = new RosNameSpace::WilczeJagody(x, y, 99, 1, 'j');
				break;

			default:
				throw ZlyZnak("Probujesz dodac organizm o nieprawidlowym znaku");
			}
		}
		catch (ZlyZnak& zlyZnak) // przy czytaniu w laduj() wystarczy dac jakis znak  w funckji dodajOrganizm, ktorego ta funkcja nie obsluguje
		{
			cout << endl << "Zlapany wyjatek" << endl << zlyZnak.tekst << endl;
			system("pause");
			return NULL;
		}

		if (znak == 'C')
		{
			organizm->ustawNumerOrganizmu(WIELKOSC_PLANSZY); // Zeby latwo go zapamietac to daje mu numer 400
			//organizm->numerOrganizmu = WIELKOSC_PLANSZY;  
		}
		else
		{
			organizm->ustawNumerOrganizmu(nrOrganizmu);
			//organizm->numerOrganizmu = nrOrganizmu;
		}

		this->organizmy[organizm->podajNumerOrganizmu()] = organizm;
		this->organizmy[organizm->podajNumerOrganizmu()]->ustawWiek(1); // na poczatku tury wiek wynosi 1
	//	this->organizmy[organizm->numerOrganizmu] = organizm;
		// this->organizmy[organizm->numerOrganizmu]->ustawWiek(1);  

		return organizm;
	}


	int Swiat::podajNajwiekszaInicjatywe() // funkcja wyszukujaca maksymalna inicjatywe 
	{
		int najwiekszaInicjatywa;
		bool czyPierwszaZnalezionaInicjatywa = true;

		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			if (organizmy[i] != NULL)
			{
				if (czyPierwszaZnalezionaInicjatywa)
				{
					najwiekszaInicjatywa = organizmy[i]->podajInicjatywe();
					czyPierwszaZnalezionaInicjatywa = false;
				}

				if (organizmy[i]->podajInicjatywe() > najwiekszaInicjatywa)
				{
					najwiekszaInicjatywa = organizmy[i]->podajInicjatywe();
				}
			}
		}

		return najwiekszaInicjatywa;
	}


	int Swiat::podajNajwiekszyWiek()
	{
		int najwiekszyWiek;
		bool czyPierwszyZnalezionyWiek = true;

		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			if (organizmy[i] != NULL)
			{
				if (czyPierwszyZnalezionyWiek)
				{
					najwiekszyWiek = organizmy[i]->podajWiek();
					czyPierwszyZnalezionyWiek = false;
				}

				if (organizmy[i]->podajWiek() > najwiekszyWiek)
				{
					najwiekszyWiek = organizmy[i]->podajWiek();
				}
			}
		}

		return najwiekszyWiek;
	}


	OrgNameSpace::Organizm* Swiat::organizmOtejSamejInicjatywie(OrgNameSpace::Organizm* sprawdzanyOrganizm) // funckja wyszukuje organizmy o tej samej inicjatywie, co podany do parametru do pozniejszego okreslenia wieku
	{
		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			if (organizmy[i] != NULL && organizmy[i] != sprawdzanyOrganizm)  // nie trzeba sprawdzac tego samego organizmu 
			{
				if (organizmy[i]->podajInicjatywe() == sprawdzanyOrganizm->podajInicjatywe())
				{
					return organizmy[i];
				}
				else
				{
					return NULL;
				}
			}
		}
		
	}


	void Swiat::dodajWiek()
	{
		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			if (organizmy[i] != NULL)
			{
				this->organizmy[i]->dodajWiek();
			}
		}
	}


	int Swiat::podajTure()
	{
		return this->tura;
	}


	void Swiat::dodajTure()
	{
		this->tura += 1;
	}


	void Swiat::wykonajKolizje()
	{
		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			if (organizmy[i] != NULL)
			{
				if (organizmy[i]->podajZnak() == 'g' || organizmy[i]->podajZnak() == 'j' || organizmy[i]->podajZnak() == 'm' || organizmy[i]->podajZnak() == 't')
				{
					organizmy[i]->kolizja(this, false);
				}
				else if (organizmy[i]->czyRozmnazac == true)
				{
					organizmy[i]->kolizja(this, true);
				}
				else
				{
					organizmy[i]->kolizja(this, false);

				}
			}
		}
	}


	void Swiat::wykonajTure(int obsluga)
	{
		OrgNameSpace::Organizm::Kierunek kierunekCzlowieka;

		if (obsluga == 0x48)
		{
			kierunekCzlowieka = OrgNameSpace::Organizm::UP;
		}
		else if (obsluga == 0x50)
		{
			kierunekCzlowieka = OrgNameSpace::Organizm::DOWN;
		}
		else if (obsluga == 0x4b)
		{
			kierunekCzlowieka = OrgNameSpace::Organizm::LEFT;
		}
		else if (obsluga == 0x4d)
		{
			kierunekCzlowieka = OrgNameSpace::Organizm::RIGHT;
		}

		int najwiekszaInicjatywa = podajNajwiekszaInicjatywe();
		int najwiekszyWiek = podajNajwiekszyWiek();

		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			OrgNameSpace::Organizm* organizm;
			ZwNameSpace::Czlowiek* czlowiekDynamicCast;

			if (organizmy[i] != NULL)
			{
				if (najwiekszaInicjatywa == organizmy[i]->podajInicjatywe())  // jesli znajdziemy najwiekszaInicjatywe 
				{
					if (organizmOtejSamejInicjatywie(organizmy[i]) != NULL) // i jesli znaleziono organizm , ktory ma ta samma inicjatywe, co dany organizm (organizmy[i]), to
					{
						organizm = organizmOtejSamejInicjatywie(organizmy[i]);

						if (organizm->podajWiek() > organizmy[i]->podajWiek()) // to on porusza sie jako pierwszy, jesli ma wiekszy wiek
						{
							czlowiekDynamicCast = dynamic_cast<ZwNameSpace::Czlowiek*>(organizm);
							if (czlowiekDynamicCast)  //(organizm->podajZnak() == 'C')
							{
								organizm->akcja(this, organizm, kierunekCzlowieka);
								czlowiekDynamicCast = NULL;
							}
							else
							{
								organizm->akcja(this, organizm, organizm->LOSOWY);
							}
						}
						else
						{
							czlowiekDynamicCast = dynamic_cast<ZwNameSpace::Czlowiek*>(organizmy[i]);
							if (czlowiekDynamicCast) // (organizmy[i]->podajZnak() == 'C')
							{ // nie musze sprawdzac czy czlowiekZywy, bo jest zywy skoro weszlismy
									organizmy[WIELKOSC_PLANSZY]->akcja(this, organizmy[WIELKOSC_PLANSZY], kierunekCzlowieka);
									czlowiekDynamicCast = NULL;
							}
							else
							{
								organizmy[i]->akcja(this, organizmy[i], organizmy[i]->LOSOWY);
							}
						}
					}

					else if (organizmOtejSamejInicjatywie(organizmy[i]) == NULL) // nie znalaziono organizmu , ktory ma ta sama inicjatywe co dany  organizm (organizmy[i]), jest on rowny NULL
					{
						czlowiekDynamicCast = dynamic_cast<ZwNameSpace::Czlowiek*>(organizmy[i]);
						if (czlowiekDynamicCast)  //(organizmy[i]->podajZnak() == 'C')
						{// nie musze sprawdzac czy czlowiekZywy, bo jest zywy skoro weszlismy
							organizmy[WIELKOSC_PLANSZY]->akcja(this, organizmy[WIELKOSC_PLANSZY], kierunekCzlowieka);
							czlowiekDynamicCast = NULL;
						}
						else
						{
							organizmy[i]->akcja(this, organizmy[i], organizmy[i]->LOSOWY);
						}
					}

					else
					{
						czlowiekDynamicCast = dynamic_cast<ZwNameSpace::Czlowiek*>(organizmy[i]);
						if (czlowiekDynamicCast)  //(organizmy[i]->podajZnak() == 'C')
						{
							if (!czyCzlowiekZywy)
							{

							}
							else
							{
								organizmy[WIELKOSC_PLANSZY]->akcja(this, organizmy[WIELKOSC_PLANSZY], kierunekCzlowieka);

							}
							czlowiekDynamicCast = NULL;
						}
						else
						{
							organizmy[i]->akcja(this, organizmy[i], organizmy[i]->LOSOWY);
						}
					}

				}
			}

			if (i == WIELKOSC_PLANSZY)
			{
				najwiekszaInicjatywa -= 1;
				if (najwiekszaInicjatywa != 0)  // algorytm powtarza petle(zmieniamy 'i' na 0, gdy 'i' bedzie rowne wartosci ostatniej iteracji petli) i zmniejsza inicjatywe do czasu, gdy inicjatywa osiagnie wartosc 0 (wtedy nie ma juz czego sprawdzac)
				{
					i = 0;
				}
			}
		}

		wykonajKolizje(); //PO PETLI WSZYSTKIE ORGANIZMY WYKONUJA KOLIZJE I KAZDY MA DODAWANY WIEK O 1
		dodajWiek();

		if (organizmy[WIELKOSC_PLANSZY] != NULL)
		{
			if (organizmy[WIELKOSC_PLANSZY]->podajCzySzybkoscAntylopyON())
			{
				organizmy[WIELKOSC_PLANSZY]->dodajIloscTurOdSpecjUm();

				if (organizmy[WIELKOSC_PLANSZY]->podajIloscTurOdSpecjUm() >= 5)
				{
					organizmy[WIELKOSC_PLANSZY]->ustawCzyMoznaWlSpecjUm(false);
					organizmy[WIELKOSC_PLANSZY]->ustawCzySzybkAntylopyON(false);
					organizmy[WIELKOSC_PLANSZY]->ustawIloscTurOdSpecjUm(0);
				}
			}

			else if (!organizmy[WIELKOSC_PLANSZY]->podajCzySzybkoscAntylopyON() && !organizmy[WIELKOSC_PLANSZY]->podajCzyMoznaWlSpecjUm())
			{
				organizmy[WIELKOSC_PLANSZY]->dodajIloscTurOdSpecjUm();

				if (organizmy[WIELKOSC_PLANSZY]->podajIloscTurOdSpecjUm() >= 5)
				{
					organizmy[WIELKOSC_PLANSZY]->ustawCzyMoznaWlSpecjUm(true);
					organizmy[WIELKOSC_PLANSZY]->ustawIloscTurOdSpecjUm(0);
				}
			}
		}

		dodajTure();
		gotoxy(24, 24);
		cout << "Aktualna tura: " << this->podajTure();
	}
		

	void Swiat::menu()
	{
		if (czyCzlowiekZywy)
		{
			zn = _getch();
		}

		if (!czyCzlowiekZywy)
		{
			zn = 1;
		}
	
		if (zn == 'n')
		{
			ON = true;
			init();
			laduj("swiat_tab.txt");
			czyCzlowiekZywy = true;
			clear_scr();
		}

		if (zn == 'x')
		{
			if (organizmy[WIELKOSC_PLANSZY] != NULL )
			{
				if (organizmy[WIELKOSC_PLANSZY]->podajCzyMoznaWlSpecjUm())
				{
					organizmy[WIELKOSC_PLANSZY]->ustawCzySzybkAntylopyON(true);
				}
			}
		}

		if (zn == 's')
		{
			zapiszDoPliku();
			clear_scr();
		}

		if (zn == 'l')
		{
			wczytajZpliku();
			clear_scr();
		}

		else if (ON && czyCzlowiekZywy)
		{
			if (zn == 0x48)
			{
				wykonajTure(zn);	
			}
			else if (zn == 0x50)
			{
				wykonajTure(zn);
				
			}
			else if (zn == 0x4b)
			{
				wykonajTure(zn);
			
			}
			else if (zn == 0x4d)
			{
				wykonajTure(zn);
			}
		}

		else if (!czyCzlowiekZywy && ON)
		{
			wykonajTure(zn);
		}

		if (zn == 'q')
		{
			programON = false;
		}
		
	}


	void Swiat::rysujOrganizmy()
	{
		int licznik = 2;
		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++) // WIELKOSC_PLANSZY +1 , bo czlowiek jest pod numerem WIELKOSC_PLANSZY=400
		{
			if (organizmy[i] != NULL) 
			{
					organizmy[i]->rysuj(this, organizmy[i]->polozenie.x, organizmy[i]->polozenie.y);
			}
		}

		gotoxy(23, 1);
		if (organizmy[WIELKOSC_PLANSZY] != NULL)
		{
			cout << "Sila czlowieka: " << organizmy[WIELKOSC_PLANSZY]->podajSile();
		}
	}


	void Swiat::rysowanie()
	{
		if (ON)
		{
			rysujSwiat();
			rysujOrganizmy();
		}
	}
}