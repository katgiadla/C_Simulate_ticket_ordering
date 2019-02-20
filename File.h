#pragma once
#include <iomanip>
#include <iostream>
#include <iostream>
#include "Pasazer.h"
#include <fstream>
#include <string>

using namespace std;

class Pasazer;

class File
{
public:
	static void doPliku(Pasazer);
	File();
	~File();
};