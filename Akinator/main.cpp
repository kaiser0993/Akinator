#include "Sistema.h"

int main(){
	
	system("mode con lines=55");	// cambia el tamaño de la ventana, LINEAS
	system("mode con cols=84");		// cambia el tamaño de la ventana, COLUMNAS
	system("color 0A");				// asigna el color, fondo negro(A), letras verdes (0)


	Sistema * sistema = new Sistema();
	
		try{
			sistema->Correr();
		}
		catch(MyError& e){
			cout<<e.porque()<<endl;
			cin.get();cin.get();
		}
		catch(...){
			cout << "\n\n\n   SE A GENERADO UN ERROR INESPERADO \n" <<
					"   EL PROGRAMA PROCEDERA A CERRARSE ";
			cin.get();cin.get();
		}


	delete sistema;

	return 0;
}