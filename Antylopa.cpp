#define WIELKOSC_PLANSZY 400

#include "Antylopa.h"
#include "Zwierze.h"
#include "funkcjeConio.h"
#include <iostream>

using namespace std;

namespace ZwNameSpace
{
	Antylopa::Antylopa(int x, int y, int sila, int inicjatywa, char znaczek)
	{
		this->polozenie.x = x;
		this->polozenie.y = y;
		this->sila = sila;
		this->inicjatywa = inicjatywa;
		this->znak = znaczek;
		this->wiek = 1;
	}


	Antylopa& Antylopa::operator=(Antylopa& wzor)
	{
		if (&wzor == this)
		{
			return *this;
		}

		this->wiek = wzor.wiek;
		this->polozenie.x = wzor.polozenie.x;
		this->polozenie.y = wzor.polozenie.y;
		this->sila = wzor.sila;
		this->inicjatywa = wzor.inicjatywa;
		this->znak = wzor.znak;
		this->numerOrganizmu = wzor.numerOrganizmu;

		return *this;
	}


	Antylopa::Antylopa(Antylopa& wzorzec)
	{
		this->wiek = wzorzec.wiek;
		this->polozenie.x = wzorzec.polozenie.x;
		this->polozenie.y = wzorzec.polozenie.y;
		this->sila = wzorzec.sila;
		this->inicjatywa = wzorzec.inicjatywa;
		this->znak = wzorzec.znak;
		this->numerOrganizmu = wzorzec.numerOrganizmu;
	}


	Antylopa::~Antylopa()
	{
		this->polozenie.x = NULL;
		this->polozenie.y = NULL;
		this->sila = NULL;
		this->inicjatywa = NULL;
		this->znak = NULL;
		this->wiek = NULL;
		this->numerOrganizmu = NULL;
	}


	bool Antylopa::czySciana(SwiatNameSpace::Swiat* swiat, int x, int y)
	{
		if (x<1 || x>swiat->szerokosc)
			return true;
		if (x<1 || y>swiat->wysokosc)
			return true;

		return (swiat->tab[x][y] != ' ');
	}


	void Antylopa::przesun(Kierunek kierunek, int* dx, int* dy)
	{
		switch (kierunek)
		{
		case UP:
			*dy = -2;
			break;

		case DOWN:
			*dy = 2;
			break;

		case RIGHT:
			*dx = 2;
			break;

		case LEFT:
			*dx = -2;
			break;
		}
	}


