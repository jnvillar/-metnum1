#include <sstream>
#include <fstream>
#include "Matriz.cpp"
#include "genRand.cpp"


void imprimirVector(vector<int> v)
{
	cout << "(";
	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
		{
			cout << v[i];
		}
		else
		{
			cout << v[i] << ",";
		}
	}
	cout << ")" << endl;
}

int partidosCon(int a, vector<int> rivales)
{
	int cantidad_jugados = 0;
	for (int i = 0; i < rivales.size(); i++)
	{
		if (rivales[i] == a) cantidad_jugados++;
	}
	return cantidad_jugados;
}

Matriz armarColleyMatrix(vector<int> jugados, vector<int> ganados, vector< vector<int> > rivales)
{
	vector<float> termIndep;
	vector< vector<float> > m;
	for (int i = 0; i < jugados.size(); i++){
		vector<float> fila_i;
		for (int j = 0; j <= jugados.size(); j++){
			if (i == j){
				float m_ij = 2 + jugados[i];
				fila_i.push_back(m_ij);
			}else if (j == jugados.size()){
				float a = ganados[i] - (jugados[i] - ganados[i]);
				float termIndep_i = 1 + a/2;
				termIndep.push_back(termIndep_i);
			}else{
				float m_ij = (-1)*(partidosCon(j, rivales[i]));
				fila_i.push_back(m_ij);
			}	
		}
		m.push_back(fila_i);
	}
	pair<int,int> aux;
	vector<pair<int,int> > partidos(ganados.size(),aux);
	for (int i = 0; i < partidos.size(); ++i){
		partidos[i].first = ganados[i];
		partidos[i].second = jugados[i]-ganados[i];

	}

	Matriz colley_matrix(m, termIndep, partidos);
	//FILE* aux = fopen("mat.txt", "w");
	//colley_matrix.ImprimirMatriz(aux);
	return colley_matrix;  
}

Matriz parser(char* file) 
{
	bool debug = true; // Si dejamos esto en true muestra la info que va parseando
	vector<float> vec;
	
	ifstream in(file);
	Matriz colley_matrix;
	if (in.is_open()){
		// Parseo de la primer línea
		string str;
		getline(in, str);
		istringstream ist;	
		ist.str(str);
		str.clear();

		int equipos;
		int partidos;

		ist>>equipos;
		ist>>partidos;

		vector<int> jugados(equipos,0);
		vector<int> ganados(equipos,0);
		vector<int> vacio;
		vector< vector<int> > rivales(equipos, vacio);
		vector<float> termIndep(equipos,0);

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
			} else {
				ganados[equipo1]++;	
			}
			jugados[equipo1]++;
			jugados[equipo2]++;
			rivales[equipo1].push_back(equipo2);
			rivales[equipo2].push_back(equipo1);

		}
		/*
		if (debug){
			for(int i = 0; i < jugados.size(); i++){
				cout << "Equipo: " << i << endl;
				cout << "Jugados: " << jugados[i] << endl;
				cout << "Ganados: " << ganados[i] << endl;
				cout << "Rivales: ";
				imprimirVector(rivales[i]);
				cout << "--------------------------------------" << endl;
			}
		}
		*/
		colley_matrix = armarColleyMatrix(jugados, ganados, rivales);

	} else {
		cout << "No se pudo abrir el archivo." << endl;
	}
	return colley_matrix;
}


Matriz parser(char* file, int equipo) 
{

	bool debug = true; // Si dejamos esto en true muestra la info que va parseando
	vector<float> vec;
	
	ifstream in(file);
	Matriz colley_matrix;
	if (in.is_open()){
		// Parseo de la primer línea
		string str;
		getline(in, str);
		istringstream ist;	
		ist.str(str);
		str.clear();

		int equipos;
		int partidos;

		ist>>equipos;
		ist>>partidos;

		vector<int> jugados(equipos,0);
		vector<int> ganados(equipos,0);
		vector<int> vacio;
		vector< vector<int> > rivales(equipos, vacio);
		vector<float> termIndep(equipos,0);

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

			if(equipo1 != equipo && equipo2 != equipo){
				if (goles1 < goles2){
					ganados[equipo2]++;
				}else{
					ganados[equipo1]++;	
				}
			}else{
				if(equipo1 == equipo){
					ganados[equipo1]++;
				}else{
					ganados[equipo2]++;
				}
			}
			jugados[equipo1]++;
			jugados[equipo2]++;
			rivales[equipo1].push_back(equipo2);
			rivales[equipo2].push_back(equipo1);

		}
		/*
		if (debug){
			for(int i = 0; i < jugados.size(); i++){
				cout << "Equipo: " << i << endl;
				cout << "Jugados: " << jugados[i] << endl;
				cout << "Ganados: " << ganados[i] << endl;
				cout << "Rivales: ";
				imprimirVector(rivales[i]);
				cout << "--------------------------------------" << endl;
			}
		}
		*/
		colley_matrix = armarColleyMatrix(jugados, ganados, rivales);

	} else {
		cout << "No se pudo abrir el archivo." << endl;
	}
	return colley_matrix;
}