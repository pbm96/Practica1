//
// Created by Pablo on 07/01/2021.
//
#define N1 7 //Concesionarios
#define N2 100 // coches generados
#define N3 12 // coches enviados a cada concesionario
#define N4 7*N3 // con este numero se muestra el menu

#ifndef LISTAS_LISTAS_H
#define LISTAS_LISTAS_H
using namespace std;
struct coche {
    string bastidor;
    string color;
    string modelo;
};struct concesionario;

class Nodo
{
private:
    coche valor;
    Nodo *siguiente;
    friend class Lista;
public:
    Nodo(coche v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }

};

class NodoDoble
{
private:
    coche valor;
    NodoDoble *siguienteDoble;
    NodoDoble *anteriorDoble;
    friend class ListaDoble;
public:
    NodoDoble(coche v, NodoDoble *sig = NULL, NodoDoble *ant = NULL)
    {
        valor = v;
        siguienteDoble = sig;
        anteriorDoble = ant;
    }

};
typedef Nodo *pnodo;
typedef NodoDoble *pnodoDoble;


class Lista
{
private:
    pnodo cabeza, actual, final;
public:
    Lista(){cabeza = actual = final = NULL;}
    ~Lista();
    void insertarNodo(coche v);
    void borrarNodo(coche v);
    bool listaVacia();
    void recorrerLista();
    void esSiguiente();
    void esPrimero();
    void esUltimo();
    bool esActual();
    coche valorActual();
    void insertarNodoIntermedio(coche vnuevo, coche posicion);
};

struct concesionario {
    string localidad;
    int clave;
    Lista automoviles;
};
class NodoArbol
{
public:
    NodoArbol(const concesionario dat, NodoArbol *izq=NULL, NodoArbol *der=NULL):
    dato(dat),izquierdo(izq),derecho(der){}
        concesionario dato;
        NodoArbol *izquierdo;
        NodoArbol *derecho;

};




class ListaDoble
{
private:
    pnodoDoble cabeza, actual, final;
public:
    ListaDoble() {cabeza=actual=final=NULL; }
    ~ListaDoble();
    void insertarNodo(coche v, char c);
    void borrarNodo(char c);
    bool listaVacia();
    void recorrerLista(int);
    void esSiguiente();
    void esAnterior(); void
    esPrimero();
    void esUltimo();
    bool esActual();
    coche valorActual();
};
typedef NodoArbol *pNodoArbol;

class Arbol {
private:
    NodoArbol *raiz,*actual;
    int contador, altura;


public:
    Arbol() : raiz(NULL), actual(NULL) {}
    ~Arbol() { Podar(raiz); }
    void Insertar(const concesionario dat);
    void Borrar(const concesionario dat);
    bool Buscar (const concesionario dat);
    bool Vacio(NodoArbol *r){return r== NULL;}
    bool EsHoja(NodoArbol *r){return !r->derecho && !r->izquierdo;}
    const int NumeroNodos();
    const int AlturaArbol();
    int Altura (const concesionario dat);
    concesionario &ValorActual (){return actual->dato;}
    void Raiz(){actual = raiz;}
    void InOrden(void (*func)(concesionario&),NodoArbol *nodoArbol= NULL, bool r = true);
    void PreOrden(void (*func)(concesionario&),NodoArbol *nodoArbol= NULL, bool r = true);
    void PostOrden(void (*func)(concesionario&),NodoArbol *nodoArbol= NULL, bool r = true);
private:
    void Podar(NodoArbol* &);
    void auxContador(NodoArbol*);
    void auxAltura(NodoArbol*, int);
};

void generarCabezeraAD();
void generarCabezeraConc();
string generarBastidor();
string generarModelo();
string generarColor();
coche generarCoches();
int generarClaveConcesionario();
concesionario generarConcesionario();
string generarLocalidad();
#endif //LISTAS_LISTAS_H
