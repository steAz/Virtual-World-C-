#pragma once

#include "Zwierze.h"


namespace ZwNameSpace
{
	class Zolw : public ZwNameSpace::Zwierze
	{
	private:
		void akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek);
		void Zolw::kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac);


	protected:


	public:
		Zolw(int x, int y, int sila, int inicjatywa, char znaczek);
		~Zolw();
		Zolw& operator=(Zolw& wzor);
		Zolw(Zolw& wzorzec);
	};
}
