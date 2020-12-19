#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "MyError.h"
#include"Arbol.h"
using namespace std;

class Interfaz{
	
public:

	Interfaz();
	~Interfaz();
	
	char menu();
	void CrearArbol(Arbol * arb);
	Nodo* getPrimero(Arbol * arb);
	Nodo* preguntar(Nodo* root);
	int* mostrarTipos(Nodo* root);
	void ingresarABaseDatos(Nodo* nodo);
	int validaInt(int, int, string);
	void Jugar(Arbol * arb);
	void cargar(Arbol *arb,list<Nodo*>l);
	bool Respuesta(string respuesta);
	void cambiarPos(Arbol* arb);
	Nodo* buscarNodo(Nodo* root, int pos);
	void insertarPos(Nodo* root, Nodo* nuevo, int pos);
	void eliminar(Nodo* root, int pos);
	int altura(Nodo *root);
	void generarArchivo(Arbol* arb);

	

};

