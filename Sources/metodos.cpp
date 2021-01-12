//
// Created by Pablo on 07/01/2021.
//

#include <iostream>
#include <iomanip>
#include "../Headers/listas.h"
using namespace std;


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
int generarClaveConcesionario() {

    //Ejemplo:453

    int clave;

    for (int i = 0; i < 3; ++i)
        clave = 100+rand()%(1000-100);

    return clave;

}
// Metodo para generar color del coche aleatorio

string generarColor() {

    string color;
    int posicion;
    string colores[6] ={"Blanco","Rojo","Negro","Azul","Naranja","Gris"};
    posicion =  rand()%6;
    color = colores[posicion];

    return color;

}

string generarLocalidad() {

    string localidad;
    int posicion;
    string localidades[4] ={"Alcobendas","Alcala","Torrejon","Pinto"};
    posicion =  rand()%4;
    localidad = localidades[posicion];

    return localidad;

}

string generarModelo() {

    string modelo;
    int posicion;
    string modelos[4] ={"Golf","Polo","Passat","T-Roc"};
    posicion =  rand()%4;
    modelo = modelos[posicion];

    return modelo;

}
coche generarCoches(){
    struct coche c;
    c.bastidor = generarBastidor();
    c.color = generarLocalidad();
    c.modelo = generarModelo();

    return c;
}
concesionario generarConcesionario(){
    struct concesionario c;
    c.clave = generarClaveConcesionario();
    c.localidad = generarLocalidad();

    return c;
}
void generarCabezeraAD(){

    cout<<setw(39)<<"|Area de distribucion|"<<endl;
    //genera guiones
    for(int i = 0; i<60;i++){
        cout<<"-";
    }
    cout<<endl;
    //genera titulos
   {
        cout<<setw(20)<<"|Bastidor|"<<setw(15)<<"|Modelo|"<<setw(15)<<"|Color|";


    }
    cout<<endl;
//genera guiones
    for(int i = 0; i<60;i++){
        cout<<"-";
    }
    cout<<endl;

}
void generarCabezeraConc(){

    cout<<setw(150)<<"|CONCESIONARIOS|"<<endl;
    for(int i = 0; i<300;i++){
        cout<<"-";
    }
    cout<<endl;
    for(int i = 0; i<N1;i++){
        cout<<setw(20)<<"|Clave|"<<setw(20)<<"|Localidad|";
    }
    cout<<endl;

    for(int i = 0; i<300;i++){
        cout<<"-";
    }
    cout<<endl;
    for(int i = 0; i<N1;i++){
        cout<<setw(17)<<"|Bastidor|"<<setw(12)<<"|Modelo|"<<setw(12)<<"|Color|";
    }
    cout<<endl;
    for(int i = 0; i<300;i++){
        cout<<"-";
    }

}

//TADS
Lista::~Lista()
{
    pnodo aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}

void Lista::insertarNodo(coche v) {
    pnodo aux;
    if (listaVacia())
    {
        cabeza = new Nodo(v, NULL);
        final=cabeza;
    }
    else
    {
        aux= new Nodo(v,NULL);
        final->siguiente=aux;
        final=aux;
    }
}

void Lista::insertarNodoIntermedio(coche vnuevo, coche posicion) {
    pnodo aux;
    actual = cabeza;
    if(listaVacia()){
        cabeza = new Nodo(vnuevo, NULL);
        final = cabeza;
    }
    else{
        while (actual->valor.bastidor != posicion.bastidor && actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        aux = new Nodo(vnuevo, NULL);
        aux->siguiente = actual->siguiente;
        actual->siguiente = aux;
    }
}

void Lista::borrarNodo(coche v) {
    pnodo anterior;
    actual = cabeza;
    while (actual->valor.bastidor!=v.bastidor && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual->valor.bastidor == v.bastidor) {
        if (actual == cabeza) // Primer elemento
            cabeza = actual->siguiente;
        else {
            anterior->siguiente = actual->siguiente;
            if (actual == final) {
                final = anterior;
            }
        }
        actual->siguiente = NULL;
        delete actual;
    }
}

bool Lista::listaVacia()
{
    return cabeza == NULL;
}
void Lista::recorrerLista()
{
    pnodo aux;
    aux = cabeza;
    while(aux) {
        cout << aux->valor.bastidor << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}


void Lista::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}
void Lista::esPrimero()
{
    actual = cabeza;
}

void Lista::esUltimo()
{
    esPrimero();
    if(!listaVacia())
        while(actual->siguiente)
            esSiguiente();
}

bool Lista::esActual()
{
    return actual != NULL;
}
coche Lista::valorActual()
{
    return actual->valor;
}

const int ASCENDENTE=0;
const int DESCENDENTE=1;
ListaDoble::~ListaDoble()
{
    pnodoDoble aux;
    esPrimero();
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguienteDoble;
        delete aux;
    }
    cabeza=NULL;
    actual=NULL;
    final=NULL;
}

