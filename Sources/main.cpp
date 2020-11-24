#include <iostream>
#include <stdio.h>
#include <iomanip>

#include<ctime>
#include "../Headers/coches.h"


using namespace std;

int main() {

    struct coche coches[N1];
    Cola arona, arona2;
    Cola ateca, ateca2;
    Cola ibiza, ibiza2;
    Cola toledo, toledo2;
    int num;
    int contEjecucion = 0;

    do {
        cout <<"introducir num: ";
        cin>> num;
        int nArray = 8;
        srand(time(0));
        //generamos la cabecera de la linea de produccion
        generarCabezera();

        // Se generan coches para fabricar

        int i ;
        int longArray;
        i =contEjecucion * nArray;
        longArray = nArray*(contEjecucion+1);
        cout<<longArray<<endl;

        for ( i ; i < longArray; i++) {

            coches[i] = generarCoches();

            if (coches[i].modelo == "Arona") {
                arona.encolar(i);

            }
            else if (coches[i].modelo == "Ateca"){
                ateca.encolar(i);

            }
            else if (coches[i].modelo == "Ibiza") {
                ibiza.encolar(i);

            }
            else if (coches[i].modelo == "Toledo") {
                toledo.encolar(i);

            }
        }
        cout<<coches[0].bastidor<<endl;

        // generamos la linea de producción
        while (!arona.vacia() || !ateca.vacia() || !ibiza.vacia() || !toledo.vacia()) {

            if (!arona.vacia()) {
                int y = arona.desencolar();
                cout << setw(8) << coches[y].bastidor << "|" << setw(6) << coches[y].modelo << "|" << setw(8)
                     << coches[y].color << "|" << setw(6) << coches[y].estado << "|";
            } else
                cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6) << " "
                     << "|";
            if (!ateca.vacia()) {
                int j = ateca.desencolar();
                cout << setw(8) << coches[j].bastidor << "|" << setw(6) << coches[j].modelo << "|" << setw(8)
                     << coches[j].color << "|" << setw(6) << coches[j].estado << "|";
            } else
                cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6) << " "
                     << "|";
            if (!ibiza.vacia()) {
                int k = ibiza.desencolar();
                cout << setw(8) << coches[k].bastidor << "|" << setw(6) << coches[k].modelo << "|" << setw(8)
                     << coches[k].color << "|" << setw(6) << coches[k].estado << "|";
            } else
                cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6) << " "
                     << "|";

            if (!toledo.vacia()) {
                int x = toledo.desencolar();
                cout << setw(8) << coches[x].bastidor << "|" << setw(6) << coches[x].modelo << "|" << setw(8)
                     << coches[x].color << "|" << setw(6) << coches[x].estado << "|";
            } else
                cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6) << " "
                     << "|";

            cout << endl;

        }

        for ( i = 0 ; i < longArray; i++) {

            coches[i] = generarCoches();

            if (coches[i].modelo == "Arona") {
                arona.encolar(i);

            }
            else if (coches[i].modelo == "Ateca"){
                ateca.encolar(i);

            }
            else if (coches[i].modelo == "Ibiza") {
                ibiza.encolar(i);

            }
            else if (coches[i].modelo == "Toledo") {
                toledo.encolar(i);

            }
        }

        contEjecucion++;
    }while (num ==1);
    return 0;
}