#include <iostream>
#include <iomanip>
#include<ctime>
#include "../Headers/coches.h"


using namespace std;

struct coche coches[N1];
// variables colas lP
Cola arona;
Cola ateca;
Cola ibiza;
Cola toledo;
// pila camion
Pila camion;
Pila cargaCamionP;
// colas ca
Cola madridCA;
Cola barcelonaCA;
Cola zaragozaCA;
// las auxiliares se usan para almacenar todos los coches
Cola madridCAaux;
Cola barcelonaCAaux;
Cola zaragozaCAaux;

// Funciones
void pintarLP();
void pintarCA();
void descargarCamion(int i);
void cargarCamion(int i, int longArray);
void buscarCoche(string bastidor, int longArray);
coche buscarCoche(string bastidor);
int cargaC = 0;
int cambioEstado;

int main() {

    // variable del cont del programa
    int contEjecucion = 0;
    // la longitud de los coches que se generan
    int nArray = N2;
    // esto es para el random
    srand(time(0));
    // variable para guardar el bastidor que se busca
    string bastidor;
    int i;
    // coches creados
    int longArray = 0;

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
                longArrayC = nArray * (contEjecucion + 1);

                //longArray son los coches generados hasta el momento y si es diferente de n1 se siguen generando coches
                if(longArray!= N1) {
                    nArray * (contEjecucion + 1) <= N1 ? longArray = nArray * (contEjecucion + 1) : longArray = N1;

                    // si es igual unicamente se podran generar los coches ya creados - los que hay que crear: ejem: si hay 96 coches y n1 es 100 solo se generan 4.
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
                // si el cont es == 3 podemos cargar camiones
                if (contEjecucion == 3 )
                    cargarCamionB = true;
                // se cargan los coches de la variable auxiliar de los ca para mostrar todos los coches
                if (cargarCamionB) {
                    while(!madridCAaux.vacia()){
                        madridCA.encolar(madridCAaux.desencolar());
                    }
                    while(!barcelonaCAaux.vacia()){
                        barcelonaCA.encolar(barcelonaCAaux.desencolar());
                    }
                    while(!zaragozaCAaux.vacia()){
                        zaragozaCA.encolar(zaragozaCAaux.desencolar());
                    }

                    // se cargan los camiones
                    cargaC =0;
                    int cargaCamion = N3;
                    // si la carga de los camiones es la misma que los coches generados se usa solo un camion
                    if(cargaCamion >= N2) {
                        cout << "Se carga el camion 1 " << endl;
                        contCamion = 2;
                        cargarCamion(i, longArray);
                    }
                        // si es menor se usan varios camiones
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
                // cambiamos de estado a los coches que llevan 2 turnos en lP a ff
                if(contEjecucion >= 2){

                    //longarrayc se usa para los cambios de estado, de fi a ff cuando llegue al tope de coches creados que no suba la longitud del array
                    longArrayC <=N1+(N2*2)?cambioEstado = longArrayC - (N2*2): cambioEstado = N1;

                    for (i = 0; i < cambioEstado; i++) {
                        if ( coches[i].estado =="fi") {
                            coches[i].estado ="ff";
                        }
                    }
                }

                // generamos la linea de producción
                cout<<endl;
                generarCabezera();
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
                    cout<<endl;
                    generarCabezeraCA();
                    pintarCA();
                    // si hay mas pasos se muestra unicamente la ca sin descargar camion
                }else if(longArray >= N1){
                    cout<<endl;
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

        // si la carga del camion es igual a la variable n3 se carga otro camion
        if (c == N3)
            break;

    }
// si los estados son diferentes de fi se desencolan para no mostrarlos en lp
    if(cargaC == N3|| cambioEstado == N1){
        for (i = 0; i < longArray; i++) {
            if(coches[i].estado=="ci" || coches[i].estado=="cf" ||coches[i].estado=="ff"|| coches[i].estado=="ca" ){
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

    // guardamos en una pila la carga de cada camion para luego en el bucle descargarlo
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
        // se descarga el camion hasta la capacidad de n3 y aleatoriamente se muestra un ca
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
        // cada vez que se descarga un camion se resta del contador
        conCamion--;

    }


}
// metodo para buscar los coches
void buscarCoche(string bastidor, int longArray) {
    bool encontrado = false;
    coche cocheEncontrado;
    for (int i = 0; i < longArray; i++) {
        if (coches[i].bastidor == bastidor) {
            cocheEncontrado = coches[i];
            encontrado = true;
        }

    }
    if (encontrado) {
        if (cocheEncontrado.estado == "fi" || cocheEncontrado.estado == "ff" )
            cout << "El coche " << cocheEncontrado.bastidor << " Se encuentra en la linea de producción con el estado: "
                 << cocheEncontrado.estado << endl;
        else if (cocheEncontrado.estado == "ci")
            cout << "El coche " << cocheEncontrado.bastidor << " Se encuentra en un camion recien cargado "<<endl;
        else if (cocheEncontrado.estado == "cf")
            cout << "El coche " << cocheEncontrado.bastidor << " Se encuentra en un camion recien llegado al destino "<<endl;
        else if (cocheEncontrado.estado == "ca")
            cout << "El coche " << cocheEncontrado.bastidor << " Se encuentra en el centro de alamacenamiento"<<endl;
    }
    else
        cout << "No se ha encontrado el coche"<<endl;


}

// metodo para pintar el ca
void pintarCA(){

    int aparcamientoM = 0;
    int aparcamientoB = 0;
    int aparcamientoZ = 0;

    while (!madridCA.vacia() || !barcelonaCA.vacia() || !zaragozaCA.vacia() ) {

        if (!madridCA.vacia()) {
            int y = madridCA.desencolar();

            coches[y].estado = "ca";
            cout <<setw(4)<<aparcamientoM<<"|"<< setw(8) << coches[y].bastidor << "|" << setw(6) << coches[y].modelo << "|"
                 << setw(8)
                 << coches[y].color << "|" << setw(6) << coches[y].estado << "|";
            madridCAaux.encolar(y);
            aparcamientoM++;
        } else
            cout << setw(4)<<" "<<"|"<< setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";
        if (!barcelonaCA.vacia()) {
            int j = barcelonaCA.desencolar();
            coches[j].estado = "ca";

            cout  <<setw(4)<<aparcamientoB<<"|"<< setw(8) << coches[j].bastidor << "|" << setw(6) << coches[j].modelo << "|"
                  << setw(8)
                  << coches[j].color << "|" << setw(6) << coches[j].estado << "|";
            barcelonaCAaux.encolar(j);
            aparcamientoB++;
        } else
            cout << setw(4)<<" "<<"|"<< setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";
        if (!zaragozaCA.vacia()) {
            int k = zaragozaCA.desencolar();
            coches[k].estado = "ca";

            cout  <<setw(4)<<aparcamientoZ<<"|"<< setw(8) << coches[k].bastidor << "|" << setw(6) << coches[k].modelo << "|"
                  << setw(8)
                  << coches[k].color << "|" << setw(6) << coches[k].estado << "|";
            zaragozaCAaux.encolar(k);
            aparcamientoZ++;
        } else
            cout << setw(4)<<" "<<"|"<< setw(8) << " " << "|" << setw(6) << " " << "|" << setw(8) << " " << "|" << setw(6)
                 << " "
                 << "|";


        cout << endl;

    }
}
