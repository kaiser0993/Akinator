#pragma once
#include <iostream>
#include <string>

class MyError{
public:
	int motivo;
	MyError(int m);
	const char* porque() const throw();
};