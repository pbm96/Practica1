#include <iostream>
#include "../Headers/listas.h"
#include<ctime>

using namespace std;


// funcion para mostrar los concesionarios
void MostrarConcesionario(concesionario &d){
    coche c;

        d.automoviles.esPrimero();
        while(d.automoviles.esActual()) {
            cout << "concesionario: "<<d.clave<<"--"<<d.automoviles.valorActual().bastidor << endl;

            d.automoviles.esSiguiente();
        }
        d.automoviles.esPrimero();

}

void Mostrar2(concesionario &d){
    cout<<d.clave<<endl;
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
    concesionarios.InOrden(Mostrar2);

    // Generamos los coches del centro de almacenamiento
    for (int i = 0; i < N2; i++) {
        coche c = generarCoches();
        almacenDistribucion.insertarNodo(c, 'f');
        cout << c.bastidor + ",";

    }
    almacenDistribucion.recorrerLista(0);
    cout<<endl;

    generarCabezeraAD();
    generarCabezeraConc();

    cout <<endl;

    do {


        almacenDistribucion.esPrimero();


        for (int i = 0; i < N3; i++) {
            if(!almacenDistribucion.listaVacia()) {
                cochePrimero = almacenDistribucion.valorActual();
                cout << cochePrimero.bastidor << endl;
                // Movemos el puntero;


                almacenDistribucion.esSiguiente();
                // Borramos el coche del almacen de distribucion
                almacenDistribucion.borrarNodo('p');


                numeroAleatorioConcesionario = 1 + rand() % (N1 - 1);
                cout << numeroAleatorioConcesionario << endl;

                numero = 0;
                concesionarios.InOrden(concesionarioAleatorio);
            }
        }

        concesionarios.InOrden(MostrarConcesionario);

        cout<< "dia: "<<dia<<endl;
        system("pause");
        dia++;
        cochesEnConcesionarios+=N3;

    }while (cochesEnConcesionarios<N4);

    /*Lista lista;
    lista.insertarNodo(20);
    lista.insertarNodo(10);
    lista.insertarNodo(40);
    lista.insertarNodo(30);
    lista.recorrerLista();
    cout << "Lista de elementos:" << endl;
    lista.esPrimero();
    while(lista.esActual()) {
        cout << lista.valorActual() << endl;

        lista.esSiguiente();
    }
        lista.esPrimero();

        cout << "Primero: " << lista.valorActual() << endl;
        lista.esUltimo();
        cout << "Ultimo: " << lista.valorActual() << endl;
        lista.borrarNodo(10);
        lista.borrarNodo(15);
        lista.borrarNodo(45);
        lista.borrarNodo(30);
        lista.borrarNodo(40);
        lista.recorrerLista();

    ListaDoble listaDoble;
    cout << "Insertamos nodo 20 al final" << endl;
    listaDoble.insertarNodo(20,'f');
    listaDoble.recorrerLista(0); //Podemos usar ASCENDENTE en lugar de 0
    cout << "Insertamos nodo 10 al final" << endl;
    listaDoble.insertarNodo(10,'f');
    listaDoble.recorrerLista(0);
    cout << "Insertamos nodo 40 al principio" << endl;
    listaDoble.insertarNodo(40,'p');
    listaDoble.recorrerLista(0);
    cout << "Insertamos nodo 30 al principio" << endl;
    listaDoble.insertarNodo(30,'p');
    listaDoble.recorrerLista(0);

    cout << endl;
    cout << "Mostrar lista hacia adelante" << endl;
    listaDoble.recorrerLista(0);
    cout << endl;
    cout << "Mostrar lista hacia atras" << endl;
    listaDoble.recorrerLista(1); //Podemos escribir 1 en lugar de DESCENDENTE
    cout << endl;
    cout << "Borramos por el final" << endl;
    listaDoble.borrarNodo('f');
    listaDoble.recorrerLista(0);

    // InserciÃ³n de nodos en Ã¡rbol:
    Arbol ArbolInt;
    ArbolInt.Insertar(10);
    ArbolInt.Insertar(5);
    ArbolInt.Insertar(12);
    ArbolInt.Insertar(4);
    ArbolInt.Insertar(7);
    ArbolInt.Insertar(3);
    ArbolInt.Insertar(6);
    ArbolInt.Insertar(9);
    ArbolInt.Insertar(8);
    ArbolInt.Insertar(11);
    ArbolInt.Insertar(14);
    ArbolInt.Insertar(13);
    ArbolInt.Insertar(2);
    ArbolInt.Insertar(1);
    ArbolInt.Insertar(15);
    ArbolInt.Insertar(10);
    ArbolInt.Insertar(17);
    ArbolInt.Insertar(18);
    ArbolInt.Insertar(16);

    cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

    // Mostrar el Ã¡rbol en tres ordenes distintos:
    cout << "InOrden: ";
    ArbolInt.InOrden(Mostrar);
    cout << endl;
    cout << "PreOrden: ";
    ArbolInt.PreOrden(Mostrar);
    cout << endl;
    cout << "PostOrden: ";
    ArbolInt.PostOrden(Mostrar);
    cout << endl;

    // Borraremos algunos elementos:
    cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
    ArbolInt.Borrar(5);
    cout << "Borrar   5: ";
    ArbolInt.InOrden(Mostrar);
    cout << endl;
    ArbolInt.Borrar(8);
    cout << "Borrar   8: ";
    ArbolInt.InOrden(Mostrar);
    cout << endl;
    ArbolInt.Borrar(15);
    cout << "Borrar  15: ";
    ArbolInt.InOrden(Mostrar);
    cout << endl;
    ArbolInt.Borrar(245);
    cout << "Borrar 245: ";
    ArbolInt.InOrden(Mostrar);
    cout << endl;
    ArbolInt.Borrar(4);
    cout << "Borrar   4: ";
    ArbolInt.InOrden(Mostrar);
    ArbolInt.Borrar(17);
    cout << endl;
    cout << "Borrar  17: ";
    ArbolInt.InOrden(Mostrar);
    cout << endl;

    // Veamos algunos parÃ¡metros
    cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
    cout << "Altura de 1 " << ArbolInt.Altura(1) << endl;
    cout << "Altura de 10 " << ArbolInt.Altura(10) << endl;
    cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

    cin.get();*/
    return 0;
}
