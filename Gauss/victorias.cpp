
int rankingWP(char* input, char* output){

	vector<int> jugados;
	vector<int> ganados;
	int equipos;
	int partidos;
	
	ifstream in(input);
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
			} else {
				ganados[equipo1]++;	
			}
			jugados[equipo1]++;
			jugados[equipo2]++;		
		}	

		FILE* out = fopen(output, "w");
		for(int i = 0; i< equipos; i++){
			float res = (float) ganados[i]/ (float)jugados[i];
			fprintf(out, "%f\n", res);
		}
		fclose(out);
	} else{
		cout << "No se pudo abrir el archivo" << endl;
	}
		
	return 0;
  
}