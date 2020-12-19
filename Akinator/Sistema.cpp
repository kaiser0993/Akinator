#include "Sistema.h"
#include <typeinfo>
#define _SECURE_SCL 1	// evita un tipo de error 


	Arbol * arb;
	Interfaz * interfaz;
	list<Nodo*>l;

Sistema::Sistema(){
	arb = new Arbol();
	interfaz = new Interfaz();
	interfaz->cargar(arb,l);
	//interfaz->CrearArbol(arb);
}


void Sistema::Correr(){
	char op ='0';
		do{
			op = interfaz->menu();
			switch(op){
				case '1':{
					Juego();
					break;
				}
				case '2':{
					Organizar();
					break;
				}
				case '0':{
						break;
				}
				default:{
						cout << " OPCION NO VALIDA " << endl;
						cin.get();
						cin.get();
						system("cls");
						break;
				}
			}
			system("cls");
		}while(op!='0');

		try{
			delete interfaz;
		}catch(...){
			cout << "\n\n\n   SE A PRODUCIDO UN ERROR INESPERADO \n" <<
					"   AL MOMENTO DE ELIMIANR LAS LISTAS \n" <<
					"   EL PROGRAMA CONTINUARA CERRANDOSE.";
			cin.get(),cin.get();
		}
}




	
void Sistema::Juego(){
	system("cls");
	interfaz->Jugar(arb);

}

void Sistema::Organizar(){
	system("cls");
	interfaz->cambiarPos(arb);
}

Sistema::~Sistema(){}