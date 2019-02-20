#pragma once
#include <iostream>
#include "Lot.h"
#include "Pasazer.h"
#include <string>

using namespace std;

class Lot;
class Pasazer;

bool CzyNieCyfra(string napis);
bool CzyNieLitera(string napis);
void UzykajNrLotu(Pasazer&, Lot&);
void UzykajCelLotu(Pasazer&, Lot&);
void DodajUzytkownika(Pasazer*, Lot&, int&);