#define _CRT_SECURE_NO_WARNINGS
#include "Interfaz.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <typeinfo>
#define _SECURE_SCL 1

string nombre;
int posInsertar,posInicio;

Interfaz::Interfaz(){
	nombre="";
	posInsertar=1;
	posInicio=0;
}
Interfaz::~Interfaz(){}

char Interfaz::menu(){
	char opcion ='0';
	bool continuar=true;

	do{
		opcion='0';
		continuar = true;
		system("cls");

		cout << "\n"<<
			"     ----------------------------------------------------------  \n" <<
			"     ||                                                      ||  \n" <<
			"     ||    >>  SISTEMA INTELIGENTE DEL REINO ANIMAL  <<      ||  \n" <<
			"     ||                                                      ||  \n" <<
			"     ----------------------------------------------------------  \n" <<
			"     ||                                                      ||  \n" <<
			"     ||     1 - JUGAR                                        ||  \n" <<
			"     ||                                                      ||  \n" <<
			"     ||     2 - REORDENAR                                    ||  \n" <<
			"     ||                                                      ||  \n" <<
			"     ||                                                      ||  \n" <<
			"     ----------------------------------------------------------  \n" <<
			"                  0- SALIR                                    \n\n" <<

			"                     --> ";
			
		try{
			if(!(cin >> opcion) || opcion > '2' || opcion < '0'){	//	VALIDACION: la opcion digitada tiene que existir
				cin.clear();			//Limpia en caso de digitar una letra
				cin.ignore(255,'\n');	// averiguar que hacia
				continuar=false;		// Limpia el atributo OPCION para que no se cierre al regresar al menu
				throw (MyError(1));
			}
		}catch(MyError &e){
			cout << e.porque();
			cin.get();
			system("cls");
			system("color 0A");
		}
	}while(!continuar);

	return opcion;
}

void Interfaz::cargar(Arbol *arb,list<Nodo*>l){
	arb->cargarLista(arb,l);
}

void Interfaz::CrearArbol(Arbol *arb){
	arb->CreaRaiz();

	//creacion de nodos
	Nodo * n1 = new Nodo("reptil",NULL,NULL,3);
	Nodo * n2 = new Nodo("Aguila",NULL,NULL,2);
	Nodo * n3 = new Nodo("mamifero",NULL,NULL,3);
	Nodo * n4 = new Nodo("Lagarto",NULL,NULL,2);
	Nodo * n5 = new Nodo("pez",NULL,NULL,3);
	Nodo * n6 = new Nodo("acuatico",NULL,NULL,1);
	Nodo * n7 = new Nodo("invertebrado",NULL,NULL,3);
	Nodo * n8 = new Nodo("Beta",NULL,NULL,2);
	Nodo * n9 = new Nodo("anfibio",NULL,NULL,3);
	Nodo * n10 = new Nodo("Araña",NULL,NULL,2);
	Nodo * n11 = new Nodo("Culebra",NULL,NULL,3);
	Nodo * n12 = new Nodo("Rana",NULL,NULL,2);
	Nodo * n13 = new Nodo("maulla",NULL,NULL,1);
	Nodo * n14 = new Nodo("Ballena",NULL,NULL,2);
	Nodo * n15 = new Nodo("Perro",NULL,NULL,2);
	Nodo * n16 = new Nodo("Gato",NULL,NULL,2);

	//pegando nodos y armando el arbol
	arb->Primero()->setDer(n2);
	arb->Primero()->setIzq(n1);
	n1->setDer(n4);
	n1->setIzq(n3);
	n2->setDer(NULL);
	n2->setIzq(NULL);

	n3->setDer(n6);
	n3->setIzq(n5);

	n4->setDer(NULL);
	n4->setIzq(NULL);

	n5->setDer(n8);
	n5->setIzq(n7);

	n6->setDer(n14);
	n6->setIzq(n13);

	n7->setDer(n10);
	n7->setIzq(n9);

	n8->setDer(NULL);
	n8->setIzq(NULL);

	n9->setDer(n12);
	n9->setIzq(n11);

	n10->setDer(NULL);
	n10->setIzq(NULL);

	n11->setDer(NULL);
	n11->setIzq(NULL);

	n12->setDer(NULL);
	n12->setIzq(NULL);

	n13->setDer(n16);
	n13->setIzq(n15);

	n14->setDer(NULL);
	n14->setIzq(NULL);

	n15->setDer(NULL);
	n15->setIzq(NULL);

	n16->setDer(NULL);
	n16->setIzq(NULL);

	/*cout<<"\t\tImprime en orden\n";
	arb->MostrarArbolOrd(arb->Primero());*/

}

Nodo* Interfaz::getPrimero(Arbol *arb){
	return arb->Primero();
}

