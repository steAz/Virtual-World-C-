#pragma once

#ifndef Roslina_h
#define Roslina_h

#define CHAR_LEFT 17
#define CHAR_RIGHT 16
#define CHAR_UP 30
#define CHAR_DOWN 31
#define PRZOD 0
#define TYL 1

#include "Organizm.h"
#include <iostream>

namespace RosNameSpace
{

	class Roslina : public OrgNameSpace::Organizm
	{

	private:


	protected:
		Roslina() {}
		Roslina(int x, int y, int sila, int inicjatywa, char znaczek);
		virtual void akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek);
		virtual void rysuj(SwiatNameSpace::Swiat* swiat, int x, int y);
		virtual void kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac);
		

	public:
		

	};
}

#endif
