//
// Created by pablo on 20/11/20.
//

#include <stdio.h>
#include <iostream>
#include <ctime>
#include "../Headers/coches.h"


using namespace std;


//Funcion para generar un bastidor aleatorio para un coche
string generarBastidor() {

    //Ejemplo:45A6789

    string bastidor;
     char numeros[] ="0123456789";
     char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    srand((unsigned)time(0));

    for (int i = 0; i < 2; ++i)
        bastidor += numeros[rand() % (sizeof(numeros) - 1)];
    for (int i = 0; i < 1; ++i)
        bastidor += letras[rand() % (sizeof(letras) - 1)];
    for (int i = 0; i < 4; ++i)
        bastidor += numeros[rand() % (sizeof(numeros) - 1)];


    return bastidor;

}

void generarCabezera(){
    cout<<"Cabezera";
}

//Destructor
Cola::~Cola() {
    while (frente) desencolar();
}

//Añadir elemento en la cola
void Cola::encolar(int v) {
    pnodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo

    // Si cola no vacía, se añade el nuevo a continuación de ultimo
    if (final) final->siguiente = nuevo;

    //El último elemento de la cola es el nuevo nodo
    final = nuevo;

    // Si frente es NULL, la cola está vacía y el nuevo nodo pasa ser el primero
    if (!frente) frente = nuevo;
}


int Cola::desencolar() {
    pnodo nodo; //Var aux para manipular nodo
    int v; //Var aux para retorno del valor

    // Nodo apunta al primer elemento de la pila
    nodo = frente;

    if (!nodo) return 0; // Si no hay nodos en la pila se devuelve 0

    //Se asigna a frente la dirección del segundo nodo
    frente = nodo->siguiente;

    //Se guarda el valor de retorno
    v = nodo->valor;

    delete nodo; // Se borra el nodo

    // Si cola vacía, ultimo debe ser NULL también
    if (!frente) final = NULL;

    return v;
}