void ListaDoble::insertarNodo(coche v, char c)
{
    pnodoDoble aux;
    char tipoInsercion; tipoInsercion=c;
    if(listaVacia()) { // Si la lista está vacía
        aux = new NodoDoble(v,NULL,NULL);
        final=cabeza=aux;
    }
    else if (tipoInsercion=='f') {//Inserción por el final
        aux= new NodoDoble(v,NULL,NULL);
        aux->anteriorDoble=final;
        final->siguienteDoble=aux;
        final=aux;
    }
    else if (tipoInsercion=='p') {//Inserción por el principio
        aux= new NodoDoble(v,NULL,NULL);
        aux->siguienteDoble=cabeza;
        cabeza->anteriorDoble=aux;
        cabeza=aux;
    }
}

void ListaDoble::borrarNodo(char c)
{
    char tipoBorrado; tipoBorrado=c;
    if(tipoBorrado=='f') {//Eliminación por el final
        pnodoDoble aux=NULL;
        if((cabeza==final)) { //Sólo hay elemento
            aux=final;
            cabeza = final = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=final;
            final=final->anteriorDoble;
            aux->anteriorDoble=NULL;
            final->siguienteDoble=NULL;
            delete aux;
        }
    }


    else if(tipoBorrado=='p') {//Eliminación por el Principio
        pnodoDoble aux=NULL;
        if((cabeza==final)) {//Sólo hay elemento
            aux=cabeza;
            cabeza = final = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=cabeza;
            cabeza=cabeza->siguienteDoble;
            aux->siguienteDoble=NULL;
            cabeza->anteriorDoble=NULL;
            delete aux;
        }
    }
}

void ListaDoble::recorrerLista (int orden)
{ pnodoDoble aux;
    if (orden == ASCENDENTE) {
        esPrimero();
        aux = cabeza;
        while(aux) {
            cout << aux->valor.bastidor << "-> "; aux = aux->siguienteDoble;
        }
    }
    else {
        esUltimo();
        aux = final;
        while(aux) {
            cout << aux->valor.bastidor << "-> "; aux = aux->anteriorDoble;
        }
    }
    cout << endl;
}

