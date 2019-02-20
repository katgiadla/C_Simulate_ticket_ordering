#pragma once
#include <iostream>
#include <exception>
#include <string>

using namespace std;

class Error : public exception {
public:
	virtual const char* what();
	Error();
};

class JestCyfra : public Error {
public:
	const char* what() override;
	JestCyfra();
};

class JestLitera : public Error {
public:
	const char* what() override;
	JestLitera();
};