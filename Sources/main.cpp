#include <iostream>
#include <stdio.h>
#include <iomanip>

#include<ctime>
#include "../Headers/coches.h"


using namespace std;

struct coche coches[N1];
Cola arona;
Cola ateca;
Cola ibiza;
Cola toledo;
Pila camion;
void pintarLP();
void descargarCamion();
void cargarCamion(int i, int longArray);
int main() {


    int contEjecucion = 0;
    int nArray = N2;
    srand(time(0));

    int i;
    int longArray;
    int longArrayC;
    int cambioEstado;
    int a, b;
    bool cargarCamionB = false;
    do {


        cout << "1- Ejecutar\n";
        cout << "2- Buscar vehiculo\n";
        cout << "3- Salir\n";
        cout <<longArray<<"/"<<N1<<" Coches creados.   "<<"Paso del programa: "<<contEjecucion<<endl;
        cin >> a;

        switch (a) {
            case 1:

                //Si los coches que hemos introducido son menores que n1 seguimos introduciendo coches
                longArrayC = nArray * (contEjecucion + 1);

                //
                if(longArray!= N1) {
                    nArray * (contEjecucion + 1) <= N1 ? longArray = nArray * (contEjecucion + 1) : longArray = N1;

                    //
                    if (longArray == N1) {
                        cout << "Unicamente se podran introducir: " << nArray * (contEjecucion + 1) - N1 << " coches."<<endl;
                    }


                    // generamos los coches en la posicion del array que toque
                    i = contEjecucion * nArray;
                    for (i; i < longArray; i++) {

                        coches[i] = generarCoches();

                        if (coches[i].modelo == "Arona") {
                            arona.encolar(i);

                        } else if (coches[i].modelo == "Ateca") {
                            ateca.encolar(i);

                        } else if (coches[i].modelo == "Ibiza") {
                            ibiza.encolar(i);

                        } else if (coches[i].modelo == "Toledo") {
                            toledo.encolar(i);

                        }
                    }

                    if (contEjecucion == 3 )
                            cargarCamionB = true;
                    if (cargarCamionB) {
                        cout << "Se carga el camión: " << endl;
                        cargarCamion(i,longArray);
                    }
                }

                // cambiamos de estado a los coches que llevan 2 turnos en lP
                if(contEjecucion >= 2){
                    longArrayC <=N1+(N2*2)?cambioEstado = longArrayC - (N2*2): cambioEstado = N1;

                    for (i = 0; i < cambioEstado; i++) {
                        if ( coches[i].estado =="fi") {
                            coches[i].estado ="ff";
                        }
                    }
                }
                //generamos la cabecera de la linea de produccion

                generarCabezera();
                // generamos la linea de producción
                pintarLP();

                // incluimos todos los coches creados en la cola
                for (i = 0; i < longArray; i++) {
                    if (coches[i].modelo == "Arona") {
                        arona.encolar(i);

                    } else if (coches[i].modelo == "Ateca") {
                        ateca.encolar(i);

                    } else if (coches[i].modelo == "Ibiza") {
                        ibiza.encolar(i);

                    } else if (coches[i].modelo == "Toledo") {
                        toledo.encolar(i);

                    }

                }

                // descargamos el camion
                descargarCamion();

                // autmentamos el contador de ejecucion
                contEjecucion++;
                break;
            case 2:
                cout << "Buscamos un coche por su numero de bastidor\n";
                break;
            case 3:
                cout << "¿Seguro que quieres salir?... SI o NO\n";
                cout << "\n 1-SI";
                cout << "\n 2-NO\n\n";
                cin >> b;
                if (b == 1) {
                    a = 3;
                } else {
                    a = 1;
                }
                break;
            default:
                cout << "Debe de introducir 1,2,3\n";
                break;

        }
    } while (a != 3);



    return 0;

}
// metodo para mostrar la linea de produccion
void pintarLP(){
    while (!arona.vacia() || !ateca.vacia() || !ibiza.vacia() || !toledo.vacia()) {

        if (!arona.vacia()) {
            int y = arona.desencolar();
                cout << setw(8) << coches[y].bastidor << "|" << setw(6) << coches[y].modelo << "|"
                     << setw(8)
                     << coches[y].color << "|" << setw(6) << coches[y].estado << "|";

        } else
            cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";
        if (!ateca.vacia()) {
            int j = ateca.desencolar();

                cout << setw(8) << coches[j].bastidor << "|" << setw(6) << coches[j].modelo << "|"
                     << setw(8)
                     << coches[j].color << "|" << setw(6) << coches[j].estado << "|";

        } else
            cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";
        if (!ibiza.vacia()) {
            int k = ibiza.desencolar();

                cout << setw(8) << coches[k].bastidor << "|" << setw(6) << coches[k].modelo << "|"
                     << setw(8)
                     << coches[k].color << "|" << setw(6) << coches[k].estado << "|";

        } else
            cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";

        if (!toledo.vacia()) {
            int x = toledo.desencolar();

                cout << setw(8) << coches[x].bastidor << "|" << setw(6) << coches[x].modelo << "|"
                     << setw(8)
                     << coches[x].color << "|" << setw(6) << coches[x].estado << "|";

        } else
            cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";

        cout << endl;

    }
}

// metodo para cargar el camion
void cargarCamion(int i, int longArray){
    // incluimos los coches con estado ff en turno anterior al camión.
    for (i = 0; i < longArray; i++) {
        if(coches[i].estado=="ff"){
            camion.apilar(i);
            coches[i].estado = "ci";
            cout <<"Camion cargado con: "<<coches[i].bastidor<<"Estado: "<<coches[i].estado<<endl;

            if (coches[i].modelo == "Arona") {
                arona.desencolar();

            } else if (coches[i].modelo == "Ateca") {
                ateca.desencolar();

            } else if (coches[i].modelo == "Ibiza") {
                ibiza.desencolar();

            } else if (coches[i].modelo == "Toledo") {
                toledo.desencolar();

            }
        }
        // si los coches no tienen estado fi o ff no se muestran
        else if(coches[i].estado=="ci" || coches[i].estado=="cf"){
            if (coches[i].modelo == "Arona") {
                arona.desencolar();

            } else if (coches[i].modelo == "Ateca") {
                ateca.desencolar();

            } else if (coches[i].modelo == "Ibiza") {
                ibiza.desencolar();

            } else if (coches[i].modelo == "Toledo") {
                toledo.desencolar();

            }
        }
    }
}
// metodo para descargar el camion
void descargarCamion(){
    // Mientras la pila del camion no este vacia lo descarga
    while (!camion.pilaVacia()){
        int i = camion.desapilar();
        coches[i].estado = "cf";
        cout << "Camion descargando... :"<< coches[i].bastidor<<" Estado: "<< coches[i].estado<<endl;
    }
}
