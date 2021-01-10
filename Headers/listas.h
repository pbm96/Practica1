//
// Created by Pablo on 07/01/2021.
//

#ifndef LISTAS_LISTAS_H
#define LISTAS_LISTAS_H
using namespace std;
class Nodo
{
private:
    int valor;
    Nodo *siguiente;
    friend class Lista;
public:
    Nodo(int v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }

};

class NodoDoble
{
private:
    int valor;
    NodoDoble *siguienteDoble;
    NodoDoble *anteriorDoble;
    friend class ListaDoble;
public:
    NodoDoble(int v, NodoDoble *sig = NULL, NodoDoble *ant = NULL)
    {
        valor = v;
        siguienteDoble = sig;
        anteriorDoble = ant;
    }

};
class NodoArbol
{
public:
    NodoArbol(const int dat, NodoArbol *izq=NULL, NodoArbol *der=NULL):
    dato(dat),izquierdo(izq),derecho(der){}
        int dato;
        NodoArbol *izquierdo;
        NodoArbol *derecho;

};
typedef Nodo *pnodo;
typedef NodoDoble *pnodoDoble;
typedef NodoArbol *pNodoArbol;


class Lista
{
private:
    pnodo cabeza, actual, final;
public:
    Lista(){cabeza = actual = final = NULL;}
    ~Lista();
    void insertarNodo(int v);
    void borrarNodo(int v);
    bool listaVacia();
    void recorrerLista();
    void esSiguiente();
    void esPrimero();
    void esUltimo();
    bool esActual();
    int valorActual();
    void insertarNodoIntermedio(int vnuevo, int posicion);
};

class ListaDoble
{
private:
    pnodoDoble cabeza, actual, final;
public:
    ListaDoble() {cabeza=actual=final=NULL; }
    ~ListaDoble();
    void insertarNodo(int v, char c);
    void borrarNodo(char c);
    bool listaVacia();
    void recorrerLista(int);
    void esSiguiente();
    void esAnterior(); void
    esPrimero();
    void esUltimo();
    bool esActual();
    int valorActual();
};
class Arbol {
private:
    NodoArbol *raiz,*actual;
    int contador, altura;


public:
    Arbol() : raiz(NULL), actual(NULL) {}
    ~Arbol() { Podar(raiz); }
    void Insertar(const int dat);
    void Borrar(const int dat);
    bool Buscar (const int dat);
    bool Vacio(NodoArbol *r){return r== NULL;}
    bool EsHoja(NodoArbol *r){return !r->derecho && !r->izquierdo;}
    const int NumeroNodos();
    const int AlturaArbol();
    int Altura (const int dat);
    int &ValorActual (){return actual->dato;}
    void Raiz(){actual = raiz;}
    void InOrden(void (*func)(int&),NodoArbol *nodoArbol= NULL, bool r = true);
    void PreOrden(void (*func)(int&),NodoArbol *nodoArbol= NULL, bool r = true);
    void PostOrden(void (*func)(int&),NodoArbol *nodoArbol= NULL, bool r = true);
private:
    void Podar(NodoArbol* &);
    void auxContador(NodoArbol*);
    void auxAltura(NodoArbol*, int);
};
#endif //LISTAS_LISTAS_H
