#pragma once

#define CHAR_LEFT 17
#define CHAR_RIGHT 16
#define CHAR_UP 30
#define CHAR_DOWN 31
#define PRZOD 0
#define TYL 1

#include "Zwierze.h"
#include <iostream>


namespace ZwNameSpace
{
	class Czlowiek : public ZwNameSpace::Zwierze
	{
	private:
		void akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek);
		void rysuj(SwiatNameSpace::Swiat* swiat, int x, int y);
		void przesun(Kierunek kierunek, int* dx, int* dy);
		void idz(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy);


	protected:


	public:
		Czlowiek() {};
		Czlowiek(int x, int y, char znaczek);
		Czlowiek(Czlowiek& wzorzec);
		Czlowiek& operator=(Czlowiek& wzor);
		~Czlowiek();
	};
}


