#include <iostream>
#include <vector>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <utility>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>

using namespace std;


int main(){
	int n = 3;
    vector< vector<float> > a;
    vector<float> f1;
    vector<float> f2;
    vector<float> f3;
    f1.push_back(3);
    f1.push_back(2);
    f1.push_back(1);
    f2.push_back(1);
    f2.push_back(4);
    f2.push_back(6);
    f3.push_back(2);
    f3.push_back(1);
    f3.push_back(3);
    a.push_back(f1);
    a.push_back(f2);
    a.push_back(f3);

    int filas,cols = n;



    for (int i = 0; i<n-1; i++){
    	for (int h = i+1; h<n; h++){
    		float aux = a[h][i];
    		for (int j = 0; j<n; j++){
    			a[h][j] = a[h][j]-aux/a[i][i]*a[i][j];
    		}
    	}
    }

    for (int i = 0; i<n; i++){
    	 for (int j = 0; j<n; j++){
    		cout << a[i][j] << " ";
    	}	
    	cout << endl;
    }

    return 0;
}