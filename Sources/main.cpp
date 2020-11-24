#include <iostream>
#include <stdio.h>
#include <iomanip>

#include<ctime>
#include "../Headers/coches.h"


using namespace std;

int main() {

    struct coche coches[N1];
    Cola arona;
    Cola ateca;
    Cola ibiza;
    Cola toledo;
    int nArray = N1;
    srand(time(0));
    //generamos la cabecera de la linea de produccion
    generarCabezera();

    // Se generan coches para fabricar
    for(int i = 0; i<nArray;i++){

        coches[i] = generarCoches();

        if(coches[i].modelo =="Arona")
            arona.encolar(i);
        else if(coches[i].modelo =="Ateca")
            ateca.encolar(i);
        else if(coches[i].modelo =="Ibiza")
            ibiza.encolar(i);
        else if(coches[i].modelo =="Toledo")
            toledo.encolar(i);
    }

    // generamos la linea de producción
    generarLP(arona, ateca, ibiza, toledo, coches);

    return 0;
}