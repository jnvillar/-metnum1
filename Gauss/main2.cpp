#include "parser.cpp"

int main(int argc, char* argv[]){

	if(argv[1][1] != 'e'){
		printf("%s [METHOD] [INPUT FILE] [OUTPUT FILE]\n", argv[0]);
		printf("Mete -g para Gauss o -c pa Cholesky amiwo o -e para la estrategia ben peola\n");
	}else{
		int equipo;
		cout << "Elija el equipo" << endl;
		cin >> equipo;		
		Matriz m(parser(argv[2],equipo-1));			
		m.estrategia1(equipo-1);		
		return 0;  
}
};