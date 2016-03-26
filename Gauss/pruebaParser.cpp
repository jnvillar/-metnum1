#include "parser.cpp"

int main(int argc, char* argv[])
{

  Matriz m = parser(argv[1]);
  m.Imprimir();

  return 0;
  
}