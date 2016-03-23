#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <sstream>
#include <fstream>

 using namespace std;

class Matriz{

	private:
		vector< vector <float> > m;
		int filas;
		int columnas;
		vector <float> result;

	public:	
		Matriz(vector<int> jugPor, vector<float> ganPor){
			
			filas = jugPor.size();
			columnas =filas; 
			result = ganPor;
			vector< vector <float> > matriz;
			for (int i = 0; i < filas; ++i){
				for (int j = 0; j < columnas; ++j){
					if(i = j){
						m[i][j] = -4; //NOOOOOOOOOOOOOOOOOOOOO
					}else{
						m[i][j] = 2+jugPor[8]; //NOOOOOOOOOOOOOOOOOOOO
					}
				}
			}
		}

		Matriz(int n){
			m.clear();
			for (int i = 0; i < n; ++i){
				vector< float> fila;
				for (int j = 0; j < n; ++j){					
					fila.push_back(0);
				}
				m.push_back(fila);
			}
			filas = n;
			columnas = n;
		
		}

		Matriz(int n, vector <float> res){
			m.clear();
			for (int i = 0; i < n; ++i){
				vector< float> fila;
				for (int j = 0; j < n; ++j){					
					fila.push_back(0);
				}
				m.push_back(fila);
			}
			filas = n;
			columnas = n;
			result = res;
		
		};

		Matriz(vector< vector<float> > v, vector <float> res){
			filas = v.size();
			columnas = v[0].size();
			m = v;
			result = res;
		}


		int Filas(){
			return filas;
		}

		int Columnas(){
			return columnas;
		}
		

		void Imprimir(){

			cout << "Imprimiendo matriz" << endl;

			for (int i = 0; i < filas; i++){				
				for (int j = 0; j < columnas; j++){
					if(j == 0){cout << "|";}
						if(m[i][j]<0){					
							cout << m[i][j];
						}else{
							cout << " " << m[i][j];
						} 
					if(j == columnas-1){cout << "| " << result[i] << endl;}
					else{ cout << "  ";}									
				}			
			}
			cout << endl;
		}		


		void Gauss0(){
			// assert( existe unica soliucion)
			for (int i = 0; i<filas-1; i++){
				if (m[i][i] == 0){
					for (int u = i+1; u<filas; u++){
						if (m[u][u] != 0){
							vector<float> swap = m[u];
							m[u] = m[i];
							m[i] = swap;
							int aux2 = result[u];
							result[u] = result[i];
							result[i] = aux2;
							break;
						}
					}
				}
				for (int h = i+1; h<filas; h++){
					float aux = m[h][i]/m[i][i];			 
					for (int j = 0; j<filas; j++){
						m[h][j] = m[h][j]-aux*m[i][j];
					}
					result[h] = result[h]-aux*result[i];

				}
			}
		
		}

		void cholesky(){

		}
		
		
};

void parser() {	

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
vector<float> ganPor(equipos,0);
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
 
    
    

}



int main() {

/*
    vector< vector<float> > a;
    vector<float> f1;
    vector<float> f2;
    vector<float> f3;
    f1.push_back(3);
    f1.push_back(2);
    f1.push_back(1);
    f2.push_back(6);
    f2.push_back(4);
    f2.push_back(1);
    f3.push_back(2);
    f3.push_back(1);
    f3.push_back(3);
    a.push_back(f1);
    a.push_back(f2);
    a.push_back(f3);


	vector<float> res;
    res.push_back(3);
    res.push_back(2);
    res.push_back(1);

	Matriz h(a,res);
	
	/* Prueba gauss sin 0*/
	/*
	h.Imprimir();
	Matriz j = h.Gauss();	
	h.Imprimir();
	j.Imprimir();
	*/

	/* Prueba permutar*/
	/*
	h.Imprimir();
	h.Permutar(1,2);
	h.Imprimir();
	*/

	/* Prueba gauss con 0*/
	
	/*
	h.Imprimir();	
	h.Gauss0();	
	h.Imprimir();
	*/

	parser();

	return 0;

}
