#include "tablero.h"
#include <iostream>


using std::cin;
using std::cout;
using std::endl;

tablero::tablero(){
	int size=11;
	crear_tablero=new char* [size];
	for(int i=0;i<size; i++){
		crear_tablero[i]=new char [size];	
	}
	
	for (int i = 0; i <size; ++i){
		for (int j = 0; j < size; ++j){
			crear_tablero[i][j]=' ';
		}
	}

	crear_tablero[0][5]='+';
	crear_tablero[10][5]='+';
	crear_tablero[5][0]='#';
	crear_tablero[5][10]='#';
}


void tablero::imprimir(){
	for (int i = 0; i < 11; ++i){
		for (int j = 0; j < 11; ++j){
			cout<<"[ "<<crear_tablero[i][j]<<" ]";
		}
	}
	cout<<endl;
}

void tablero::clonar(char** matriz, int x, int y, int jugador){
	if(jugador==1)
		matriz[x][y]='+';
	else
		matriz[x][y]='#';	
}







/*bool tablero::verificar(){
	int contMenos,contMas,cont=0;
	for (int i = 0; i < 11; ++i){
		for (int j = 0; j < 11; ++j){
			if (this->matriz[i][j]==' '){
				cont++;
			}else{
				if (this->matriz[i][j]=="#"){
					contMenos++;
				}else{
					if (this->matriz[i][j]=="+"){
						contMas++;
					}
				}
			}

		}// fin for2
	}// fin for1

	if(cont==0){
		if(contMenos>=0 && conMas!=0){
			cout<<"Ganaron los +"<<endl;
			return true;
		}
		if(contMenos!=0 && contMas==0){
			cout<<"Ganaron los #"<<endl;
			return true;
		}
		if(contMas==contMenos){
			cout<<"Empate"<<endl;
		}

	}
	return false;

} // FIN VERIFICAR
*/