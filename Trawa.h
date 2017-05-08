#pragma once

#include "Roslina.h"


namespace RosNameSpace
{
	class Trawa : public RosNameSpace::Roslina
	{
	private:


	protected:


	public:
		Trawa(int x, int y, int sila, int inicjatywa, char znaczek);
		~Trawa();
		Trawa& operator=(Trawa& wzor);
		Trawa(Trawa& wzorzec);
	};
}
