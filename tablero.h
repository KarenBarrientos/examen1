#ifndef TABLERO_H
#define TABLERO_H

#include <cmath>

class tablero{
	private:

	public:
		tablero();
		char** crear_tablero();
		void imprimir();
		int espacios(char** , int);
		int  distancia(int ,int , int , int  );
		void comerMas(char**,int  ,int );
		void comerMenos(char**,int  ,int );
		int totalMas(char** , int );;

		~tablero(); // destructor
};

#endif