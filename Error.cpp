#include "Error.h"

const char * Error::what()
{
	return nullptr;
}

Error::Error(){}

const char * JestCyfra::what()
{
	return "Znaleziono cyfr� - wpisz jeszcze raz";
}

JestCyfra::JestCyfra(){}

const char * JestLitera::what()
{
	return "Znaleziono liter� - wpisz jeszcze raz";
}

JestLitera::JestLitera(){}

