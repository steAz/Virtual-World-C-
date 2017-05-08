#define WIELKOSC_PLANSZY 400

#include "Swiat.h"
#include "Zwierze.h"
#include "Czlowiek.h"
#include "funkcjeConio.h"
#include "time.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

namespace ZwNameSpace
{
	Zwierze::Zwierze(int x, int y, int sila, int inicjatywa, char znak)
	{
		this->sila = sila;
		this->inicjatywa = inicjatywa;
		this->znak = znak;
		this->polozenie.x = x;
		this->polozenie.y = y;
	}


	void Zwierze::przesun(Kierunek kierunek, int* dx, int* dy)
	{
		switch (kierunek)
		{
		case UP:
			*dy = -1;
			break;

		case DOWN:
			*dy = 1;
			break;

		case RIGHT:
			*dx = 1;
			break;

		case LEFT:
			*dx = -1;
			break;
		}
	}


	bool Zwierze::czyMozeIsc(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, int dx, int dy)
	{
		for (int i = 0; i < WIELKOSC_PLANSZY; i++)
		{
			if (swiat->organizmy[i] != NULL)
			{
				if (this->podajZnak() == swiat->organizmy[i]->podajZnak() && this != swiat->organizmy[i]) // jesli to te same typy, ale nie te same organizmy
				{
					if ((this->polozenie.x + dx == swiat->organizmy[i]->polozenie.x) && (this->polozenie.y + dy == swiat->organizmy[i]->polozenie.y)) // jesli pierwszy po przesunieciu, trafi na wspolrzedne organizmu swojego typu, to zwroc falsz(nie moze isc !)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
		

	void Zwierze::idz(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek, int dx, int dy)
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


	void Zwierze::akcja(SwiatNameSpace::Swiat* swiat, OrgNameSpace::Organizm* organizm, Kierunek kierunek)
	{
		int losuj;
		
		
		if (this->podajZnak() == 'W')
		{
			srand(rand() % 2000);
			losuj = rand() % 4;
		}
		if (this->podajZnak() == 'S')
		{
			srand(rand() % 1000);
			losuj = rand() % 4; // kazde zwierze generuje sranda z innym parametrem - > zmieniamy pseudolosowosc ( np od 2 do 1000, jesli srand przyjmuje parametr 1, to pseudolosowac jest taka sama dla kazdej akcji)
		}

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


	void Zwierze::kolizja(SwiatNameSpace::Swiat* swiat, bool czyRozmnazac)
	{
		if (this->czyRozmnazac)
		{
			int dx = 0;
			int dy = 0;

			int losuj;
			for (int j = 0; j < WIELKOSC_PLANSZY + 1; j++)
			{
				if (swiat->organizmy[j] != NULL )
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

		else if(!this->czyRozmnazac)
		{
			swiat->licznik = 2;
			if (swiat->licznik >= 23)
			{
				swiat->licznik = 2;
			}
			for (int i = 0; i < WIELKOSC_PLANSZY + 1; i++)
			{
				ZwNameSpace::Czlowiek* czlowiekDynamicCast;  // do okreslania typu dynamicznie

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
									czlowiekDynamicCast = dynamic_cast<ZwNameSpace::Czlowiek*>(this);
									if (czlowiekDynamicCast)
									{
										swiat->czyCzlowiekZywy = false;
										if (swiat->licznik < 24)
										{
											gotoxy(23, swiat->licznik);
											cout << this->podajZnak() << " zjadl " << swiat->organizmy[i]->podajZnak() << endl;
											swiat->licznik++;
										}
										usunOrganizm(this);
										czlowiekDynamicCast = NULL;
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
									czlowiekDynamicCast = dynamic_cast<ZwNameSpace::Czlowiek*>(this);
									if (czlowiekDynamicCast)
									{
										swiat->czyCzlowiekZywy = false;
										if (swiat->licznik < 24)
										{
											gotoxy(23, swiat->licznik);
											cout << swiat->organizmy[i]->podajZnak() << " zabil " << this->podajZnak() << endl;
											swiat->licznik++;
										}

										usunOrganizm(this);
										czlowiekDynamicCast = NULL;
									}
									else
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
							}

							else if (swiat->organizmy[i]->podajZnak() == 'A')
							{
								int procent = rand() % 100;
								srand(rand() % 1000);

								if (procent < 50)
								{
									if (this->podajSile() >= swiat->organizmy[i]->podajSile())
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
										czlowiekDynamicCast = dynamic_cast<ZwNameSpace::Czlowiek*>(this);
										if(czlowiekDynamicCast) //(this->podajZnak() == 'C')
										{
											swiat->czyCzlowiekZywy = false;
											if (swiat->licznik < 24)
											{
												gotoxy(23, swiat->licznik);
												cout << swiat->organizmy[i]->podajZnak() << " zabil " << this->podajZnak() << endl;
												swiat->licznik++;
											}

											usunOrganizm(this);
											czlowiekDynamicCast = NULL;
										}
										else
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

												if ((swiat->organizmy[i]->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (swiat->organizmy[i]->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, swiat->organizmy[i]->polozenie.x + dx, swiat->organizmy[i]->polozenie.y + dy))
												{
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dx;
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dy;
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

												if ((swiat->organizmy[i]->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (swiat->organizmy[i]->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, swiat->organizmy[i]->polozenie.x + dx, swiat->organizmy[i]->polozenie.y + dy))
												{
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dx;
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dy;
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

												if ((swiat->organizmy[i]->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (swiat->organizmy[i]->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, swiat->organizmy[i]->polozenie.x + dx, swiat->organizmy[i]->polozenie.y + dy))
												{
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dx;
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dy;
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

												if ((swiat->organizmy[i]->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (swiat->organizmy[i]->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, swiat->organizmy[i]->polozenie.x + dx, swiat->organizmy[i]->polozenie.y + dy))
												{
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dx;
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dy;
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

												if ((swiat->organizmy[i]->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (swiat->organizmy[i]->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, swiat->organizmy[i]->polozenie.x + dx, swiat->organizmy[i]->polozenie.y + dy))
												{
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dx;
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dy;
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

												if ((swiat->organizmy[i]->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (swiat->organizmy[i]->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, swiat->organizmy[i]->polozenie.x + dx, swiat->organizmy[i]->polozenie.y + dy))
												{
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dx;
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dy;
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

												if ((swiat->organizmy[i]->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (swiat->organizmy[i]->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, swiat->organizmy[i]->polozenie.x + dx, swiat->organizmy[i]->polozenie.y + dy))
												{
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dx;
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dy;
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

												if ((swiat->organizmy[i]->polozenie.x + dx != swiat->organizmy[j]->polozenie.x) && (swiat->organizmy[i]->polozenie.y + dy != swiat->organizmy[j]->polozenie.y) && !czySciana(swiat, swiat->organizmy[i]->polozenie.x + dx, swiat->organizmy[i]->polozenie.y + dy))
												{
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dx;
													swiat->organizmy[i]->polozenie.x = swiat->organizmy[i]->polozenie.x + dy;
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

							else if (this->podajSile() >= swiat->organizmy[i]->podajSile())
							{
								czlowiekDynamicCast = dynamic_cast<ZwNameSpace::Czlowiek*>(swiat->organizmy[i]);
								if(czlowiekDynamicCast) //(swiat->organizmy[i]->podajZnak() == 'C')
								{
									swiat->czyCzlowiekZywy = false;
									if (swiat->licznik < 24)
									{
										gotoxy(23, swiat->licznik);
										cout << this->podajZnak() << " zabil " << swiat->organizmy[i]->podajZnak() << endl;
										swiat->licznik++;
									}

									swiat->organizmy[i] = NULL;
									czlowiekDynamicCast = NULL;
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
								czlowiekDynamicCast = dynamic_cast<ZwNameSpace::Czlowiek*>(this);
								if(czlowiekDynamicCast)  //(this->podajZnak() == 'C')
								{
									swiat->czyCzlowiekZywy = false;
									if (swiat->licznik < 24)
									{
										gotoxy(23, swiat->licznik);
										cout << swiat->organizmy[i]->podajZnak() << " zabil " << this->podajZnak() << endl;
										swiat->licznik++;
									}

									usunOrganizm(this);
									czlowiekDynamicCast = NULL;
								}
								else
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
						}
					}
				}
			}
		}
	}


	void Zwierze::rysuj(SwiatNameSpace::Swiat* swiat, int x, int y)
	{
		gotoxy(x, y);
		switch (this->znak)
		{
		case 'W':
			putchar('W');
			break;

		case 'S':
			putchar('S');
			break;

		case 'L':
			putchar('L');
			break;

		case 'Z':
			putchar('Z');
			break;

		case 'A':
			putchar('A');
			break;
		}
	}
}
