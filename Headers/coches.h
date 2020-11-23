//
// Created by pablo on 20/11/20.
//

#define N1 100
#ifndef PRACTICA1_COCHES_H
#define PRACTICA1_COCHES_H

using namespace std;

struct coche {
    string bastidor;
    string color;
    string estado;
    string modelo;
};


void generarCabezera();
string generarBastidor();
string generarModelo();
coche generarCoches();
string generarColor();


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




};


#endif //PRACTICA1_COCHES_H
