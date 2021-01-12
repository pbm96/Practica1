#include <iostream>
#include <iomanip>

#include "../Headers/listas.h"
#include<ctime>

using namespace std;


// funcion para mostrar los concesionarios
void MostrarConcesionarioCoches(concesionario &d){
    coche c;

        d.automoviles.esPrimero();

    cout<<endl;
        while(d.automoviles.esActual()) {

            cout <<setw(15)<<d.automoviles.valorActual().bastidor<<"|"<<setw(11)<<d.automoviles.valorActual().modelo<<"|"<<setw(11)<<d.automoviles.valorActual().color <<"|"<<setw(19)<<d.clave<<"|"<<setw(19)<<d.localidad<<"|"<< endl;

            d.automoviles.esSiguiente();
        }
        d.automoviles.esPrimero();


}




int numeroAleatorioConcesionario;

coche cochePrimero;
int numero = 0;

// funcion para introducir coches en exposicion
void concesionarioAleatorio(concesionario &d){
    if(numero == numeroAleatorioConcesionario){
         d.automoviles.insertarNodo(cochePrimero);
    }
    numero++;
}

int main() {
    Arbol concesionarios;
    ListaDoble almacenDistribucion;
    srand(time(0));


    int dia = 1;
    int cochesEnConcesionarios=0;
    // Generamos los concesionarios aleatorios
    for (int i = 0; i < N1; i++) {
        concesionario c = generarConcesionario();
        concesionarios.Insertar(c);

    }

    // Generamos los coches del centro de almacenamiento
    for (int i = 0; i < N2; i++) {
        coche c = generarCoches();
        almacenDistribucion.insertarNodo(c, 'f');

    }



    cout <<endl;

    do {
        generarCabezeraAD();
        almacenDistribucion.recorrerLista(0);
        cout<<endl;
        // Mostramos concesionarios
        if(dia>1){
        almacenDistribucion.esPrimero();

            generarCuerpoConc();
        concesionarios.InOrden(MostrarConcesionarioCoches);
    }

        // sacamos los coches de la lista y los movemos a los concesionarios
        for (int i = 0; i < N3; i++) {
            if (!almacenDistribucion.listaVacia()) {
                cochePrimero = almacenDistribucion.valorActual();
                // Movemos el puntero;

                almacenDistribucion.esSiguiente();
                // Borramos el coche del almacen de distribucion
                almacenDistribucion.borrarNodo('p');
                numeroAleatorioConcesionario =  rand() % N1 ;

                numero = 0;
                concesionarios.InOrden(concesionarioAleatorio);
            }
        }

        cout<< "dia: "<<dia<<endl;
        system("pause");

        dia++;
        cochesEnConcesionarios+=N3;

    }while (cochesEnConcesionarios<N4);


    return 0;
}
