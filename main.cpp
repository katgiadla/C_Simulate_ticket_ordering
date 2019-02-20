#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <clocale>
#include <fstream>
#include <Windows.h>
#include "Dodatkowe_funkcje.h"
#include "Error.h"
#include "Lot.h"
#include "File.h"
#include "Pasazer.h"

using namespace std;

int Pasazer::iid = 0;

int main() {
	setlocale(LC_ALL, "pl_PL");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);

	///ustawienie bazy pasazerow///
	int maxLiczbaPasazerowwBazie = 300;
	Pasazer* bazaPasazerow = new Pasazer[maxLiczbaPasazerowwBazie];

	//zadeklarowanie na razie jedynego lotu i liczby juz zarejetrowanych biletow//
	Lot jedynyDostepny;
	int licznikPasazerowwBazie = 0;
	
	///ekran powitalny//
	kolejnyUzytkownik: SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
	cout << "System rezerwacji biletow lotniczych linii AirKoryo: " << endl << endl;
	
	//sprawdzenie, czy maksymalna ilosc osob jest juz zarejestrowana//
	if (licznikPasazerowwBazie == maxLiczbaPasazerowwBazie)
	{
		cout << "\nNie mo�na wpisa� nowych u�ytkownik�w! System zosta� zamkniety!";
		return 0;
	}

	cout << "Mo�liwa rezerwacja tylko jednego lotu: " << jedynyDostepny;
	
	//Dodawanie konkretnego u�ytkownika//
	DodajUzytkownika(bazaPasazerow, jedynyDostepny, licznikPasazerowwBazie);

	//Mo�liwo�� wydruku biletu jest zale�na od woli u�ytkownika//
	int wyborUzytkownika;
	cout << "\nCzy chcesz wydrukowac swoj bilet? Wybierz liczb�: " << endl;
	cout << "(1) TAK" << endl;
	cout << "(2) NIE i wyjdz z programu" << endl;
	powrot: cin >> wyborUzytkownika;
	switch (wyborUzytkownika)
	{
	case (1):
	{
		File::doPliku(bazaPasazerow[licznikPasazerowwBazie - 1]);
		cout << "Plik zostal wygenerowany";
		break;
	}
	case (2): break;
	default:
	{
		cout << "Zla wartosc, wpisz ponownie";
		goto powrot;
	}
	}

	//Mo�liwo�� rejestracji kolejnej osoby//
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
	powrot2: cout << "\nCzy chcesz dokona� kolejnej rezerwacji?" << endl;
	cout << "(1) TAK" << endl;
	cout << "(2) NIE i wyjdz z programu" << endl;
	cin >> wyborUzytkownika;
	switch (wyborUzytkownika)
	{
		case (1):
		{
			goto kolejnyUzytkownik;
			break;
		}
		case (2): break;
		default:
		{
			cout << "Zla wartosc, wpisz ponownie";
			goto powrot2;
		}
	}
	

	//koniec programu//
	SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
	cout << "Dzi�kujemy za rezerwacj�!" << endl;
	system("PAUSE");
	return 0;
}