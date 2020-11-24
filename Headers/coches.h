//
// Created by pablo on 20/11/20.
//

#define N1 20
#ifndef PRACTICA1_COCHES_H
#define PRACTICA1_COCHES_H

using namespace std;

struct coche {
    string bastidor;
    string color;
    string estado;
    string modelo;
};





class Nodo {
private:
    int valor;
    Nodo *siguiente;

    friend class Cola;

public:
    Nodo(int v, Nodo *sig = NULL) {
        valor = v;
        siguiente = sig;
    }
};

typedef Nodo *pnodo;

class Cola {
private:
    pnodo frente, final;
public:
    Cola() : frente(NULL), final(NULL) {}

    ~Cola();

    void encolar(int v);

    int desencolar();
    bool vacia();



};
void generarCabezera();
void generarLP(Cola arona, Cola ateca, Cola ibiza, Cola toledo, coche coches[]);
string generarBastidor();
string generarModelo();
coche generarCoches();
string generarColor();

int menu();


#endif //PRACTICA1_COCHES_H
