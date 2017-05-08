// projektWirtSwiat.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include "funkcjeConio.h"
#include "Organizm.h"
#include "Swiat.h"
#include "Zasoby.h"
#include "Czlowiek.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>



using namespace std;



int main()
{
	SetConsoleTitle(TEXT("Micha³ Kazanowski 160512"));
	SwiatNameSpace::Swiat* swiat = new SwiatNameSpace::Swiat();
	//ZwNameSpace::Czlowiek czlowiek('C');
	Zasoby zasoby;
	swiat->programON = true;
	swiat->ON = false;
	swiat->czyCzlowiekZywy = true;

	zasoby.powitanie();
	do
	{
		swiat->menu();
		swiat->rysowanie();
		
	} while (swiat->programON);
	

	return 0;
}

