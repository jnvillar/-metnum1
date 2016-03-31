#include <time.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void generador(int equipos, int enfrentamientos, char* ruta){
	
	srand(time(NULL));
	int cantEquipos = equipos;
	int cantPartidos = enfrentamientos;	

	FILE* out = fopen(ruta, "w");

	fprintf(out, "%d %d\n", cantEquipos, cantPartidos);

	// PUEDE HABER EQUIPOS SIN JUGAR
	for (int i = 0; i<cantPartidos; i++){
		int equip1 = (rand()%cantEquipos)+1;
		int equip2 = (rand()%cantEquipos)+1;
		if (equip1 != equip2){
			fprintf(out, "1 %d 1 %d 0\n", equip1, equip2);
		} else{
			i--;
		}
	}
	fclose(out);  
}
/*
int CHUPALA(int argc, char* argv[]){	

	
	if (argc != 4 ){
		printf("%s [Cantidad de equipos] [Cantidad de partidos] [OUTPUT FILE]\n", argv[0]);
	} else{
		srand(time(NULL));
		int cantEquipos = atoi(argv[1]);
		int cantPartidos = atoi(argv[2]);



		FILE* out = fopen(argv[3], "w");

		fprintf(out, "%d %d\n", cantEquipos, cantPartidos);
		
		

		// PUEDE HABER EQUIPOS SIN JUGAR
		for (int i = 0; i<cantPartidos; i++){
			int equip1 = (rand()%cantEquipos)+1;
			int equip2 = (rand()%cantEquipos)+1;
			if (equip1 != equip2){
				fprintf(out, "1 %d 1 %d 0\n", equip1, equip2);
			} else{
				i--;
			}
		}
		fclose(out);
	}
	
	return 0;
  
}
*/