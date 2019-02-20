#include "Lot.h"
#include <ctime>
#include <cmath>

Lot::Lot() {
	srand(time(NULL));
	this->dataiGodzina = "18/01/2018";
	this->cel = "Korea Pó³nocna";
	this->KodLotu = (rand() % 100) + 800;
	this->pasazerowie = new Pasazer[this->ilepasazerowMax];
}

Lot::Lot(const Lot & wzor)
{
	this->KodLotu = wzor.KodLotu;
	this->cel = wzor.cel;
	this->dataiGodzina = wzor.dataiGodzina;
	this->ilePasazerow = wzor.ilePasazerow;
	this->pasazerowie = new Pasazer[wzor.ilepasazerowMax];
}

Lot::Lot(string data, string cel)
{
	this->KodLotu = (rand() % 100) + 800;
	this->cel = cel;
	this->dataiGodzina;
	this->pasazerowie = nullptr;
}

int Lot::getNrLotu()
{
	return this->KodLotu;
}

string Lot::getCelLotu()
{
	return this->cel;
}

void Lot::setPasazer(Pasazer & osobanaPoklad)
{
	pasazerowie = &osobanaPoklad;
}

Lot::~Lot(){}

ostream & operator<<(ostream & wyj, Lot & przykladLot)
{
	wyj << "\nNumer lotu: " << przykladLot.KodLotu << endl;
	wyj << "Miejsce docelowe: " << przykladLot.cel << endl;
	wyj << "Data i godzina wylotu: " << przykladLot.dataiGodzina << endl;
	return wyj;
}
