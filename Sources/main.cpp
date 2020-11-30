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
Cola madridCA;
Cola barcelonaCA;
Cola zaragozaCA;
Cola madridCAaux;
Cola barcelonaCAaux;
Cola zaragozaCAaux;
Pila cargaCamionP;
void pintarLP();
void guardarCochesPilaAuxCA();
void pintarCA();
void descargarCamion(int i);
void cargarCamion(int i, int longArray);
void buscarCoche(string bastidor, int longArray);
coche buscarCoche(string bastidor);
int cargaC = 0;
int cambioEstado;

int main() {


    int contEjecucion = 0;
    int nArray = N2;
    srand(time(0));
    string bastidor;
    int i;
    int longArray;
    int longArrayC;
    int a, b;
    bool cargarCamionB = false;
    int contCamion;

    do {


        cout << "1- Ejecutar\n";
        cout << "2- Buscar vehiculo\n";
        cout << "3- Salir\n";
        cout <<longArray<<"/"<<N1<<" Coches creados.   "<<"Paso del programa: "<<contEjecucion<<endl;
        cin >> a;

        switch (a) {
            case 1:
                contCamion = 1;
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


                }
                if (contEjecucion == 3 )
                    cargarCamionB = true;

                if (cargarCamionB) {
                    guardarCochesPilaAuxCA();
                    cargaC =0;
                    int cargaCamion = N3;

                    if(cargaCamion >= N2) {
                        cout << "Se carga el camion 1 " << endl;
                        contCamion = 2;
                        cargarCamion(i, longArray);
                    }
                    else if(cargaCamion < N2){
                        cargaCamion = 0;
                        while (cargaCamion < N2 ){
                            cout << "Se carga el camion "<<contCamion << endl;
                            cargarCamion(i, longArray);
                            cargaCamion += N3;
                            contCamion++;

                        }
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

                // descargamos los camiones
                if(!camion.pilaVacia()){
                    descargarCamion(contCamion-1);
                    generarCabezeraCA();
                    pintarCA();
                }else if(longArray >= N1){
                    generarCabezeraCA();
                    pintarCA();
                }

                // autmentamos el contador de ejecucion
                contEjecucion++;
                break;
            case 2:

                cout << "Introducir bastidor para buscar: ";
                cin >> bastidor;
                buscarCoche(bastidor, longArray);
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
    int c = 0;
    // incluimos los coches con estado ff en turno anterior al camión.
    for (i = 0; i < longArray; i++) {
        if(coches[i].estado=="ff"){
            camion.apilar(i);
            coches[i].estado = "ci";
            cout <<"Camion cargado con: "<<coches[i].bastidor<<" Estado: "<<coches[i].estado<<endl;

            c++;
            cargaC++;

        }
        // si los coches no tienen estado fi o ff no se muestran


        if (c == N3)
            break;

    }

    if(cargaC == N3|| cambioEstado == N1){
        for (i = 0; i < longArray; i++) {
            if(coches[i].estado=="ci" || coches[i].estado=="cf" ||coches[i].estado=="ff"){
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


    cargaCamionP.apilar(c);

}
// metodo para descargar el camion
void descargarCamion(int conCamion){
    // Mientras la pila del camion no este vacia lo descarga
    cout<<conCamion<<endl;
    while (conCamion >=1) {
        int carga = cargaCamionP.desapilar();
        int c = 1;
        string caSeleccionado = generarCA();
        cout << "El camion "<<conCamion<<" se descarga en: "<<caSeleccionado<<endl;
        while(c <=carga){
            int m = camion.desapilar();
            coches[m].estado = "cf";

            if(caSeleccionado == "Madrid"){
                madridCA.encolar(m);
            }
            if(caSeleccionado == "Barcelona"){
                barcelonaCA.encolar(m);
            }
            if(caSeleccionado == "Zaragoza"){
                zaragozaCA.encolar(m);
            }
            cout << "Camion descargando... :"<< coches[m].bastidor<<" Estado: "<< coches[m].estado<<" en: "<<caSeleccionado<<endl;
            c++;
        }

        conCamion--;

    }


}

void buscarCoche(string bastidor, int longArray) {
    bool encontrado = false;
    coche cocheEncontrado;
    for (int i = 0; i < longArray; i++) {
        if (coches[i].bastidor == bastidor) {
            cocheEncontrado = coches[i];
            encontrado = true;
        }

    }
    if (encontrado)
        cout << "El estado del coche " << cocheEncontrado.bastidor << " es: " << cocheEncontrado.estado << endl;
    else
        cout << "No se ha encontrado el coche"<<endl;


}
void pintarCA(){

    while (!madridCA.vacia() || !barcelonaCA.vacia() || !zaragozaCA.vacia() ) {

        if (!madridCA.vacia()) {
            int y = madridCA.desencolar();
            cout << setw(8) << coches[y].bastidor << "|" << setw(6) << coches[y].modelo << "|"
                 << setw(8)
                 << coches[y].color << "|" << setw(6) << coches[y].estado << "|";
            // guardamos el coche en una pila auxiliar para poder disponer de el todos los turnos
            madridCAaux.encolar(y);

        } else
            cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";
        if (!barcelonaCA.vacia()) {
            int j = barcelonaCA.desencolar();

            cout << setw(8) << coches[j].bastidor << "|" << setw(6) << coches[j].modelo << "|"
                 << setw(8)
                 << coches[j].color << "|" << setw(6) << coches[j].estado << "|";
            barcelonaCAaux.encolar(j);
        } else
            cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";
        if (!zaragozaCA.vacia()) {
            int k = zaragozaCA.desencolar();

            cout << setw(8) << coches[k].bastidor << "|" << setw(6) << coches[k].modelo << "|"
                 << setw(8)
                 << coches[k].color << "|" << setw(6) << coches[k].estado << "|";
            zaragozaCAaux.encolar(k);
        } else
            cout << setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";


        cout << endl;

    }
}
// guardamos los coches de la pila auxiliar en la pila de cA para mostrarlo
void guardarCochesPilaAuxCA(){
        while(!madridCAaux.vacia()){
            madridCA.encolar(madridCAaux.desencolar());
        }
        while(!barcelonaCAaux.vacia()){
            barcelonaCA.encolar(barcelonaCAaux.desencolar());
        }
        while(!zaragozaCAaux.vacia()){
            zaragozaCA.encolar(zaragozaCAaux.desencolar());
        }
};