	void Antylopa::kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac)
	{
		if (this->czyRozmnazac)
		{
			int dx = 0;
			int dy = 0;

			int losuj;
			for (int j = 0; j < WIELKOSC_PLANSZY + 1; j++)
			{
				if (swiat->organizmy[j] != NULL)
				{
					losuj = 0;
					if (losuj == 0)
					{
						dx = 1;
						dy = 0;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 1)
					{
						dx = 1;
						dy = -1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 2)
					{
						dx = 0;
						dy = -1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 3)
					{
						dx = -1;
						dy = -1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 4)
					{
						dx = -1;
						dy = 0;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 5)
					{
						dx = -1;
						dy = 1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 6)
					{
						dx = 0;
						dy = 1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{
							losuj += 1;
						}
					}
					if (losuj == 7)
					{
						dx = 1;
						dy = 1;

						if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
						{
							swiat->dodajOrganizm(this->polozenie.x + dx, this->polozenie.y + dy, this->podajZnak());
							break;
						}
						else
						{

						}
					}
				}
			}
		}

		else if (!this->czyRozmnazac)
		{
			for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
			{
				if (swiat->organizmy[i] != NULL) 
				{
					if (this->podajZnak() != swiat->organizmy[i]->podajZnak())
					{
						if (this->polozenie.x == swiat->organizmy[i]->polozenie.x && this->polozenie.y == swiat->organizmy[i]->polozenie.y)
						{
							if (swiat->organizmy[i]->podajZnak() == 'g' || swiat->organizmy[i]->podajZnak() == 't' || swiat->organizmy[i]->podajZnak() == 'm' || swiat->organizmy[i]->podajZnak() == 'j')
							{
								if (swiat->organizmy[i]->podajZnak() == 'g')
								{
									this->zwiekszSile(3);
								}
								else if (swiat->organizmy[i]->podajZnak() == 'j')
								{
									if (this->podajZnak() == 'C')
									{
										swiat->czyCzlowiekZywy = false;
										if (swiat->licznik < 24)
										{
											gotoxy(23, swiat->licznik);
											cout << this->podajZnak() << " zjadl " << swiat->organizmy[i]->podajZnak() << endl;
											swiat->licznik++;
										}
										usunOrganizm(this);
									}
									else
									{
										if (swiat->licznik < 24)
										{
											gotoxy(23, swiat->licznik);
											cout << this->podajZnak() << " zjadl " << swiat->organizmy[i]->podajZnak()  << endl;
											swiat->licznik++;
										}

										usunOrganizm(this);
									}
								}

								if (swiat->licznik < 24 && swiat->organizmy[i]->podajZnak() != 'j')
								{
									gotoxy(23, swiat->licznik);
									cout << this->podajZnak() << " zjadl " << swiat->organizmy[i]->podajZnak() << endl;
									swiat->licznik++;
								}
								swiat->organizmy[i] = NULL;
							}

							else if (swiat->organizmy[i]->podajZnak() == 'Z')
							{
								if (this->podajSile() < 5)
								{
									this->polozenie.x = polozeniePoprzednie.x;
									this->polozenie.y = polozeniePoprzednie.y;
								}
								else if (this->podajSile() > swiat->organizmy[i]->podajSile() && this->podajSile() >= 5)
								{
									if (swiat->licznik < 24)
									{
										gotoxy(23, swiat->licznik);
										cout << this->podajZnak() << " zabil " << swiat->organizmy[i]->podajZnak() << endl;
										swiat->licznik++;
									}
									swiat->organizmy[i] = NULL;
								}
								else if (swiat->organizmy[i]->podajSile() > this->podajSile())
								{
									if (swiat->licznik < 24)
									{
										gotoxy(23, swiat->licznik);
										cout << swiat->organizmy[i]->podajZnak() << " zabil " << this->podajZnak() << endl;
										swiat->licznik++;
									}

									usunOrganizm(this);
								}
							}

							else if (this->podajSile() >= swiat->organizmy[i]->podajSile())
							{
								if (swiat->organizmy[i]->podajZnak() == 'C')
								{
									swiat->czyCzlowiekZywy = false;
									if (swiat->licznik < 24)
									{
										gotoxy(23, swiat->licznik);
										cout << this->podajZnak() << " zabil " << swiat->organizmy[i]->podajZnak() << endl;
										swiat->licznik++;
									}

									swiat->organizmy[i] = NULL;
								}
								else
								{
									if (swiat->licznik < 24)
									{
										gotoxy(23, swiat->licznik);
										cout << this->podajZnak() << " zabil " << swiat->organizmy[i]->podajZnak() << endl;
										swiat->licznik++;
									}

									swiat->organizmy[i] = NULL;
								}
							}
							else if (swiat->organizmy[i]->podajSile() > this->podajSile())
							{
								int procent = rand() % 100;
								srand(rand() % 1000);

								if (procent < 50)
								{
									if (swiat->licznik < 24)
									{
										gotoxy(23, swiat->licznik);
										cout << swiat->organizmy[i]->podajZnak() << " zabil " << this->podajZnak() << endl;
										swiat->licznik++;
									}

									usunOrganizm(this);
								}
								else
								{
									int dx = 0;
									int dy = 0;

									int losuj;
									for (int j = 0; j < WIELKOSC_PLANSZY + 1; j++)
									{
										if (swiat->organizmy[j] != NULL)
										{
											losuj = 0;
											if (losuj == 0)
											{
												dx = 1;
												dy = 0;

												if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
												{
													this->polozenie.x = this->polozenie.x + dx;
													this->polozenie.y = this->polozenie.y + dy;
													break;
												}
												else
												{
													losuj += 1;
												}
											}
											if (losuj == 1)
											{
												dx = 1;
												dy = -1;

												if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
												{
													this->polozenie.x = this->polozenie.x + dx;
													this->polozenie.y = this->polozenie.y + dy;
													break;
												}
												else
												{
													losuj += 1;
												}
											}
											if (losuj == 2)
											{
												dx = 0;
												dy = -1;

												if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
												{
													this->polozenie.x = this->polozenie.x + dx;
													this->polozenie.y = this->polozenie.y + dy;
													break;
												}
												else
												{
													losuj += 1;
												}
											}
											if (losuj == 3)
											{
												dx = -1;
												dy = -1;

												if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
												{
													this->polozenie.x = this->polozenie.x + dx;
													this->polozenie.y = this->polozenie.y + dy;
													break;
												}
												else
												{
													losuj += 1;
												}
											}
											if (losuj == 4)
											{
												dx = -1;
												dy = 0;

												if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
												{
													this->polozenie.x = this->polozenie.x + dx;
													this->polozenie.y = this->polozenie.y + dy;
													break;
												}
												else
												{
													losuj += 1;
												}
											}
											if (losuj == 5)
											{
												dx = -1;
												dy = 1;

												if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
												{
													this->polozenie.x = this->polozenie.x + dx;
													this->polozenie.y = this->polozenie.y + dy;
													break;
												}
												else
												{
													losuj += 1;
												}
											}
											if (losuj == 6)
											{
												dx = 0;
												dy = 1;

												if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
												{
													this->polozenie.x = this->polozenie.x + dx;
													this->polozenie.y = this->polozenie.y + dy;
													break;
												}
												else
												{
													losuj += 1;
												}
											}
											if (losuj == 7)
											{
												dx = 1;
												dy = 1;

												if ((this->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (this->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
												{
													this->polozenie.x = this->polozenie.x + dx;
													this->polozenie.y = this->polozenie.y + dy;
													break;
												}
												else
												{

												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}


	void Antylopa::idz(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy)
	{
		this->kierunek = kierunek;
		przesun(kierunek, &dx, &dy);

		if (czyMozeIsc(swiat, this, dx, dy))
		{
			if (!czySciana(swiat, this->polozenie.x + dx, this->polozenie.y + dy))
			{
				this->polozeniePoprzednie.x = polozenie.x;
				this->polozeniePoprzednie.y = polozenie.y;

				this->czyRozmnazac = false;
				this->polozenie.x += dx;
				this->polozenie.y += dy;
			}
		}
		else if (!czyMozeIsc(swiat, this, dx, dy))
		{
			this->czyRozmnazac = true;
		}
	}


	void Antylopa::akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek)
	{
		int losuj;
		srand(rand() % 1000);   // kazde zwierze generuje sranda z innym parametrem - > zmieniamy pseudolosowosc ( np od 2 do 1000, jesli srand przyjmuje parametr 1, to pseudolosowac jest taka sama dla kazdej akcji)
		losuj = rand() % 4;

		if (losuj == UP)
		{
			idz(swiat, organizm, UP, 0, 0);
		}
		else if (losuj == DOWN)
		{
			idz(swiat, organizm, DOWN, 0, 0);
		}
		else if (losuj == RIGHT)
		{
			idz(swiat, organizm, RIGHT, 0, 0);
		}
		else if (losuj == LEFT)
		{
			idz(swiat, organizm, LEFT, 0, 0);
		}
	}
}