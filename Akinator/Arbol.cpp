#define _CRT_SECURE_NO_WARNINGS
#include"Arbol.h"



Arbol::Arbol()
{
	this->raiz = NULL;

}

Arbol::Arbol(Nodo *raiz)
{
	this->raiz = raiz;

}
Arbol::~Arbol()
{
	LiberaArbol();
}

Nodo * Arbol::Nuevo(string word){
	Nodo * nuevo = new Nodo(word,NULL,NULL,0);
	//nuevo->setDer(NULL);
	//nuevo->setIzq(NULL);
	return nuevo;
}

Nodo *  Arbol::SigDer(Nodo * p){
	if(p)return p->der;
	else return p;
}

Nodo *  Arbol::SigIzq(Nodo * p)
{
	if(p)return p->izq;
    else return p;
}

bool  Arbol::EstaVacio()
{
	return  raiz == NULL;
}

Nodo *  Arbol::Primero(){
	return raiz;
}

void Arbol::SetPrimero(Nodo* nuevo){
	Nodo * temp=raiz;
	raiz=nuevo;
	raiz->setIzq(temp);
}

Nodo * Arbol::CambiaPrimero(Nodo* nuevo){
	Nodo * temp=raiz;
	raiz=nuevo;
	return temp;
}

void Arbol::CreaRaiz(){
	Nodo *nuevo = new Nodo("ave",NULL,NULL,3);
	if(!nuevo){
		cout<<"No hay memoria...\n";
		return;
	}
	raiz = nuevo;
	raiz->setDer(NULL);
	raiz->setIzq(NULL);
}

void Arbol::CreaRaiz(string pNom, int pTipo){
	Nodo *nuevo = new Nodo(pNom,NULL,NULL,pTipo);
	if(!nuevo){
		cout<<"No hay memoria...\n";
		return;
	}
	raiz = nuevo;
	raiz->setDer(NULL);
	raiz->setIzq(NULL);
}

void Arbol::MostrarArbolOrd(Nodo * root){
	if(root){
		MostrarArbolOrd(SigIzq(root));
		cout<<root->toString()<<endl;
		MostrarArbolOrd(SigDer(root));
	}
}

void Arbol::guardarEnArchivo(ofstream& fs, Nodo *A){
	l.push_back(A);
	if(A->izq)
		guardarEnArchivo(fs,A->izq);
	if(A->der)
		guardarEnArchivo(fs,A->der);
	if(A)
		fs<<*A;
}

void Arbol::cargarLista(Arbol *arb,list<Nodo*>l){
	try{
			ifstream isAr("arbol.txt", ios::in);
			if(!isAr){
				throw exception();
			}
			Nodo  *a = new Nodo();
			

			isAr >> *a;

			while(!isAr.eof()){
				l.push_front(a);
				a = new Nodo();
				isAr >> *a;
			}

			isAr.close();

		}catch(...){
			cout << "\n ALGO PASO... No se puede abrir el archivo (ERROR: C02) \n" ;
			cin.get(),cin.get();
		}	
	cargarArbol(arb,l);


}
void Arbol::cargarArbol(Arbol *arb,list<Nodo*>l){
	bool continuar = true;
	Nodo  *a = new Nodo();
	arb->CreaRaiz(l.front()->getWord(), l.front()->getTipo());
	l.pop_front();
	Nodo *rpas= NULL;
	Nodo *root=NULL;
	while(!l.empty()){
		root= raiz;
		rpas= raiz;
		a = new Nodo(l.front()->getWord(), l.front()->getTipo());
		l.pop_front();
		if(a->getTipo()==3){
			if(rpas==NULL){
				rpas=raiz;
			}
			while(root->getIzq()!=NULL){
				root= root->getIzq();
			}
			root->setIzq(a);
		}

		if(a->getTipo()==2){
			int cont=0;
			continuar=false;
			while(root->getIzq()!=NULL){
				root= root->getIzq();
				rpas= rpas->getIzq();
			}
			if(root->getDer()==NULL){
				root->setDer(a);
			}else{
				root=root->getDer();
				rpas=rpas->getDer();
				do{
					while(root->getDer()!=NULL && root->getDer()->getTipo()==1){
							root=root->getDer();
					}
					if(root->getDer()==NULL){
						root->setDer(a);
						continuar=true;
					}else{
						if(root->getIzq()!=NULL){
							root=root->getIzq();
							if(root->getTipo()==2){
								root=rpas;
								if(cont==1){
									continuar=true;
								}
								if(root->getIzq()==NULL){
									root->setIzq(a);
									continuar=true;
								}else{
									root=root->getIzq();
								}							
								cont++;
							}else{
								root=root->getIzq();
							}
						}else{
							root->setIzq(a);
							continuar=true;
							}
						}
				}while(!continuar);
			}
		}

		if(a->getTipo()==1){
			int cont=0;
			while(root->getIzq()!=NULL){
				root= root->getIzq();
				rpas= rpas->getIzq();
			}
			if(root->getDer()==NULL){
				root->setDer(a);
			}else{
				root=root->getDer();
				rpas=rpas->getDer();
				do{
					while(root->getDer()!=NULL && root->getDer()->getTipo()==1){
						root=root->getDer();
					}
					if(root->getDer()==NULL){
						root->setDer(a);
						continuar=true;
					}else{
						if(root->getIzq()!=NULL && root->getIzq()->getTipo() == 2){
							root=rpas;
							if(cont==1){
								continuar=true;
							}
							if(root->getIzq()==NULL){
								root->setIzq(a);
								continuar=true;
							}else{
								root=root->getIzq();
							}							
							cont++;
						}else{
							if(root->getIzq()!=NULL && root->getIzq()->getTipo()==1){
								root=root->getIzq();
							}else{
								root->setIzq(a);
								continuar=true;
							}
						}
					}
				}while(!continuar);
			}
		}
	}



}