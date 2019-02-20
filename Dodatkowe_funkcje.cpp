#pragma once
#include <iostream>
#include "Dodatkowe_funkcje.h"
#include <string>
#include "Error.h"

using namespace std;

bool CzyNieCyfra(string napis)
{
	for (int i = 0; i < napis.length(); i++)
	{
		if (isdigit(napis[i])) throw JestCyfra();
	}
	return true;
}

bool CzyNieLitera(string napis)
{
	for (size_t i = 0; i < napis.length(); i++)
	{
		if (napis[i] == ',') napis[i] = '.';
	}

	for (int i = 0; i < napis.length(); i++)
	{
		if (isalpha(napis[i])) throw JestLitera();
	}
	return true;
}

void UzykajNrLotu(Pasazer & przykladPasazer, Lot & LotDoPrzyporzadkowania)
{
	przykladPasazer.lotPasazera = LotDoPrzyporzadkowania.getNrLotu();
}

void UzykajCelLotu(Pasazer & przykladPasazer, Lot & LotDoPrzyporzadkowania)
{
	przykladPasazer.celPasazera = LotDoPrzyporzadkowania.getCelLotu();
}

void DodajUzytkownika(Pasazer * bazaPasazerow, Lot & LotDlaPasazera, int & ilewBazie)
{
    label: string noweImionaINazwisko;
	string nowyTel;
	string nowyPass;

    cout << "\nPodaj imiona i nazwisko: ";
	try {
		getline(cin, noweImionaINazwisko);
		CzyNieCyfra(noweImionaINazwisko);
	}
	catch (Error& err) {
		cout << err.what();
		goto label;
	}
label2: cout << "\nPodaj numer telefonu: ";
	try {
		getline(cin, nowyTel);
		CzyNieLitera(nowyTel);
	}
	catch (Error& err) {
		cout << err.what();
		goto label2;
	}
	cout << "\nWprowadz numer dokumentu paszportowego: ";
	cin >> nowyPass;
	cout << "\nDane zosta³y wprowadzone prawid³owo - oto Twoje dane: ";

	bazaPasazerow[ilewBazie] = Pasazer(noweImionaINazwisko, nowyTel, nowyPass);
	UzykajNrLotu(bazaPasazerow[ilewBazie], LotDlaPasazera);
	UzykajCelLotu(bazaPasazerow[ilewBazie], LotDlaPasazera);
	LotDlaPasazera.setPasazer(bazaPasazerow[ilewBazie]);
	cout << bazaPasazerow[ilewBazie];
	ilewBazie++;
}


