#define WIELKOSC_PLANSZY 400
#include "Swiat.h"
#include "Organizm.h"

namespace OrgNameSpace
{
	void KontenerOrganizmow::dodajOrganizmy(SwiatNameSpace::Swiat* swiat)
	{
		int licznik = 0;
		for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
		{
			if (swiat->organizmy[i] != NULL)
			{
				licznik++;
			}
		}

		this->organizmy = new OrgNameSpace::Organizm*[licznik];
		this->iloscOrganizmowWkontenerze = licznik;

		int j = 0;
		for (int i = 0; i < licznik; i++)
		{
			if (organizmy[i] != NULL)
			{
				this->organizmy[j] = swiat->organizmy[i];
				j++;
			}
		}
	}


	void KontenerOrganizmow::usunOrganizmy(SwiatNameSpace::Swiat* swiat)
	{
		for (int i = 0; i < iloscOrganizmowWkontenerze; i++)
		{
			delete[] this->organizmy[i];
			this->organizmy[i] = NULL;
		}
	}
}