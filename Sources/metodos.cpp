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
        cout<<setw(9)<<"Bastidor|"<<setw(7)<<"Color|"<<setw(9)<<"Modelo|"<<setw(6)<<"Estado|";

    }
    cout<<endl;

    for(int i = 0; i<120;i++){
        cout<<"-";
    }
    cout<<endl;

}

void generarLP(Cola arona, Cola ateca, Cola ibiza, Cola toledo, coche coches[]){
    while (!arona.vacia() || !ateca.vacia() || !ibiza.vacia() || !toledo.vacia()){

        if(!arona.vacia()) {
            int i = arona.desencolar();
            cout << setw(8)<<coches[i].bastidor << "|" <<  setw(6)<<coches[i].modelo << "|" <<setw(8)<<coches[i].color << "|" <<setw(6)<<coches[i].estado << "|";
        } else
            cout << setw(8)<<" "<< "|" << setw(6)<<" "<< "|"<< setw(8)<<" "<< "|"<< setw(6)<<" "<< "|";
        if(!ateca.vacia()) {
            int j = ateca.desencolar();
            cout << setw(8)<<coches[j].bastidor << "|" <<  setw(6)<<coches[j].modelo << "|" <<setw(8)<<coches[j].color << "|" <<setw(6)<<coches[j].estado << "|";
        } else
            cout << setw(8)<<" "<< "|" << setw(6)<<" "<< "|"<< setw(8)<<" "<< "|"<< setw(6)<<" "<< "|";
        if(!ibiza.vacia()) {
            int k = ibiza.desencolar();
            cout << setw(8)<<coches[k].bastidor << "|" <<  setw(6)<<coches[k].modelo << "|" <<setw(8)<<coches[k].color << "|" <<setw(6)<<coches[k].estado << "|";
        } else
            cout << setw(8)<<" "<< "|" << setw(6)<<" "<< "|"<< setw(8)<<" "<< "|"<< setw(6)<<" "<< "|";

        if(!toledo.vacia()) {
            int x = toledo.desencolar();
            cout << setw(8)<<coches[x].bastidor << "|" <<  setw(6)<<coches[x].modelo << "|" <<setw(8)<<coches[x].color << "|" <<setw(6)<<coches[x].estado << "|";
        } else
            cout << setw(8)<<" "<< "|" << setw(6)<<" "<< "|"<< setw(8)<<" "<< "|"<< setw(6)<<" "<< "|";

        cout<<endl;

    }
}

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

bool Cola::vacia(){
    pnodo nodo;
    nodo = frente;
    if (!nodo)
        return true;
    return false;
}
int menu() {
}



