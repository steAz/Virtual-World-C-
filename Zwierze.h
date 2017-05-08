#pragma once

#ifndef Zwierze_h
#define Zwierze_h

#define CHAR_LEFT 17
#define CHAR_RIGHT 16
#define CHAR_UP 30
#define CHAR_DOWN 31
#define PRZOD 0
#define TYL 1

#include "Organizm.h"
#include <iostream>

namespace ZwNameSpace
{
	class Zwierze : public OrgNameSpace::Organizm
	{
	private:


	protected:
		Zwierze() {};
		virtual void akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek);
		virtual void rysuj(SwiatNameSpace::Swiat* swiat, int x, int y);
		virtual void kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac);
		virtual void przesun(Kierunek kierunek, int* dx, int* dy);
		virtual void idz(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy);
		virtual bool czyMozeIsc(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, int dx, int dy);
		Zwierze(int x, int y, int sila, int inicjatywa, char znaczek);

	public:


	};
}

#endif


