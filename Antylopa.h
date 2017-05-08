#pragma once

#include "Zwierze.h"


namespace ZwNameSpace
{
	class Antylopa : public ZwNameSpace::Zwierze
	{
	private:
		bool czySciana(SwiatNameSpace::Swiat* swiat, int x, int y);
		void przesun(Kierunek kierunek, int* dx, int* dy);
		void akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek);
		void idz(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy);
		void kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac);


	protected:


	public:
		Antylopa(int x, int y, int sila, int inicjatywa, char znaczek);
		~Antylopa();
		Antylopa& operator=(Antylopa& wzor);
		Antylopa(Antylopa& wzorzec);
	};
}
