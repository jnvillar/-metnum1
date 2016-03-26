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

    Matriz() {}

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
			// assert(es def positiva y simetrica)
			vector< vector <float> > l;
			for (int i = 0; i < filas; i++){
				vector< float> fila;
				for (int j = 0; j < filas; j++){					
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
			}
			m = l;
		}
		
		void resolverTriangInf(){
			// assert(es triangular inferior y la diagonal no tiene 0)
			for (int i = 0; i<filas; i++){
				float sumaProd = 0;
				for(int j = 0; j<i; j++){
					sumaProd += result[j]*m[i][j];
					cout << sumaProd << endl;

				}
				result[i] = (result[i] - sumaProd)/m[i][i];
			}			
		}

		void resolverTriangSup(){
			// assert(es triangular superior y la diagonal no tiene 0)
			for (int i = filas-1; i>=0; i--){
				float sumaProd = 0;
				for(int j = filas-1; j>i; j--){
					sumaProd += result[j]*m[i][j];
				}
				result[i] = (result[i] - sumaProd)/m[i][i];
			}			
		}

		void matrizTraspuesta(){
			for (int i = 0; i < filas; i++){
				for (int j = 0; j<i; j++){	
					float swap = m[i][j];				
					m[i][j] = m[j][i];
					m[j][i] = swap;
				}
				
			}
		}
};