#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <fstream>
#include "prueba2.cpp"

using namespace std;

int main() {	

vector<float> vec;

ifstream in("prueba.in");
string str;
getline(in,str);

istringstream ist;
ist.str(str);
str.clear();

int equipos;
int partidos;

ist>>equipos;
ist>>partidos;

/* Mostrar Equipos y Cantidad de Partidos
cout << equipos << endl;
cout << partidos << endl;
*/

vector<int> jugPor(equipos,0);
vector<int> ganPor(equipos,0);
vector<float> termIndep(equipos,0);


while (in.good()){

  	vector<float> vec;
  	string st;
	getline(in, st);
	istringstream iss;
	iss.str(st);
	iss.clear();

		int fecha;
		iss>> fecha;
		int equipo1;
		iss>> equipo1;
		equipo1--;		// Asi el equipo 1 es el 0 
		int goles1;
		iss>> goles1;
		int equipo2;
		iss>> equipo2;
		equipo2--;
		int goles2;
		iss>> goles2;

	if(goles1<goles2){
		ganPor[equipo2]++;
	}
	else{
		ganPor[equipo1]++;	
	}

	jugPor[equipo1]++;
	jugPor[equipo2]++;

}

/* Para Ver lo que hay en jugPor y ganPor */

/*

for (int i = 0; i < jugPor.size(); ++i){
	cout << jugPor[i] ;
}

cout << endl;

for (int i = 0; i < ganPor.size(); ++i){
	cout << ganPor[i] ;
}

cout << endl;
*/

for (int i = 0; i < termIndep.size(); ++i){
	termIndep[i] = 1 + (ganPor[i]-(partidos - ganPor[i]))/2;
}

/*
for (int i = 0; i < termIndep.size(); ++i){
	cout << termIndep[i] ;
}

cout << endl;
*/










/*
    
    ofstream out;
    out.open("prueba.out");
    out << "probando" << endl;
    out.close();
  */
 
    
    return 0;
    

}
