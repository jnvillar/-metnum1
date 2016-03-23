#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

 using namespace std;

class Matriz{

	private:
		vector< vector <float> > m;
		int filas;
		int columnas;
		vector <float> result;

	public:	


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
					for (int j = 0; j<columnas; j++){
						m[h][j] = m[h][j]-aux*m[i][j];
					}
					result[h] = result[h]-aux*result[i];

				}
			}
		
		}

		void cholesky(){
			vector< vector <float> > l;
			for (int i = 0; i < filas; ++i){
				vector< float> fila;
				for (int j = 0; j < filas; ++j){					
					fila.push_back(0);
				}
				l.push_back(fila);
			}

			for(int i = 0; i<filas; i++){
				for(int j = 0; j<=i; j++){
					if (i == j){
						float sumCuad = 0;
						for(int h = 0; h<i; h++){
							sumCuad += l[i][h]*l[i][h]; 
						}
						l[i][i] = sqrt(m[i][i]-sumCuad);
						
					} else{
						float suma = 0;
						for(int h = 0; h<i-1; h++){
							suma += l[i][h]*l[j][h]; 
						}
						l[i][j] = (m[i][j]-suma)/l[j][j];
						
				}
			}
			m = l;
		}
		
		
};



int main() {

	

    vector< vector<float> > a;
    vector<float> f1;
    vector<float> f2;
    vector<float> f3;
    vector<float> f4;
    vector<float> f5;
    f1.push_back(5);
    f1.push_back(0);
    f1.push_back(-1);
    f1.push_back(-1);
    f1.push_back(-1);
    f2.push_back(0);
    f2.push_back(4);
    f2.push_back(-1);
    f2.push_back(0);
    f2.push_back(-1);
    f3.push_back(-1);
    f3.push_back(-1);
    f3.push_back(6);
    f3.push_back(-1);
    f3.push_back(-1);
    f4.push_back(-1);
    f4.push_back(0);
    f4.push_back(-1);
    f4.push_back(4);
    f4.push_back(0);
    f5.push_back(-1);
    f5.push_back(-1);
    f5.push_back(-1);
    f5.push_back(0);
    f5.push_back(5);

    a.push_back(f1);
    a.push_back(f2);
    a.push_back(f3);
    a.push_back(f4);
    a.push_back(f5);


	vector<float> res;
    res.push_back(3);
    res.push_back(2);
    res.push_back(1);
    res.push_back(1);
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
	
	//h.Imprimir();	
	//h.Gauss0();	
	h.Imprimir();
	h.cholesky();
	h.Imprimir();
	

	return 0;
}