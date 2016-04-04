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

//CON ESTO NOS ASEGURAMOS DE QUE TODOS TENGAN AL MENOS 1 PARTIDO JUGADO (cantPartidos >= cantEquipos)  
  for (int i = 0; i<cantEquipos; i++){
    int equip1 = i + 1;
    int equip2 = (rand()%cantEquipos)+1;
    if (equip1 != equip2){
      fprintf(out, "1 %d 1 %d 0\n", equip1, equip2);
    } else{
      i--;
    }
  }

//ACA ARMAMOS EL RESTO DE LOS PARTIDOS
  for (int i = cantEquipos; i<cantPartidos; i++){
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

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    printf("%s [Cantidad de equipos] [Cantidad de partidos] [OUTPUT FILE]\n", argv[0]);
  }
  else
  {
    generador(atoi(argv[1]), atoi(argv[2]), argv[3]);
  }

}