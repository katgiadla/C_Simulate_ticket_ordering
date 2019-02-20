#pragma once
#include <iostream>
#include "Dodatkowe_funkcje.h"
#include <string>
#include "File.h"
#include "Lot.h"

using namespace std;

class Lot;
class Pasazer;
class File;
ostream& operator<<(ostream&, Pasazer&);
void UzykajNrLotu(Pasazer&, Lot&);
void UzykajCelLotu(Pasazer&, Lot&);

class Pasazer{
	friend class Lot;
	friend class File;
	friend ostream& operator<<(ostream&, Pasazer&);
	friend void UzykajNrLotu(Pasazer&, Lot&);
	friend void UzykajCelLotu(Pasazer&, Lot&);
	string imionaInazwisko;
	string nrTel;
	string nrPaszportu;
	static int iid;
	int lotPasazera;
	string celPasazera;
public:
	Pasazer();
	Pasazer(string noweImionaiNaz, string nowyTel, string nowyPaszport);
	~Pasazer();
};