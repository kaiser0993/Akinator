#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Nodo{
private:
	
	Nodo * der;
	Nodo * izq;
	friend class Arbol;
	
public:
	string word;
	int tipo;
	Nodo();
	Nodo(string,Nodo*,Nodo*, int);
	Nodo(string word, int type);
	~Nodo();
	void setDer(Nodo * p);
	void setIzq(Nodo * p);
	Nodo * getDer();
	Nodo * getIzq();
	string getWord();
	void setWord(string wor);
	string toString();
	void setTipo(int);
	int getTipo();
	//sobrecarga del operador de salida para grabar en disco
    friend ostream & operator<<(ostream&, const Nodo&);
    //sobrecarga del operador deentrada para leer en disco
    friend istream & operator>>(istream&,Nodo&);  
   bool esCaracteristica();
};
