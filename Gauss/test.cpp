#include "parser.cpp"

int main(){
	for (int i = 0; i<300; i++){
		srand(time(NULL));
		int cantEquipos = 100;
		int cantPartidos = 300;



		FILE* out = fopen("test.txt", "w");

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

		Matriz m1 = parser("test.txt");
		Matriz m2 = parser("test.txt");
		m1.Gauss0();
		m1.resolverTriangSup();
		m2.cholesky();
		m2.resolverTriangInf();
		m2.resolverTriangSupTraspuesta();

		FILE* out2 = fopen("resGauss.txt", "w");
		FILE* out3 = fopen("resCholesky.txt", "w");
		m1.ImprimirSolucion(out2);
		m2.ImprimirSolucion(out3);

		vector <float> res1 = m1.devolverRes();
		vector <float> res2 = m2.devolverRes();
		bool andaBien = true;
		for (int i = 0; i<res1.size(); i++){
			if (fabs(res1[0]-res2[0])>0.0001){ //res1[0] != res2[0]
				andaBien = false;
				break;
			}
		}
		if (!andaBien){
			cout << "Algo anda mal" << endl;
			return 0;
		}

	}
	
	
	return 0;
  
}