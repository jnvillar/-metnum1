#include <sstream>
#include <fstream>
#include <vector>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <algorithm>




using namespace std;

int main(int argc, char* argv[])
{

	vector<float> rankingEquipos;
	if (argc != 3){
		printf("%s [INPUT FILE (ranking)] [INPUT FILE (partidos a analizar)]\n", argv[0]);
		return 0;
	} 

	ifstream in(argv[1]);
	if (in.is_open()){
		string str;

		istringstream ist;	
		ist.str(str);
		str.clear();

		string st;
		while (getline(in, st)){
			istringstream iss;
			iss.str(st);

			//Aca extraemos la info de la línea en la que estamos

			float ranking;
			iss>> ranking;
			rankingEquipos.push_back(ranking);

		}	

	}

	int predAcertadas = 0;
	ifstream in2(argv[2]);
	if (in.is_open()){
		string st2;
		while (getline(in2, st2)){
			istringstream iss2;
			iss2.str(st2);

			//Aca extraemos la info de la línea en la que estamos

			int fecha;
			iss2>> fecha;
			int equipo1;
			iss2>> equipo1;
			equipo1--;		// Asi el equipo 1 es el 0 
			int goles1;
			iss2>> goles1;
			int equipo2;
			iss2>> equipo2;
			equipo2--;
			int goles2;
			iss2>> goles2;

			if (goles1 > goles2){
				if (rankingEquipos[equipo1] > rankingEquipos[equipo2]){
					predAcertadas++;
				}
			} else {
				if (rankingEquipos[equipo1] < rankingEquipos[equipo2]){
					predAcertadas++;
				}	
			}
			if (rankingEquipos[equipo1] == rankingEquipos[equipo2]){
				// QUE CARAJO PASA?
			}


		}	

	}
	
	cout << predAcertadas << endl;
	return 0;
  
}