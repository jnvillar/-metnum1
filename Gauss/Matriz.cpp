#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <fstream>
#include <tuple>
 using namespace std;

class Matriz{

	private:
		vector< vector <float> > m;
		int filas;
		int columnas;
		vector <float> result;		
		vector < pair<int,int> > partidos;		

	public:	

   		Matriz() {}

		Matriz(int n, vector <float> res){
			m.clear();
			
			vector<float> x(n,0);
		
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

		Matriz(vector< vector<float> > v, vector <float> res, vector<pair<int,int> > part){
			filas = v.size();
			columnas = v[0].size();
			vector<float> x(v.size(),0);			
			m = v;
			result = res;			
			partidos = part;
		}

		


		int Filas(){
			return filas;
		}

		int Columnas(){
			return columnas;
		}
		
		void cambiarRes(vector <float> res){
			result = res;
		}

		vector <float> devolverRes(){
			return result;
		}

		void ImprimirMatriz(FILE* out){
			fprintf(out, "Imprimiendo matriz\n");
			for (int i = 0; i < filas; i++){				
				for (int j = 0; j < columnas; j++){
					if(j == 0){fprintf(out, "|");}
						if(m[i][j]<0){					
							fprintf(out, "%f", m[i][j]);
						}else{
							fprintf(out, " %f", m[i][j]);							
						} 
					if(j == columnas-1){fprintf(out, "| %f\n", result[i]);}
					else{ fprintf(out, "  ");}									
				}			
			}
			fprintf(out, "\n");
		}

		void ImprimirSolucion(FILE* out){
			for (int i = 0; i < filas; i++){
				fprintf(out,"%f\n",result[i]);			
			}
		}

		void ImprimirSolucionOrdeneda(FILE* out){


			
			tuple<float,int,int,int> aux;
			vector<tuple<float,int,int,int> > ord(result.size(),aux);

			for (int i = 0; i < result.size(); ++i){
				get<0>(ord[i]) = result[i];
				get<1>(ord[i]) = i;
				get<2>(ord[i]) = partidos[i].first;
				get<3>(ord[i]) = partidos[i].second;

			}

			sort(ord.begin(),ord.end());

			for (int i = ord.size()-1; i > 0; i--){
				fprintf(out,"%s %d %f %s %d %s %d\n","Equipo",get<1>(ord[i])+1,get<0>(ord[i]),"Gano",get<2>(ord[i]), "Perdio",get<3>(ord[i]));			
			}
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
			for(int i = 0; i<filas; i++){
				for(int j = 0; j<=i; j++){
					if (i == j){
						float sumCuad = 0;
						for(int h = 0; h<i; h++){
							sumCuad += m[i][h]*m[i][h]; 
						}
						m[i][i] = sqrt(m[i][i]-sumCuad);
						
					} else{
						float suma = 0;
						for(int h = 0; h<j; h++){
							suma += m[i][h]*m[j][h]; 
						}
						m[i][j] = (m[i][j]-suma)/m[j][j];
					}	
				}
			}
		}
		
		void resolverTriangInf(){
			// assert(es triangular inferior y la diagonal no tiene 0)
			for (int i = 0; i<filas; i++){
				float sumaProd = 0;
				for(int j = 0; j<i; j++){
					sumaProd += result[j]*m[i][j];
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


		void resolverTriangSupTraspuesta(){
			// assert(es triangular inferior y la diagonal no tiene 0)
			for (int i = filas-1; i>=0; i--){
				float sumaProd = 0;
				for(int j = filas-1; j>i; j--){
					sumaProd += result[j]*m[j][i];
				}
				result[i] = (result[i] - sumaProd)/m[i][i];
			}			
		}
















		// EXPERIMENTACION


		bool estaPrimero(int equipo){

			bool res = true;
			float ranking = devolverRes()[equipo];		
			for (int i = 0; i < devolverRes().size(); ++i){
				if(i!=equipo && devolverRes()[i]>ranking){
					res = false;
					break;
				}
			}			
			return res;
		}

		int peorRanking(int equipo, vector<int> &vecesjugadas){
			int res;
			float menor = 40;
	
			for (int i = 0 ; i < filas; ++i){
				if(i != equipo && result[i]<menor && vecesjugadas[i]<0){									
					res = i;
					menor = result[i];					
				}
			}
			vecesjugadas[res]++;
			return res;
		}

		int perderpartido(vector<float> &termIndp, int equipo,vector<int> &vecesjugadas){
			int peor = peorRanking(equipo,vecesjugadas);
			partidos[equipo].first--;
			partidos[equipo].second++;
			termIndp[equipo] = (1 + ((float)partidos[equipo].first-(float)partidos[equipo].second)/2);
			partidos[peor].first++;
			partidos[peor].second--;
			termIndp[peor] = (1 + ((float)partidos[peor].first-(float)partidos[peor].second)/2);		
			cambiarRes(termIndp);
			return peor;
		}

		void ganarpartido(vector<float> &termIndp, int equipo,int ganador){
			partidos[equipo].first++;
			partidos[equipo].second--;
			termIndp[equipo] = (1 + ((float)partidos[equipo].first-(float)partidos[equipo].second)/2);
			partidos[ganador].first--;
			partidos[ganador].second++;
			termIndp[ganador] = (1 + ((float)partidos[ganador].first-(float)partidos[ganador].second)/2);

			cambiarRes(termIndp);
			resolverTriangInf();
			resolverTriangSupTraspuesta();
			
		}

		vector<int> partidosContra(int equipo){
			
			vector<int> partidosContra(filas,0);
			for (int i = 0; i < filas; ++i){
				partidosContra[i] = m[equipo][i];
			}
			return partidosContra;
		}

		void estrategia1(int equipo){		//DEBE USAR LA MATRIZ CREADA CON PARSER(CHAR* FILE,INT EQUIPO)
						
			vector<float> termIndp = devolverRes();			
			vector<int> vecesjugadas = partidosContra(equipo);
			cholesky();
			resolverTriangInf();
			resolverTriangSupTraspuesta();				
			int perdioContra;			
			
			
			if(estaPrimero(equipo)){				
				while(estaPrimero(equipo)){
					perdioContra = perderpartido(termIndp,equipo,vecesjugadas);													
					resolverTriangInf();
					resolverTriangSupTraspuesta();										
				}

				ganarpartido(termIndp,equipo,perdioContra);			
				cout << endl << "Asi quedaron los Rankings" << endl << endl;
				ImprimirSolucionOrdeneda(stdout);				
				cout << endl << "El equipo elegido quedo primero" << endl;	
				
			}else{				
				
				ImprimirSolucionOrdeneda(stdout);
				cout << endl << "No es posible que quede primero, ya gano todos los partidos y aun no alcanza" << endl;
				cout << "Con todos los partidos ganados, el equipo" << equipo << " quedo en la posición indicada en el ranking de arriba" << endl;
			}
		
		}
};