void Interfaz::Jugar(Arbol *arb){
	bool bandera = true;
	string respuesta="";
	if(nombre==""){
		cout<<"\n\n Hola!! Soy el genio que todo lo sabe ";
		cout<<"\n\n Dime tu nombre ";
		cin>>nombre;
	}
	
	for(int i=3; i>0;i--){
	  system("cls");
	  cout<<"\n\n Hola!! Soy el genio que todo lo sabe ";
	  cout<<"\n\n "<<nombre<< " piensa en un animal y yo intentare adivinarlo. ";
	  cout<<"\n Espera "<<i<<" seg" << endl;
	  Sleep(1000);
	}
		//Encicla el juego para seguir jugando
	do{
		preguntar(arb->Primero());
		system("cls");
		cout<<"\n\n "<<nombre<< " deseas volver a jugar? digita (SI o No)";
		cout<<"\n "<<nombre<<" -> ";
		cin>>respuesta;
		system("cls");
		if( Respuesta(respuesta)){
			for(int i=3; i>0;i--){
			  system("cls");
			  cout<<"\n\n Hola!! Soy el genio que todo lo sabe ";
			  cout<<"\n\n "<<nombre<< " piensa en un animal y yo intentare adivinarlo. ";
			  cout<<"\n Esperando "<<i<<" seg" << endl;
			  Sleep(1000);
			}
		}
	}while( Respuesta(respuesta));
		//Se termino el juego

		//Aqui se implementa el guardar en el arbol hay ke recorrer el arbol e ir guardando
		ofstream os("arbol.txt");
		arb->guardarEnArchivo(os, arb->Primero());
		
}
void Interfaz::generarArchivo(Arbol* arb){

	ofstream os("arbol.txt");
	arb->guardarEnArchivo(os,arb->Primero());


}


Nodo* Interfaz::preguntar(Nodo* root){
	 
	if(root){
		string respuesta = "";
		system("cls");
		cout<<"\n\n  Genio -> "<<nombre<<" estas pensando en un(a) "<< root-> getWord()<<"? Digite (SI o NO)";
		cout<<"\n  "<<nombre<<" -> ";
		cin>>respuesta;		
		if( Respuesta(respuesta)){
			
			if(root->getDer()== NULL){
				for(int i=3; i>0;i--){
					system("cls");
					cout << "\n\n  Genio -> GENIAL ENCONTRE LA RESPUETA YO GANE!!!";
					cout << "\n  ME ENCANTA JUGAR CONTIGO!!!";
					cout<<"\n  Espera "<<i<<" seg" << endl;
					Sleep(1000);
				}
				
			}else	
			preguntar(root->getDer());
			
			
		}else{

			if(root->getIzq()== NULL){
				for(int i=4; i>0;i--){
					system("cls");
					cout << "\n\n Genio -> Lo siento no conozco ese animal!";
					cout << "\n "<<nombre<<" ayudame a incluirlo!";
					cout<<"\n  Espera "<<i<<" seg" << endl;
					Sleep(1000);
				}

				ingresarABaseDatos(root);
			}else				
			 preguntar(root->getIzq());
			
		}
	}else{
		return NULL;
	}
	

}
void Interfaz::ingresarABaseDatos(Nodo* nodo){
	string respuesta;
	Nodo* nodoAnimal;	
	string animal;
	string caracteristica;
	system("cls");
	cout<<"\n\n Genio -> ACTUALICEMOS MI BASE DE DATOS...";
	cout << "\n\n "<<nombre<<" en que animal estabas pensando?";
	cout <<"\n Dime: "; 
	cin>>animal;
	cout << "\n\n Dame una caracteristica relevante que sirva para distinguirle";
	cout <<"\n Dime: ";
	cin>>caracteristica;		
	nodoAnimal = new Nodo(animal,NULL,NULL,2);
	if(nodo->getIzq()==NULL && nodo->getDer()==NULL){
		system("cls");
		Nodo* temp = new Nodo("",NULL,NULL,0);
		temp->setWord(nodo->getWord());
		temp->setTipo(nodo->getTipo());
		nodo->setWord(caracteristica);
		nodo->setTipo(1);
		nodo->setIzq(temp);		
		nodo->setDer(nodoAnimal);
		for(int i=3; i>0;i--){
			system("cls");
			cout<<"\n\n Genio -> "<<nombre<<" hemos actualizado mi base de datos...";
			cout<<"\n\n GRACIAS! "<<endl<<endl;
			cout<<"\n  Espera "<<i<<" seg" << endl;
			Sleep(1000);
		}
	}
}

bool Interfaz::Respuesta(string respuesta){
	bool resp=false;

	if(respuesta == "SI" ||respuesta == "si"||respuesta == "s"||respuesta == "S"|| respuesta == "sI"||respuesta == "Si") // Valor de retorno
		resp=true;
	return resp;
	
}

