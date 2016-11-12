#include <iostream>
#include "tablero.h"

#include <time.h>
#include <cstdlib>
#include <math.h> 

using std::cin;
using std::cout;
using std::endl;

void matriz (char** m);
void liberar_Memoria(char** m);
void llenar (char** m);
void imprimir (char** m);
void jugador1 (char** m ,int x ,int y , int a , int b);
void jugador2 (char** m ,int x ,int y , int a , int b);

bool jugando = true;
int jugador =1;

int main(int argc, char const *argv[]){
	cout<<"POR NO IR A CLASES NO SE COMO USAR CLASES :( "<<endl;
	char** m = new char*[11];
	int posicionx=0,posiciony=0,posicionx2=0,posiciony2=0;
	matriz (m);
	llenar(m);
	while(jugando){
		if ((posicionx>=0 && posicionx<=11) && (posiciony>=0 && posiciony<=11) && (posicionx2>=0 && posicionx2<=11) && (posiciony2>=0 && posiciony2<=11)){
	 		if(jugador==1){
		 		cout<< "------------ Jugador 1 ------------"<<endl;
		 		cout<<"JUGADOR 1 = +"<<endl;
		 		imprimir (m);
		 		jugador=2;
		 		cout << "Posicion inicial (x): "<<endl;
		 		cin >> posicionx;
		 		cout << "Posicion inicial (y): "<<endl;
		 		cin >> posiciony;
		 		cout << "Posicion FINAL (x):"<<endl;
		 		cin >> posicionx2;
		 		cout << "Posicion FINAL (y): "<<endl;
		 		cin >>posiciony2;
		 		if ((posicionx>=0 && posicionx<=11) && (posiciony>=0 && posiciony<=11) && (posicionx2>=0 && posicionx2<=11) && (posiciony2>=0 && posiciony2<=11)){
		 			jugador1 (m,posicionx,posiciony,posicionx2,posiciony2);
		 		}else{
		 			cout<< "Fuera de rango"<<endl;
		 		}
		 		
		 	}

		 	if(jugador==2){
		 		cout<< "------------ Jugador 2 ------------"<<endl;
		 		imprimir (m);
		 		jugador=1;
		 		cout << "Posicion inicial (x): "<<endl;
		 		cin >> posicionx;
		 		cout << "Posicion inicial (y): "<<endl;
		 		cin >> posiciony;
		 		cout << "Posicion FINAL (x):"<<endl;
		 		cin >> posicionx2;
		 		cout << "Posicion FINAL (y): "<<endl;
		 		cin >>posiciony2;
		 		if ((posicionx>=0 && posicionx<=11) && (posiciony>=0 && posiciony<=11) && (posicionx2>=0 && posicionx2<=11) && (posiciony2>=0 && posiciony2<=11)){
		 			jugador2 (m,posicionx,posiciony,posicionx2,posiciony2);
		 		}else{
		 			cout<< "Fuera de rango"<<endl;
		 		}
		 		
		 	}
		 	int contador5;
		 	for(int i =0; i<11;i++){
		    	for(int j =0 ;j<11 ;j++){
			  		if (m[i][j] != ' '){
			  			contador5++;
			  		}
		    	}
		    }
		    if (49<=contador5){
		    	cout<< "Gano El jugador "<<jugador <<endl;
		    	jugando = false;
		    }
		    int cont ;
		    cout << "Desea salir del juego ingrese 1?"<<endl;
		    cin >> cont;
		    if (cont==1){
		    	jugando = false;
		    }
		}
	}

	liberar_Memoria(m);

	return 0;
}



void matriz (char** m){
	for (int i =0; i<11 ;i++){
		m[i]=new char[11];
    }
}

void liberar_Memoria(char** m){
	for(int i =0 ; i <11;i++){
	   delete[] m[i];
	}
	delete[] m;
}

void llenar (char** m){
	for(int i =0; i<11;i++){
		for(int j =0 ;j<11;j++){
			m[i][j]=' ';
		}
	}
	m[0][5]='#';
	m[10][5]='#';
	m[5][0]='+';
	m[5][10]='+';	
}

void imprimir (char** m){
	for(int i =0; i<11;i++){
	    for(int j =0 ;j<11 ;j++){
	    	cout << " [ "<< m[i][j] <<" ]";
	    }
	    cout << endl;
	}	
}

void jugador1 (char** m ,int x ,int y , int a , int b){
	int g=0,h=0;
	g = abs(x-a);
	h = abs(y-b);
	cout <<g<<endl;
	cout << h<<endl;
    
	if(g<=2 && h<=2){
		if((g==2 && h ==0)||(g==0 && h ==2)){
			if (m[x][y]=='+'&& m[a][b]!='#'){
				if((y-b)==-2){
            		m[a][b-1]='+';
            		m[a][b]='+';
            	}
		    	if ((y-b)== 2 && m[a][b]!='#'){
		    		m[a][b+1]='+';
            		m[a][b]='+';
		    	}
				if((x-a)==-2 && m[a][b]!='#'){
            		m[a-1][b]='+';
            		m[a][b]='+';
			
		   		}
		    	if ((x-a)== 2 && m[a][b]!='#'){
		    		m[a+1][b]='+';
            		m[a][b]='+';
		    	}

		    }else{
				cout << "Perdio turno"<<endl;
		   		cout <<(y-b)<<endl;
		   	}
		}
		if(g<=1 && h<=1){
			if (m[a][b]=='#'){
				m[a][b]='+';
				cout<< "se comio una pieza del jugador 2"<<endl;
			}
		}
	}else{//
		cout<< "No se puede mover mas de 2 espacios"<<endl;
	}
    
}

void jugador2 (char** m ,int x ,int y , int a , int b){
	int g=0,h=0;
	g = abs(x-a);
	h = abs(y-b);
	cout <<g<<endl;
	cout << h<<endl;
    
	if(g<=2 && h<=2){
		if((g==2 && h ==0)||(g==0 && h ==2)){
			if (m[x][y]=='#'&& m[a][b]!='+'){
				if((y-b)==-2){
            		m[a][b-1]='#';
            		m[a][b]='#';
            	}
		    	if ((y-b)== 2 && m[a][b]!='+'){
		    		m[a][b+1]='#';
            		m[a][b]='#';
		    	}
				if((x-a)==-2 && m[a][b]!='+'){
            		m[a-1][b]='#';
            		m[a][b]='#';
		   		}
		    	if ((x-a)== 2 && m[a][b]!='+'){
		    		m[a+1][b]='#';
            		m[a][b]='#';
		    	}

		    }else{
				cout << "Perdio turno"<<endl;
		   		cout <<(y-b)<<endl;
		   	}
		}
		if(g<=1 && h<=1){
			if (m[a][b]=='+'){
				m[a][b]='#';
				cout<< "se comio una pieza del jugador 1"<<endl;
			}
		}
	}else{//
		cout<< "No se puede mover mas de 2 espacios"<<endl;
	}
    
}