bool ListaDoble::listaVacia()
{
    return cabeza == NULL;
}
void ListaDoble::esSiguiente()
{
    if(actual) actual = actual->siguienteDoble;
}
void ListaDoble::esAnterior()
{
    if(actual) actual = actual->anteriorDoble;
}
void ListaDoble::esPrimero()
{
    actual=cabeza;
}
void ListaDoble::esUltimo()
{
    actual=final;
}
bool ListaDoble::esActual()
{
    return actual != NULL;
}
coche ListaDoble::valorActual()
{
    if (!listaVacia())return actual->valor;
}
void Arbol::Podar(NodoArbol* &nodo)
{
    if(nodo) {
        Podar(nodo->izquierdo); // Podar izquierdo
        Podar(nodo->derecho);
        delete nodo;
        nodo = NULL;
    }
}
bool Arbol::Buscar(const concesionario dat)
{
    actual = raiz;
    while(!Vacio(actual))
    {
        if(dat.clave == actual->dato.clave) return true;
        else
        if(dat.clave > actual->dato.clave) actual = actual->derecho;
        else if(dat.clave < actual->dato.clave) actual = actual->izquierdo;
    }
    return false;
}
void Arbol::Insertar (const concesionario dat)
{
    NodoArbol *padre = NULL;
    actual = raiz;
    while(!Vacio(actual) && dat.clave != actual->dato.clave)
    {
        padre = actual;
        if(dat.clave > actual->dato.clave) actual = actual->derecho;
        else if(dat.clave < actual->dato.clave) actual = actual->izquierdo;
    }
    if(!Vacio(actual)) return;
    if(Vacio(padre)) raiz = new NodoArbol(dat);
    else if(dat.clave < padre->dato.clave) padre->izquierdo = new NodoArbol(dat);
    else if(dat.clave > padre->dato.clave) padre->derecho = new NodoArbol(dat);
}
void Arbol::Borrar(const concesionario dat)
{
    NodoArbol *padre = NULL;
    NodoArbol *nodo;
    int aux;
    actual = raiz;
    while(!Vacio(actual))
    {
        if(dat.clave == actual->dato.clave) { // Si el valor está en el nodo actual
            if(EsHoja(actual)){
                if(padre) // Si tiene padre (no es el nodo raiz)
                    if(padre->derecho == actual) padre->derecho = NULL;
                    else if(padre->izquierdo == actual) padre->izquierdo = NULL;
                delete actual; // Borrar el nodo
                actual = NULL;
                return;
            }
            else
            {
                padre = actual;
                if(actual->derecho)
                {
                    nodo = actual->derecho;
                    while(nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                else
                {
                    nodo = actual->izquierdo;
                    while(nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
                aux = actual->dato.clave;
                actual->dato = nodo->dato;
                nodo->dato.clave = aux;
                actual = nodo;
            }
        }
        else
        {
            padre = actual;
            if(dat.clave > actual->dato.clave) actual = actual->derecho;
            else if(dat.clave < actual->dato.clave) actual = actual->izquierdo;
        }
    }
}
void Arbol::PreOrden(void (*func)(concesionario&), NodoArbol *nodo, bool r)
{
    if(r) nodo = raiz;
    func(nodo->dato);
    if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
    if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}
void Arbol::InOrden(void (*func)(concesionario &), NodoArbol *nodoArbol, bool r)
{
    if(r) nodoArbol = raiz;
    if(nodoArbol->izquierdo)InOrden(func,nodoArbol->izquierdo, false);
    func(nodoArbol->dato);
    if(nodoArbol->derecho)InOrden(func,nodoArbol->derecho, false);

}
void Arbol::PostOrden(void (*func)(concesionario &), NodoArbol *nodoArbol, bool r)
{
    if(r) nodoArbol = raiz;
    if(nodoArbol->izquierdo)PostOrden(func,nodoArbol->izquierdo, false);
    if(nodoArbol->derecho)PostOrden(func,nodoArbol->derecho, false);
    func(nodoArbol->dato);

}
 int Arbol::Altura(const concesionario dat) {
    int altura = 0;
    actual = raiz;

    while (!Vacio(actual)){
        if(dat.clave == actual->dato.clave) return altura;
        else{
            altura++;
            if(dat.clave > actual->dato.clave) actual = actual->derecho;
            if(dat.clave < actual->dato.clave) actual = actual->izquierdo;

        }
    }
     return -1;


}

const int Arbol::NumeroNodos() {
    contador = 0;
    auxContador(raiz);
    return contador;
}



//   preorden, el proceso es aumentar el contador
void Arbol::auxContador(NodoArbol *nodoArbol)
{
    contador++;  // Otro nodo
    // Continuar recorrido
    if(nodoArbol->izquierdo) auxContador(nodoArbol->izquierdo);
    if(nodoArbol->derecho)   auxContador(nodoArbol->derecho);
}

// Calcular la altura del Ã¡rbol, que es la altura del nodo de mayor altura.
const int Arbol::AlturaArbol()
{
    altura = 0;

    auxAltura(raiz, 0); // FunciÃ³n auxiliar
    return altura;
}

// FunciÃ³n auxiliar para calcular altura. FunciÃ³n recursiva de recorrido en
// postorden, el proceso es actualizar la altura sÃ³lo en nodos hojas de mayor
// altura de la mÃ¡xima actual
void Arbol::auxAltura(NodoArbol *nodo, int a)
{
    // Recorrido postorden
    if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
    if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
    // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
    // Ã¡rbol, actualizamos la altura actual del Ã¡rbol
    if(EsHoja(nodo) && a > altura) altura = a;
}