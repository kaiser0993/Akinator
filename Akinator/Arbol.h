#pragma once
#include<iostream>
#include<string>
#include <list>
#include"Nodo.h"
#include<fstream>
using namespace std;


class Arbol{
private:
	Nodo * raiz;
	list<Nodo*>l;
	void LiberaArbol(){}
public:
	Arbol();
	Arbol(Nodo*);
	~Arbol();
	Nodo * Nuevo(string);
	Nodo * SigDer(Nodo * p);
	Nodo * SigIzq(Nodo * p);
	bool EstaVacio();
	Nodo * Primero();
	void guardarEnArchivo(ofstream& fs, Nodo *A);
	void cargarDeArchivo();
	void CreaRaiz();
	void CreaRaiz(string pNom, int pTipo);
	void MostrarArbolOrd(Nodo * );
	void SetPrimero(Nodo* nuevo);
	Nodo * CambiaPrimero(Nodo* nuevo);
	void cargarLista(Arbol *arb,list<Nodo*>l);
	void cargarArbol(Arbol *arb,list<Nodo*>l);

	/*void MostrarArbolPre(Nodo * );
	void MostrarArbolPost(Nodo * );
	void CuentaNodos(Nodo * );
	int EliminaMenor(Nodo * ,Nodo * );
	void Poda(Nodo *, Nodo * );
	int Mayor(Nodo * );
	int Mayor(Nodo * , int);
	int profundidad(Nodo * );
	bool insertaOrdenado(Nodo * ,Nodo * ,Nodo * );
	bool eliminaElemento(Nodo * ,Nodo *, int);
	bool buscaElemento(Nodo * , int);*/
};