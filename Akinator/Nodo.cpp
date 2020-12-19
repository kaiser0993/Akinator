#include"Nodo.h"
#define _CRT_SECURE_NO_WARNINGS

#include<fstream>

Nodo::Nodo()
{
	this->word = "";
	this->der = NULL;
	this->izq = NULL;
	this->tipo = 0;
}

Nodo::Nodo(string word,Nodo* der,Nodo * izq, int type)
{
	this->word = word;
	this->der = der;
	this->izq = izq;
	this->tipo = type;
}
Nodo::Nodo(string word, int type)
{
	this->word = word;
	this->der = NULL;
	this->izq = NULL;
	this->tipo = type;
}


Nodo::~Nodo(){}

void Nodo::setDer(Nodo * p)
{
	der = p;
}

void Nodo::setIzq(Nodo * p)
{
	izq = p;
}

Nodo * Nodo::getDer()
{
	return der;
}

Nodo * Nodo::getIzq(){
	return izq;
}

string Nodo::getWord(){
	return word;
}

void Nodo::setWord(string wor){
	word  = wor;
}

string Nodo::toString(){
	stringstream s;
	s<<endl<<endl<<"Word: "<<word<<endl;
	return s.str();
}
int Nodo::getTipo(){
	return tipo;
}

void Nodo::setTipo(int Tipo){
	tipo  = Tipo;
}

ostream & operator<<(ostream& os, const Nodo& c){
	 /*return os<<c.izq<<endl<<c.der<<endl<<c.word<<endl<<c.tipo<<endl;*/
	return os<<c.word<<endl<<c.tipo<<endl;
 }


 istream & operator>>(istream& is ,Nodo& c)
 {
	 int algo2=0;
	 string algo="";

	 getline(is,c.word,'\n');
	 getline(is,algo,'\n');
	 algo2 = atoi(algo.c_str());
	 c.tipo = algo2;
	 return is;


 }

 bool Nodo::esCaracteristica(){
	if(tipo==1)
		return true;
	else 
		return false;
 }		                          