#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

 using namespace std;

class Matriz{

	private:
		vector< vector <int> > m;
		int filas;
		int columnas;
		
	public:	
		Matriz(int n){
			for (int i = 0; i < n; ++i){
				vector< int> fila;
				for (int j = 0; j < n; ++j){
					m.push_back(fila);
					m[j].push_back(0);
				}
			}
			filas = n;
			columnas = n;
		};

		Matriz(vector< vector<int> > v){
			filas = v.size();
			columnas = v[0].size();
			m = v;

		}

		Matriz(int f, int c){
			for (int i = 0; i < f; ++i){
				vector< int> fila;
				for (int j = 0; j < c; ++j){					
					m[j].push_back(0);
				}
				m.push_back(fila);
			}
			filas = f;
			columnas = c;
		};

		int Obtener(int f, int c){
			return m[f][c];
		}

		void Cambiar(int f, int c, int n){
			m[f][c] = n;
		}

		Matriz Identidad(int n){
			Matriz m = Matriz(n);
			for (int i = 0; i < n; ++i){				
				for (int j = 0; j < n; ++j){					
					if(i=j){
						Cambiar(i,j,1);										
					}
				}
			}			
		};

		int Filas(){
			return filas;
		}

		int Columnas(){
			return columnas;
		}		

		void Llenar0(){
			for (int i = 0; i < filas; ++i){				
				for (int j = 0; j < columnas; ++j){					
					Cambiar(i,j,0);	

				}
			}			

		};

		void Imprimir(){
			for (int i = 0; i < filas; i++){				
				for (int j = 0; j < columnas; j++){
					if(j == 0){cout << "| ";}					
					cout << m[i][j];
					if(j == columnas-1){cout << " |" << endl;}
					else{ cout << " ";}									
				}			
			}
		}

		void Gauss(){
			for (int i = 1; i <columnas-1; ++i){						//COLUMNAS
				for (int j = i+1; j < filas; ++j){				//FILAS
					double aux = m[j][i]/m[i][i];					
					m[j][i] = m[j][i]-(aux*m[i][j]);			
				}	
			}
		};
		
};

int main() {

	vector< int > a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	vector< int > b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	vector< int > c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);

	vector< vector <int> > m;
	m.push_back(a);
	m.push_back(b);
	m.push_back(c);

	Matriz h(m);
	
	h.Gauss();
	h.Imprimir();
	
	

	return 0;
}