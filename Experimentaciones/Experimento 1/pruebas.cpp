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
double secs1acum;
double secs2acum;

FILE*  arch1= fopen("resgauss", "w");
FILE*  arch2= fopen("reschol", "w");


int equipos;
cout << "Ingresa cantidad de equipos" << endl;
cin >> equipos;

int enfrentamientos;
cout << "Ingresa cantidad de enfrentamientos" << endl;
cin >> enfrentamientos; 

int resolver;
cout << "Ingresa cantidad de enfrentamientos" << endl;
cin >> resolver; 

char* ruta = "resultados";

int i = 0;

while(i<100){

	equipos = equipos + 10;
	generador(equipos,enfrentamientos,ruta);

	Matriz g = parser(ruta);
	secs1acum = 0;
	secs2acum = 0;
	int j = 0;

	while(j<resolver){

	Matriz a = g;	
	Matriz b = g;

	gettimeofday(&gauss_ini, NULL);
	a.Gauss0();
	a.resolverTriangSup();
	gettimeofday(&gauss_fin, NULL);
	secs1 = timeval_diff(&gauss_fin, &gauss_ini);
	secs1acum = secs1acum +secs1;

	gettimeofday(&chol_ini, NULL);
	b.cholesky();
	b.resolverTriangSup();
	b.resolverTriangSupTraspuesta();
	gettimeofday(&chol_fin, NULL);
	secs2 = timeval_diff(&chol_fin, &chol_ini);
	secs2acum = secs2acum + secs2;
	j++;
	}

fprintf(arch1, "%f\n", secs1acum/resolver);
fprintf(arch2, "%f\n", secs2acum/resolver);


i++;
}

fclose(arch1);
fclose(arch2);



return 0;
}
