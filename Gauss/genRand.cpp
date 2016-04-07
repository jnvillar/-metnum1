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
