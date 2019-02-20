#pragma once
#include <iostream>
#include "Pasazer.h"
#include <string>
#include "Dodatkowe_funkcje.h"

using namespace std;

class Lot;
class Pasazer;
ostream& operator<<(ostream&, Lot&);
void UzykajNrLotu(Pasazer&, Lot&);
void UzykajCelLotu(Pasazer&, Lot&);

class Lot {
	friend class Pasazer;
	friend ostream& operator<<(ostream&, Lot&);
	friend void UzykajNrLotu(Pasazer&, Lot&);
	friend void UzykajCelLotu(Pasazer&, Lot&);
	int KodLotu;
	string dataiGodzina;
	string cel;
	int ilePasazerow;
	const int ilepasazerowMax = 300;
	Pasazer* pasazerowie;
public:
	Lot();
	Lot(const Lot&);
	Lot(string data, string cel);
	int getNrLotu();
	string getCelLotu();
	void setPasazer(Pasazer&);
	~Lot();
};