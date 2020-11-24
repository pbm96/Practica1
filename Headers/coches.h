//
// Created by pablo on 20/11/20.
//

#define N1 100
#define N2 8
#define N3 8
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
    friend class Pila;

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
class Pila {
private:
    pnodo cima;
public:
    Pila() : cima(NULL) {}

    ~Pila();

    void apilar(int v);

    int desapilar();
    void mostrarCima();



};
void generarCabezera();
void generarLP(Cola arona, Cola ateca, Cola ibiza, Cola toledo, coche coches[]);
string generarBastidor();
string generarModelo();
string generarColor();
coche generarCoches();



#endif //PRACTICA1_COCHES_H
