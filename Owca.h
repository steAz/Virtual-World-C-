#pragma once
#include "Zwierze.h"


namespace ZwNameSpace
{
	class Owca : public ZwNameSpace::Zwierze
	{
	private:


	protected:


	public:
			Owca(int x, int y, int sila, int inicjatywa, char znaczek);
			~Owca();
			Owca& operator=(Owca& wzor);
			Owca(Owca& wzorzec);
	};
}