#include "File.h"

void File::doPliku(Pasazer przykladowaOsoba)
{
	fstream out;
	out.open("bilet.txt", ios::app);
	if (!out.good())
		return;
	out << "Bilet: " << endl;
	out << przykladowaOsoba;
	out.close();
}

File::File(){}

File::~File(){}
