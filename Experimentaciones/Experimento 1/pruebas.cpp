#include "../../Gauss/parser.cpp"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/syscall.h>

/* retorna "a - b" en segundos */
double timeval_diff(struct timeval *a, struct timeval *b)
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int main(int argc, char *argv[]){
  struct timeval gauss_ini, gauss_fin;
  struct timeval chol_ini, chol_fin;
  double secs1;
  double secs2;
  
  FILE*  arch1= fopen("resgauss", "w");
  FILE*  arch2= fopen("reschol", "w");
  

  int equipos;
  cout << "Ingresa cantidad de equipos" << endl;
  cin >> equipos;

  int enfrentamientos;
  cout << "Ingresa cantidad de enfrentamientos" << endl;
  cin >> enfrentamientos;

 char* ruta = "resultados";

  int i = 0;

  while(i<100){

  	equipos = equipos + 10;
	generador(equipos,enfrentamientos,ruta);

	Matriz g = parser(ruta);
	Matriz c = parser(ruta);

	

	gettimeofday(&gauss_ini, NULL);
	g.Gauss0();
	g.resolverTriangSup();
	gettimeofday(&gauss_fin, NULL);
	secs1 = timeval_diff(&gauss_fin, &gauss_ini);
	fprintf(arch1, "%f\n", secs1);



	gettimeofday(&chol_ini, NULL);
	c.cholesky();
	c.resolverTriangSup();
	c.resolverTriangSupTraspuesta();
	gettimeofday(&chol_fin, NULL);
	secs2 = timeval_diff(&chol_fin, &chol_ini);
	fprintf(arch2, "%f\n", secs2);
	i++;
}

fclose(arch1);
fclose(arch2);



  return 0;
}