int* Interfaz::mostrarTipos(Nodo* root){
	int* rango= new int[2];
	rango[0]=0;
	rango[1]=0;
	bool continuar=true;
	Nodo* aux;
	int i=0;
	string resp="";
	if(root){
		do{
			system("cls");
			aux=root;
			i=0;
			cout<<"\n\n  Genio -> "<<nombre<<" estas son las categorias de animales"<<endl;
			while(aux->getIzq()!= NULL){
				i++;
				cout << "\n  "<< i <<" -> "<<aux->getWord();
				aux=aux->getIzq();
			}
			cout<<"\n\n  Deseas modificarlas? Digite (SI o NO) ";
			cin>>resp;
			if(Respuesta(resp)){
				cout<<"\n\n  Genio -> Digita el numero del tipo de animal a mover";
				cout<<"\n  -> ";
				cin>>rango[0];
				cout<<"\n\n  Genio -> Digita la nueva posicion del tipo de animal escogido";
				cout<<"\n  -> ";
				cin>>rango[1];
				if(rango[0]<1 || rango[0]>i || rango[1]<1 || rango[1]>i){
					cout<<"\n\n  Genio -> Digitaste una posicion invalida";
					cout<<"\n\n  Intenta de nuevo";
					continuar=false;
				}
			}
		}while(!continuar);
	}
	
	return rango;
}

int Interfaz::altura(Nodo *root){
    int ARI =0;
	if( root->getIzq()!= NULL){
       ARI = altura(root->getIzq()) + 1;
	}
	return ARI;
    
    //return (-1);
} 

void Interfaz::cambiarPos(Arbol* arb){
	int actual;
	int alt=this->altura(arb->Primero());
	Nodo *aux= arb->Primero();// variable auxiliar para el nodo a cambiar 
	Nodo *ant= arb->Primero();
	Nodo *temp, *p=NULL;
	if(nombre==""){
		cout<<"\n\n Hola!! Soy el genio que todo lo sabe ";
		cout<<"\n\n Dime tu nombre ";
		cin>>nombre;
	}
	int* rango = mostrarTipos(arb->Primero());
	posInicio= rango[0];
	posInsertar=rango[1];

	if(posInicio>1 && posInicio<=alt && posInsertar==1){///cuando se escoje posicion mayor a 1 y se desea insertar en la primera posicion
		for(actual=1; actual<(posInicio-1); aux = aux->getIzq(), actual++){}
		temp=aux->getIzq();
		aux->setIzq(temp->getIzq());		
		arb->SetPrimero(temp);
		posInicio= posInsertar=0;
	}
	if(posInicio==1 && posInsertar==alt){//cuando se escoje la primera posicion y se desea insertar en la ultima posicion
		temp=arb->CambiaPrimero(aux->getIzq());
		ant= arb->Primero();		
		for(actual=1; actual<(posInsertar-1); ant = ant->getIzq(), actual++){}
		temp->setIzq(ant->getIzq());
		ant->setIzq(temp);
		posInicio= posInsertar=0;
	}
	if(posInicio==1 && posInsertar<=alt){//cuando se escoje la primera posicion y se desea insertar en cualquier posicion
		temp=arb->CambiaPrimero(aux->getIzq());
		ant= arb->Primero();		
		for(actual=1; actual<(posInsertar-1); ant = ant->getIzq(), actual++){}
		temp->setIzq(ant->getIzq());
		ant->setIzq(temp);
		posInicio= posInsertar=0;
	}
	if(posInicio>1 && posInicio<=alt && posInsertar>0 && posInsertar<=alt){//cuando se escoje una posicion mayor a 1 y se desea insertar en la ultima posicion
		for(actual=1; actual<(posInicio-1); aux = aux->getIzq(), actual++){}
		temp=aux->getIzq();
		aux->setIzq(temp->getIzq());
		for(actual=1; actual<(posInsertar-1); ant = ant->getIzq(), actual++){}
		temp->setIzq(ant->getIzq());
		ant->setIzq(temp);
		posInicio= posInsertar=0;
		cin.get();cin.get();
	}
	
	delete [] rango;
}

Nodo* Interfaz::buscarNodo(Nodo* root, int pos){
    Nodo * aux= root;
	for(int actual=1; actual<pos; aux = aux->getIzq(), actual++){}	
	return aux;
}
void Interfaz::insertarPos(Nodo* root, Nodo* nuevo, int pos){
	while(pos<posInsertar){
		insertarPos(root->getIzq(),nuevo,pos+1);
	}	
	nuevo->setIzq(root->getIzq());
	root->setIzq(nuevo);
}
void Interfaz::eliminar(Nodo* root, int pos){
	Nodo * aux= root;
	Nodo *temp=NULL;
	for(int actual=1; actual<pos; aux = aux->getIzq(), actual++){}
	temp=aux->getIzq();
	aux->setIzq(temp->getIzq());
	delete temp;
	

}
	
	