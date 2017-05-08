#pragma once

#include "Roslina.h"


namespace RosNameSpace
{
	class Mlecz : public RosNameSpace::Roslina
	{
	private:
		void akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek);


	protected:


	public:
		Mlecz(int x, int y, int sila, int inicjatywa, char znaczek);
		~Mlecz();
		Mlecz& operator=(Mlecz& wzor);
		Mlecz(Mlecz& wzorzec);

	};
}
