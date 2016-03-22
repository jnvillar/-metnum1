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

		void Permutar(int i, int j){
			vector<int> aux = m[j];
			m[j] = m[i];
			m[i] = aux;

		}		

		void Llenar0(){
			for (int i = 0; i < filas; ++i){				
				for (int j = 0; j < columnas; ++j){					
					Cambiar(i,j,0);	

				}
			}
		};

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
					if(j == columnas-1){cout << "|" << endl;}
					else{ cout << "  ";}									
				}			
			}
			cout << endl;
		}		

		Matriz Gauss(){

			Matriz res = Matriz(filas);

			for (int i = 0; i <columnas-1; ++i){						//COLUMNAS
				for (int j = i+1; j < filas; ++j){				//FILAS
					int aux = m[j][i]/m[i][i];					
					res.Cambiar(j,i,aux);
					m[j][i] = m[j][i]-aux*m[i][i];			
				}	
			}

			return res;
		};

		void Reordenar(vector<int> &p, int i, int j){
			int aux = p[i];
			p[i] = p[j];
			p[j] = aux;
		}

		Matriz Gauss0(vector<int> &p){

			Matriz res = Matriz(filas);

			for (int i = 0; i <columnas-1; ++i){						//COLUMNAS
				for (int j = i+1; j < filas; ++j){				//FILAS
					
					bool todos0 = false;
					if(m[i][i] == 0){
						int h = i;						
						while(h<columnas){
							if(m[h][i] != 0){
								Permutar(i,h);
								res.Permutar(i,h);
								Reordenar(p,i,h);
								h = h +columnas;
							}
							h++;
						}
						todos0 = true;
					}		

					if(!todos0){									
					int aux = m[j][i]/m[i][i];					
					res.Cambiar(j,i,aux);
					m[j][i] = m[j][i]-aux*m[i][i];		
					}	
				}	
			}

			return res;
		};
		
};

void Imprimir(vector<int> p){
			cout << "Imprimiendo vector de permutacion" << endl;
			for (int i = 0; i < p.size(); ++i){
				if(i == 0){cout << "[";}				
				cout << p[i];
				if(i == p.size()-1){cout << "]";}
				else{cout << ",";}
			}
			cout << endl;
			cout << endl;
}

int main() {

	

	vector< vector<int> > a;
    vector<int> f1;
    vector<int> f2;
    vector<int> f3;
    f1.push_back(3);
    f1.push_back(2);
    f1.push_back(1);
    f2.push_back(1);
    f2.push_back(4);
    f2.push_back(6);
    f3.push_back(2);
    f3.push_back(1);
    f3.push_back(3);
    a.push_back(f1);
    a.push_back(f2);
    a.push_back(f3);

	vector<int> p;
	p.push_back(1);
	p.push_back(2);
	p.push_back(3);
	p.push_back(4);
	p.push_back(5);
	p.push_back(6);

	Matriz h(a);
	
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

	/* Prueba gauss con 0 */
	
	h.Imprimir();	
	Matriz j = h.Gauss0(p);	
	h.Imprimir();
	Imprimir(p);
	j.Imprimir();
	
	

	return 0;
}