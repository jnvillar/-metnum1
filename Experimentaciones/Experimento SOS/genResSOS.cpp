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

void generador(int equipos, int enfrentamientos, vector< pair<int, int> > resultados, char* ruta)
{
  
  srand(time(NULL));
  int cantEquipos = equipos;
  int cantPartidos = enfrentamientos;

  vector<int> ganados(equipos, 0);
  vector<int> perdidos(equipos, 0);

  FILE* out = fopen(ruta, "w");

  fprintf(out, "%d %d\n", cantEquipos, cantPartidos);

//CON ESTO NOS ASEGURAMOS DE QUE TODOS TENGAN AL MENOS 1 PARTIDO JUGADO (cantPartidos >= cantEquipos)  
  for (int i = 0; i<cantEquipos; i++)
  {
    int equip1 = i + 1;
    int equip2 = (rand()%cantEquipos)+1;
    if (equip1 != equip2 && resultados[equip1-1].first > ganados[equip1-1] && resultados[equip2-1].second > perdidos[equip2-1])
    {      
      fprintf(out, "1 %d 1 %d 0\n", equip1, equip2);
      ganados[equip1-1]++;
      perdidos[equip2-1]++;
    }        
    else
    {
      i--;
    }
  }

//ACA ARMAMOS EL RESTO DE LOS PARTIDOS
  for (int i = cantEquipos; i<cantPartidos; i++)
  {
    int equip1 = (rand()%cantEquipos)+1;
    int equip2 = (rand()%cantEquipos)+1;
    if (equip1 != equip2 && resultados[equip1-1].first > ganados[equip1-1] && resultados[equip2-1].second > perdidos[equip2-1])
    {
      fprintf(out, "1 %d 1 %d 0\n", equip1, equip2);
      ganados[equip1-1]++;
      perdidos[equip2-1]++;        
    }
    else
    {
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
    vector< pair<int, int> > resultados;
    for (int i = 0; i<atoi(argv[1]); i++)
    {
      cout << "Cantidad de ganados por el equipo " << i+1 << ": " << endl;
      int g;
      cin >> g;
      cout << "Cantidad de perdidos por el equipo " << i+1 << ": " << endl;
      int p;
      cin >> p;
      pair<int, int> res(g,p);
      resultados.push_back(res);
    }
    generador(atoi(argv[1]), atoi(argv[2]), resultados, argv[3]);
  }

}