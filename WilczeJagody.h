#pragma once

#include "Roslina.h"


namespace RosNameSpace
{
	class WilczeJagody : public RosNameSpace::Roslina
	{
	private:
		void kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac);


	protected:


	public:
		WilczeJagody(int x, int y, int sila, int inicjatywa, char znaczek);
		~WilczeJagody();
		WilczeJagody& operator=(WilczeJagody& wzor);
		WilczeJagody(WilczeJagody& wzorzec);

	};
}
