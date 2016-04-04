#include <sstream>
#include <fstream>
#include <vector>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>  
#include "parser.cpp"




using namespace std;

int main(int argc, char* argv[])
{
	bool debug = true;
	vector< vector< pair<int, int> > >resultados;
	vector<int> jugados;
	vector<int> ganados;
	int equipos;
	int partidos;
	if (argc != 3){
		printf("%s [INPUT FILE] [OUTPUT FILE]\n", argv[0]);
	} else{
		ifstream in(argv[1]);
		if (in.is_open()){
			string str;
			getline(in, str);
			istringstream ist;	
			ist.str(str);
			str.clear();
			ist>>equipos;
			ist>>partidos;
			for (int i = 0; i<equipos; i++){
				jugados.push_back(0);
				ganados.push_back(0);
				vector<pair<int, int> > fila;
				for(int j = 0; j<equipos; j++)
				{
					pair<int, int> p(0,0);
					fila.push_back(p);
				}
				resultados.push_back(fila);
			}


			// Parseo del resto del archivo
			string st;
			while (getline(in, st)){
				istringstream iss;
				iss.str(st);

				//Aca extraemos la info de la línea en la que estamos

				int fecha;
				iss>> fecha;


				int equipo1;
				iss>> equipo1;
				equipo1--;		// Asi el equipo 1 es el 0 
				int goles1;
				iss>> goles1;
				int equipo2;
				iss>> equipo2;
				equipo2--;
				int goles2;
				iss>> goles2;

				if (goles1 < goles2){
					ganados[equipo2]++;
					resultados[equipo1][equipo2].second++;
					resultados[equipo2][equipo1].first++;
				} else {
					ganados[equipo1]++;	
					resultados[equipo1][equipo2].first++;
					resultados[equipo2][equipo1].second++;
				}
				jugados[equipo1]++;
				jugados[equipo2]++;		

			}	

			if (debug)
			{
				cout << "Jugados: ";
				imprimirVector(jugados);
				cout << "Ganados: ";
				imprimirVector(ganados);

				for (int i = 0; i<resultados.size(); i++)
				{
					if (i == 0) cout << "       ";
					cout << "  " << "E" << i+1 << "   "; 
					if (i == resultados.size() - 1) cout << endl; 
				}
				for (int k = 0; k<resultados.size(); k++)
				{
					for (int j = 0; j<resultados.size(); j++)
					{

						if (j == 0)
						{
							if (k < 9) cout << "  E" << k+1 << "   ";
							else cout << "  E" << k+1 << "  ";
						}
						cout << "  " << resultados[k][j].first << "-" << resultados[k][j].second << "  ";
						if (j == resultados.size() - 1) cout << endl;
					}
				}

			}

			FILE* out = fopen(argv[2], "w");
			for(int i = 0; i< equipos; i++){
				float res = (float) ganados[i]/ (float)jugados[i];
				fprintf(out, "%f\n", res);
			}
			fclose(out);
		}
		else
		cout << "No se pudo abrir el archivo" << endl;

	}
	
	return 0;
  
}