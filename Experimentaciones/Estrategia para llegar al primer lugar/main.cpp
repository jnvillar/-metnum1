#include "../../Gauss/parser.cpp"

int main(int argc, char* argv[]){	
	int equipo;
	cout << "Elija el equipo" << endl;
	cin >> equipo;		
	Matriz m(parser(argv[2],equipo-1));			
	m.estrategia1(equipo-1);		
	return 0;  

};