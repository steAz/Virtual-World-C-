#pragma once

#include "Zwierze.h"


namespace ZwNameSpace
{
	class Lis : public ZwNameSpace::Zwierze
	{
	private:
		void akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek);
		void idz(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy);
		bool czyObokSilniejszyPrzeciwnik(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy);


	protected:


	public:
		Lis(int x, int y, int sila, int inicjatywa, char znaczek);
		~Lis();
		Lis& operator=(Lis& wzor);
		Lis(Lis& wzorzec);

	};
}