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
   // generarLP(arona, ateca, ibiza, toledo, coches);
    int a,b;
    do{


        cout<<"1- Ejecutar\n";
        cout<<"2- Buscar vehiculo\n";
        cout<<"3- Salir\n";
        cin>>a;

        switch(a)
        {
            case 1:
                cout<<"Ejecutamos el programa\n";
                break;
            case 2:
                cout<<"Buscamos un coche por su numero de bastidor\n";
                break;
            case 3:
                cout<<"¿Seguro que quieres salir?... SI o NO\n";
                cout<<"\n 1-SI";
                cout<<"\n 2-NO\n\n";
                cin>>b;
                if(b==1){
                    a=3;
                }
                else{
                    a=1;
                }
            default:
                cout<<"Debe de introducir 1,2,3\n";


        }
    }

    while(a!=3);








    return 0;


    }

