//
// Created by pablo on 20/11/20.
//

#include <iostream>
#include <iomanip>
#include "../Headers/coches.h"


using namespace std;


//Funcion para generar un bastidor aleatorio para un coche
string generarBastidor() {

    //Ejemplo:45A6789

    string bastidor;
     char numeros[] ="0123456789";
     char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



    for (int i = 0; i < 2; ++i)
        bastidor += numeros[rand() % (sizeof(numeros) - 1)];
    for (int i = 0; i < 1; ++i)
        bastidor += letras[rand() % (sizeof(letras) - 1)];
    for (int i = 0; i < 4; ++i)
        bastidor += numeros[rand() % (sizeof(numeros) - 1)];

    return bastidor;

}
string generarColor() {

    string color;
    int posicion;
    string colores[6] ={"Blanco","Rojo","Negro","Azul","Naranja","Gris"};
    posicion =  rand()%6;
        color = colores[posicion];

    return color;

}
string generarModelo() {

    string modelo;
    int posicion;
    string modelos[4] ={"Ibiza","Arona","Ateca","Toledo"};
    posicion =  rand()%4;
    modelo = modelos[posicion];

    return modelo;

}
// Metodo que se encarga de pintar la cabezera de la consola
void generarCabezera(){

    cout<<setw(32)<<"Linea de produccion 1|"<<setw(32)<<"Linea de produccion 2|"<<setw(32)<<"Linea de produccion 3|"<<setw(32)<<"Linea de produccion 4|"<<endl;
    for(int i = 0; i<120;i++){
        cout<<"-";
    }
    cout<<endl;
    for(int i = 0; i<4;i++){
        cout<<setw(9)<<"Bastidor|"<<setw(7)<<"Modelo|"<<setw(9)<<"Color|"<<setw(6)<<"Estado|";

    }
    cout<<endl;

    for(int i = 0; i<120;i++){
        cout<<"-";
    }
    cout<<endl;

}

//Funcion para generar la linea de produccion
void generarLP(Cola arona, Cola ateca, Cola ibiza, Cola toledo, coche coches[]){

    ;
}
// funcion para generar coches para fabricar
coche generarCoches(){
    struct coche c;
        c.bastidor = generarBastidor();
        c.color = generarColor();
        c.estado = "fi";
        c.modelo = generarModelo();

    return c;
}

//Destructor
Cola::~Cola() {
    while (frente) desencolar();
}
Pila::~Pila() {
    while (cima) desapilar();
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

    // Nodo apunta al primer elemento de la cola
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

//funcion para comprobar que la cola esta vacia
bool Cola::vacia(){
    pnodo nodo;
    nodo = frente;
    if (!nodo)
        return true;
    return false;
}
int menu() {
}

void Pila::apilar(int v) {
    pnodo nuevo;
    nuevo = new Nodo(v,cima);
    cima = nuevo;
}
int Pila::desapilar() {
    pnodo nodo;
    int v;
    if(!cima)return 0;

    nodo = cima;
    cima=nodo->siguiente;

    v = nodo->valor;
    delete nodo;

    return v;

}

void Pila::mostrarCima() {
    if(!cima)
        cout << "Cima: null"<<endl;
    else
        cout << "Cima: "<<cima->valor<<endl;
}


