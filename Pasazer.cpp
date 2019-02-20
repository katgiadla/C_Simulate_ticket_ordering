#include "Pasazer.h"
#include "Dodatkowe_funkcje.h"

Pasazer::Pasazer(){}

Pasazer::Pasazer(string noweImionaiNaz, string nowyTel, string nowyPaszport)
{
	this->imionaInazwisko = noweImionaiNaz;
	this->nrTel = nowyTel;
	this->nrPaszportu = nowyPaszport;
	this->iid++;
}

Pasazer::~Pasazer(){}

ostream & operator<<(ostream & wyj, Pasazer & przyklad)
{
	wyj << "Indywidualne id pasazera: " << przyklad.iid;
	wyj << "\nImiona i nazwisko: " << przyklad.imionaInazwisko << endl;
	wyj << "Nr paszportu: " << przyklad.nrPaszportu << endl;
	wyj << "Nr tel: " << przyklad.nrTel << endl;
	wyj << "Cel lotu: " << przyklad.celPasazera << endl;
	wyj << "Nr lotu: " << przyklad.lotPasazera << endl;
	return wyj;
}
