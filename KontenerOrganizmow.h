#pragma once

#include "Swiat.h"
#include <iostream>

namespace SwiatNameSpace
{
	class Swiat;
}

namespace OrgNameSpace
{
	class Organizm;
}

namespace OrgNameSpace
{
	class KontenerOrganizmow
	{

	private:
		int iloscOrganizmowWkontenerze;
		void dodajOrganizmy(SwiatNameSpace::Swiat* swiat);
		void usunOrganizmy(SwiatNameSpace::Swiat* swiat);

	protected:


	public:
		OrgNameSpace::Organizm** organizmy;
		
	};
}



