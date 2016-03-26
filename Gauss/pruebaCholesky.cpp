#include "Matriz.cpp"


int main() {

  

    vector< vector<float> > a;
    vector<float> f1;
    vector<float> f2;
    vector<float> f3;
    vector<float> f4;
    vector<float> f5;
    f1.push_back(5);
    f1.push_back(0);
    f1.push_back(-1);
    f1.push_back(-1);
    f1.push_back(-1);
    f2.push_back(0);
    f2.push_back(4);
    f2.push_back(-1);
    f2.push_back(0);
    f2.push_back(-1);
    f3.push_back(-1);
    f3.push_back(-1);
    f3.push_back(6);
    f3.push_back(-1);
    f3.push_back(-1);
    f4.push_back(-1);
    f4.push_back(0);
    f4.push_back(-1);
    f4.push_back(4);
    f4.push_back(0);
    f5.push_back(-1);
    f5.push_back(-1);
    f5.push_back(-1);
    f5.push_back(0);
    f5.push_back(5);

    a.push_back(f1);
    a.push_back(f2);
    a.push_back(f3);
    a.push_back(f4);
    a.push_back(f5);


    vector<float> res;
    res.push_back(3);
    res.push_back(2);
    res.push_back(1);
    res.push_back(1);
    res.push_back(1);


    Matriz hChole(a,res);
    Matriz hGauss(a,res);


    hChole.cholesky();
    hChole.resolverTriangInf();
    hChole.matrizTraspuesta();
    hChole.resolverTriangSup();
    hChole.Imprimir();



    hGauss.Gauss0();
    hGauss.resolverTriangSup();
    hGauss.Imprimir();
    

    return 0;
}