#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
#include "MyError.h"
using namespace std;


MyError::MyError(int m):motivo(m){}
	
const char* MyError::porque() const throw(){
	system("cls");
	system("color A0");
	switch(motivo){
			case 1:
				return "\n\n\n"
							"  ------------------------------------------- \n"
							"  ||                                       || \n"
							"  ||  No esta digitando una opcion valida  || \n"
							"  ||           Intente de nuevo            || \n"
							"  ||                                       || \n"
							"  ------------------------------------------- \n";
				break;			
				
	}

		return "\n\n\n   SE A GENERADO UN ERROR INESPERADO \n\n\n";
}
		
		//return 0;
		
		
		
		
		
	