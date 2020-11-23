#include <iostream>
#include <stdio.h>

#include<ctime>
#include "../Headers/coches.h"


using namespace std;

int main() {

    struct coche coches[N1];
    srand(time(0));

    for(int i = 0; i<N1;i++){

        coches[i] = generarCoches();
        cout<<coches[i].modelo<<"--"<<coches[i].color <<"--"<< coches[i].bastidor<<endl;
    }



    return 0;
}