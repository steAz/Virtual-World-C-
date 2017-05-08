#pragma once

#include "Zwierze.h"

namespace ZwNameSpace
{
	class Wilk : public ZwNameSpace::Zwierze
	{
	private:

	
	protected:


	public:
		Wilk(int x, int y, int sila, int inicjatywa, char znaczek);
		~Wilk();
		Wilk& operator=(Wilk& wzor);
		Wilk(Wilk& wzorzec);

	};
}
