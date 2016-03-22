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
					}					
										
					int aux = m[j][i]/m[i][i];					
					res.Cambiar(j,i,aux);
					m[j][i] = m[j][i]-aux*m[i][i];			
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

	

	vector< int > a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(4);
	vector< int > b;
	b.push_back(1);
	b.push_back(0);
	b.push_back(3);
	b.push_back(3);
	b.push_back(4);
	vector< int > c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	c.push_back(3);
	c.push_back(4);
	vector< int > d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(3);
	d.push_back(4);
	vector< int > f;
	f.push_back(1);
	f.push_back(2);
	f.push_back(3);
	f.push_back(3);
	f.push_back(4);

	vector< vector <int> > m;
	m.push_back(a);
	m.push_back(b);
	m.push_back(c);
	m.push_back(d);
	m.push_back(f);

	vector<int> p;
	p.push_back(1);
	p.push_back(2);
	p.push_back(3);
	p.push_back(4);
	p.push_back(5);
	p.push_back(6);

	Matriz h(m);
	
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