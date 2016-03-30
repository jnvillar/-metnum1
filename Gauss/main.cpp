#include "parser.cpp"

int main(int argc, char* argv[])
{

	
	if ((argc != 3 && argc != 4 ) || (argv[1][1] != 'g' && argv[1][1] != 'c') ){
		printf("%s [METHOD] [INPUT FILE] [OUTPUT FILE]\n", argv[0]);
		printf("WHERE METHOD CAN BE -g for Gauss or -c for Cholesky\n");
	} else{
		Matriz m = parser(argv[2]);
		if (argv[1][1] == 'g'){
			m.Gauss0();
			m.resolverTriangSup();
		} else if (argv[1][1] == 'c'){
			m.cholesky();
		    m.resolverTriangInf();
		    m.resolverTriangSupTraspuesta();		    
		}
		if (argc == 4){
			FILE* out = fopen(argv[3], "w");
			m.ImprimirSolucion(out);
			fclose(out);			
		} else {
			m.ImprimirSolucion(stdout);			
		}
	}
	
	return 0;
  
}