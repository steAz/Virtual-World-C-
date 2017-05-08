#pragma once

#include "Roslina.h"


namespace RosNameSpace
{
	class Guarana : public RosNameSpace::Roslina
	{
	private:
		virtual void kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac);


	protected:


	public:
		Guarana(int x, int y, int sila, int inicjatywa, char znaczek);
		~Guarana();
		Guarana& operator=(Guarana& wzor);
		Guarana(Guarana& wzorzec);
	};
}
