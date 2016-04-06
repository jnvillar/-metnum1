#include "../../Gauss/parser.cpp"

int main(int argc, char* argv[]){	
	int equipo;
	cout << "Elija el equipo, note que el equipo 0 es el 1" << endl;
	cin >> equipo;		
	Matriz m(parser(argv[1],equipo-1));		
	Matriz original(parser(argv[1]));
	original.cholesky();
	original.resolverTriangInf();
	original.resolverTriangSupTraspuesta();	
	cout << endl <<  "Rankings Originales" << endl << endl;
	original.ImprimirSolucionOrdeneda(stdout);	
	m.estrategia1(equipo-1);		
	return 0;  
};