#include <time.h>
#include <vector>
//#include <algorithm>
//#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
//#include <math.h>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h> // para rand
#include "parser.cpp"

using namespace std;

//NO USAR LOS 2 define A LA VEZ PORQUE SE ROMPE TODO
#define FUNC //Este define es para usarlo como funcion
//#define ARG //Este define es para usarlo como main

#ifdef ARG
// Este generador deja la matriz fija y va cambiando el termino independiente. En la iteración i se computa el tiempo de haber resuelto i sistemas con
// Gauss y con Cholesky 
int main(int argc, char* argv[]){

	if (argc != 6)
	{
		printf("%s [Cantidad de equipos] [Cantidad de partidos] [Cantidad de sistemas] [OUTPUT FILE FOR GAUSS] [OUTPUT FILE FOR CHOLESKY] \n", argv[0]);
	}
	else
	{
#endif //ARG


#ifdef FUNC
void testMFTamFijo(int cantEquipos, int cantPartidos, int cantSistemas, char* file_gauss, char* file_cholesky)
{
#endif //FUNC


#ifdef ARG
		int cantEquipos = atoi(argv[1]);
		int cantPartidos = atoi(argv[2]);
		int cantSistemas = atoi(argv[3]);
		char* file_gauss = argv[4];
		char* file_cholesky = argv[5]; 
#endif

		srand(time(NULL));
		cout << "Cantidad de equipos: "<< cantSistemas << endl;
		cout << "Cantidad de partidos: "<< cantPartidos << endl;
		cout << "Cantidad de sistemas: "<< cantSistemas << endl;
		cout << "Procesando..." << endl;
		
		
		// Aca armamos el fixture. Lo guardamos porque queremos que la matriz no cambie.
		// PUEDE HABER EQUIPOS SIN JUGAR
		vector< vector<int> > fixture;
		for (int i = 0; i<cantPartidos; i++)
		{
			int equip1 = (rand()%cantEquipos)+1;
			int equip2 = (rand()%cantEquipos)+1;
			if (equip1 != equip2)
			{
				vector<int> partido;
				partido.push_back(equip1);
				partido.push_back(equip2);
				fixture.push_back(partido);
			} 
			else
			{
				i--;
			}
		}

		float tiempoGauss = 0;
		float tiempoCholesky = 0;
		Matriz m_cholesky;
		for (int i = 0; i < cantSistemas; i++)
		{

			//Aca hacemos random el resultado de los partidos del fixture
			FILE* partidos = fopen("fixture.in", "w");
			fprintf(partidos, "%d %d\n", cantEquipos, cantPartidos);
			for (int j = 0; j < fixture.size(); j++)
			{
				int resultado = rand() % 100 + 1;
				int goles1;
				int goles2;
				if (resultado < 50)
				{
					goles1 = 1;
					goles2 = 0;
				} 
				else
				{
					goles1 = 0;
					goles2 = 1;
				}

				fprintf(partidos, "1 %d %d %d %d\n", fixture[j][0], goles1, fixture[j][1], goles2);
			}
			fclose(partidos);

			
			Matriz m_gauss = parser("fixture.in");  //Generamos la matriz a partir del archivo de datos
			// En la primer iteracion cholesky va a tener que encontrar la L 
			if (i == 0)
			{
				m_cholesky = m_gauss;
			}
			// Aca cholesky ya tiene la L, solo cambia el termino independiente	
			else
			{
				vector<float> nuevo_res = m_gauss.devolverRes();
				m_cholesky.cambiarRes(nuevo_res);
			}
			
			//Medimos el tiempo que toma Gauss
			FILE * outGauss;
			if (i == 0)
			{
				outGauss = fopen(file_gauss, "w");
			}
			else
			{
				outGauss = fopen(file_gauss, "a");
			}
			clock_t t = clock();
			m_gauss.Gauss0();
			m_gauss.resolverTriangSup();
			t = clock() - t;

			tiempoGauss = tiempoGauss + (((float)t)/CLOCKS_PER_SEC);
			fprintf(outGauss, "%f\n", tiempoGauss);
			fclose(outGauss);

			// Medimos el tiempo que toma Cholesky
			FILE * outCholesky;
			if (i == 0)
			{
				outCholesky = fopen(file_cholesky, "w");
				t = clock();
				m_cholesky.cholesky();
			    m_cholesky.resolverTriangInf();
			    m_cholesky.resolverTriangSupTraspuesta();
				t = clock() - t;
			}
			else
			{
				outCholesky = fopen(file_cholesky, "a");
				t = clock();
				m_cholesky.resolverTriangInf();
		    	m_cholesky.resolverTriangSupTraspuesta();
				t = clock() - t;
			}

			tiempoCholesky = tiempoCholesky + (((float)t)/CLOCKS_PER_SEC);

			fprintf(outCholesky, "%f\n", tiempoCholesky);
			fclose(outCholesky);
		}


		cout << "Terminado" << endl;

	}

#ifdef ARG	
	return 0;
}
#endif