#include <iostream>
#include <iomanip>
#include <fstream>

#include "../Headers/listas.h"
#include<ctime>

using namespace std;


// funcion para mostrar los concesionarios
void MostrarConcesionarioCoches(concesionario &d){
    coche c;

        d.automoviles.esPrimero();
    cout<<endl;
        while(d.automoviles.esActual()) {

            cout <<setw(15)<<d.automoviles.valorActual().bastidor<<"|"<<setw(11)<<d.automoviles.valorActual().modelo<<"|"<<setw(11)<<d.automoviles.valorActual().color <<"|"<<setw(19)<<d.clave<<"|"<<setw(19)<<d.localidad<<"|"<<setw(19)<<d.automoviles.valorActual().dia<<"|"<< endl;

            d.automoviles.esSiguiente();
        }


}
//Funcion para exportar archivos
ofstream file;
void MostrarConcesionarioCochesTxt(concesionario &d){

    coche c;

    d.automoviles.esPrimero();
    file<<endl;
    while(d.automoviles.esActual()) {
        file <<setw(15)<<d.automoviles.valorActual().bastidor<<"|"<<setw(11)<<d.automoviles.valorActual().modelo<<"|"<<setw(11)<<d.automoviles.valorActual().color <<"|"<<setw(19)<<d.clave<<"|"<<setw(19)<<d.localidad<<"|"<<setw(19)<<d.automoviles.valorActual().dia<<"|"<< endl;

        d.automoviles.esSiguiente();
    }


}
// Funcion para mostrar las estadisticas de un modelo en concreto
string modelo;
int contModelo=0;
void MostrarEstadisticasCoches(concesionario &d){
    coche c;

    d.automoviles.esPrimero();
    while(d.automoviles.esActual()) {
    if(modelo == d.automoviles.valorActual().modelo) {
        contModelo++;
    }
    d.automoviles.esSiguiente();
    }


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

//Funcion para introducir automomovil manualmente en concesionario
int claveManual;
coche cManual;
void introducirAutomovilManual(concesionario &d){
    if(claveManual == d.clave){
        d.automoviles.insertarNodo(cManual);
    }
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

    // Generamos los coches del centro de almacenamiento
    for (int i = 0; i < N2; i++) {
        coche c = generarCoches();
        almacenDistribucion.insertarNodo(c, 'f');

    }



    cout <<endl;

    do {
         cout <<cochesEnConcesionarios<<endl;
        generarCabezeraAD();
        almacenDistribucion.recorrerLista(0);
        // Mostramos concesionarios
        if(dia>1){
        almacenDistribucion.esPrimero();

            generarCuerpoConc();
        concesionarios.InOrden(MostrarConcesionarioCoches);
    }

        // sacamos los coches de la lista y los movemos a los concesionarios
        for (int i = 0; i < N3; i++) {
            if (!almacenDistribucion.listaVacia()) {
                cochePrimero = almacenDistribucion.valorActual();
                cochePrimero.dia = dia;
                // Movemos el puntero;

                almacenDistribucion.esSiguiente();
                // Borramos el coche del almacen de distribucion
                almacenDistribucion.borrarNodo('p');
                numeroAleatorioConcesionario =  rand() % N1 ;

                numero = 0;
                concesionarios.InOrden(concesionarioAleatorio);
            }
        }

        cout<< "dia: "<<dia<<endl;
        cochesEnConcesionarios+=N3;

        dia++;
        system("pause");


    }while (cochesEnConcesionarios<N4);

    generarCabezeraAD();
    almacenDistribucion.recorrerLista(0);
    cout<<endl;
    generarCuerpoConc();
    concesionarios.InOrden(MostrarConcesionarioCoches);
    bool menu = true;
    int a,b;

    do {
        //Mostramos el menu despues del paso 7
        int claveConcesionario, claveConcesionarioNuevo;
        string bastidorCoche, localidadConcesionario, modeloMostrar;
        almacenDistribucion.esPrimero();
        concesionarios.Raiz();
        cout << "1- Insertar un concesionario aleatoriamente\n";
        cout << "2- Insertar un concesionario de forma manual\n";
        cout << "3- Borrar un concesionario\n";
        cout << "4- Mostrar los datos de los automoviles que tiene en exposicion un concesionario dado\n";
        cout << "5- Mostrar una estadistica de los concesionarios de la empresa\n";
        cout << "6- Vender algun automovil concreto de un concesionario concreto \n";
        cout << "7- Llevar un automovil concreto del AD a un concesionario concreto.\n";
        cout << "8- Llevar un automovil concreto de un concesionario a otro.\n";
        cout << "9- Exportar datos concesionario a .txt\n";

        cout << "0- Salir\n";

        cin >> a;


        switch (a) {
            case 1: {
                // generar concesionario Aleatorio
                concesionario c = generarConcesionario();
                cout << "Se ha insertado un concesionario aleatoriamente en: " << c.localidad << " con clave: "
                     << c.clave << endl;


                concesionarios.Insertar(c);

                dia++;
                break;
            }
            case 2:{
                cout << "Introducir clave de concesionario Nuevo: " << endl;
                cin >> claveConcesionario;
                cout << "Introducir localidad de concesionario " << endl;
                cin >> localidadConcesionario;

                concesionario c = generarConcesionarioManual(localidadConcesionario, claveConcesionario);


                concesionarios.Insertar(c);
                cout << "Se ha insertado un concesionario manualmente en: " << c.localidad << " con clave: "
                     << c.clave << endl;
                dia++;
                break;

            }
            case 3: {
                // Borrar concesionario:
                cout << "Introducir clave de concesionario a borrar: " << endl;
                cin >> claveConcesionario;

                // buscamos el concesionario a borrar
                if (concesionarios.Buscar(claveConcesionario)) {
                    concesionarios.Borrar(concesionarios.ValorActual());
                    cout << "Se ha borrado el concesionario. " << endl;

                } else
                    cout << "No se ha encontrado el concesionario. " << endl;

                generarCuerpoConc();
                almacenDistribucion.esPrimero();
                concesionarios.Raiz();
                concesionarios.InOrden(MostrarConcesionarioCoches);
                dia++;
                break;
            }

            case 4: {
                concesionario cMostrar;
                cout << "Introducir clave de concesionario para mostrar: " << endl;
                cin >> claveConcesionario;
                //Buscamos el concesionario para mostrar
                if (concesionarios.Buscar(claveConcesionario)) {
                    cMostrar = concesionarios.ValorActual();
                    // Mostramos el concesionario
                    cMostrar.automoviles.esPrimero();
                    while(cMostrar.automoviles.esActual()) {

                        cout <<setw(15)<<cMostrar.automoviles.valorActual().bastidor<<"|"<<setw(11)<<cMostrar.automoviles.valorActual().modelo<<"|"<<setw(11)<<cMostrar.automoviles.valorActual().color <<"|"<< endl;

                        cMostrar.automoviles.esSiguiente();
                    }
                    cMostrar.automoviles.esPrimero();
                }else{
                    cout<<"No se ha encontrado el concesionario. "<<endl;

                }
                concesionarios.Raiz();

                dia++;
                break;
            }
            case 5: {
                cout << "Introducir modelo a mostrar en estadisticas " << endl;
                cin >> modelo;
                concesionarios.InOrden(MostrarEstadisticasCoches);
                cout <<"Los concesionarios tienen: "<<contModelo<<" modelos de "<< modelo<<endl;
                break;
            }

            case 6:{
                concesionario cMostrar;
                bool borrar = false;
                cout << "Introducir clave de concesionario del coche " << endl;
                cin >> claveConcesionario;
                cout << "Introducir bastidor del coche " << endl;
                cin >> bastidorCoche;
                //Buscamos el concesionario del coche
                if (concesionarios.Buscar(claveConcesionario)) {
                    cMostrar = concesionarios.ValorActual();
                    cMostrar.automoviles.esPrimero();
                    while(cMostrar.automoviles.esActual()) {
                        // si se encuentra el coche se borra
                            if(cMostrar.automoviles.valorActual().bastidor == bastidorCoche) {
                                cMostrar.automoviles.borrarNodo(cMostrar.automoviles.valorActual());
                                cout<<"El coche "<<bastidorCoche<<" se ha borrado correctamente"<<endl;
                                borrar = true;
                            }

                        cMostrar.automoviles.esSiguiente();
                    }

                }else{
                    cout<<"No se ha encontrado el concesionario. "<<endl;

                }
                if(!borrar){
                    cout<<"El coche "<<bastidorCoche<<"No se ha encontrado"<<endl;

                }
                generarCuerpoConc();
                concesionarios.InOrden(MostrarConcesionarioCoches);
                dia++;
                break;
                }


            case 7: {
                concesionario cMostrar;
                bool insertar = false;
                cout << "Introducir clave de concesionario del coche " << endl;
                cin >> claveConcesionario;
                cout << "Introducir bastidor del coche " << endl;
                cin >> bastidorCoche;

                // buscamos el concesionario donde llevar el coche
                if (concesionarios.Buscar(claveConcesionario)) {
                    cMostrar = concesionarios.ValorActual();
                   while (almacenDistribucion.esActual()){
                       // Si se encuentra el coche del ad se mueve al concesionario
                       if(almacenDistribucion.valorActual().bastidor == bastidorCoche){

                           coche c =  almacenDistribucion.valorActual();
                           c.dia = dia;
                           cMostrar.automoviles.insertarNodo(c);
                           claveManual = cMostrar.clave;
                           cManual = c;
                            concesionarios.InOrden(introducirAutomovilManual);
                            // se borra el coche del ad
                            almacenDistribucion.borrarNodoIntermedio(almacenDistribucion.valorActual());
                           insertar = true;

                       }
                       almacenDistribucion.esSiguiente();

                   }
                }else{
                    cout<<"No se ha encontrado el concesionario. "<<endl;

                }
                if(!insertar){
                    cout<<"El coche "<<bastidorCoche<<" No se ha encontrado"<<endl;

                }else{
                        cout<<"El coche "<<bastidorCoche<<" Se ha movido al concesionario: "<<cMostrar.clave<<endl;

                }
                almacenDistribucion.esPrimero();
                generarCabezeraAD();
                almacenDistribucion.recorrerLista(0);
                cout<<endl;
                almacenDistribucion.esPrimero();

                generarCuerpoConc();
                concesionarios.InOrden(MostrarConcesionarioCoches);
                dia++;
                break;
            }

            case 8: {
                concesionario cMostrar,cNuevo;
                coche ca;
                bool insertar = false;
                cout << "Introducir clave de concesionario del coche " << endl;
                cin >> claveConcesionario;
                cout << "Introducir bastidor del coche " << endl;
                cin >> bastidorCoche;
                cout << "Introducir clave de concesionario nuevo " << endl;
                cin >> claveConcesionarioNuevo;

                // buscamos el concesionario del coche
                if (concesionarios.Buscar(claveConcesionario)  ) {
                    cMostrar = concesionarios.ValorActual();

                    cMostrar.automoviles.esPrimero();
                    while(cMostrar.automoviles.esActual()) {
                        // si encontramos el coche se traslada al otro concesionario si se encuentra
                        if (cMostrar.automoviles.valorActual().bastidor == bastidorCoche) {
                             ca = cMostrar.automoviles.valorActual();
                             cout<<"bastidor: "<< ca.bastidor;
                        }
                        cMostrar.automoviles.esSiguiente();

                    }
                    cMostrar.automoviles.esPrimero();

                    // si se encuentra el concesionario donde llevar el coche y se borra el antiguo
                    if(concesionarios.Buscar(claveConcesionarioNuevo) && ca.bastidor == bastidorCoche){
                        cNuevo = concesionarios.ValorActual();
                        claveManual = cNuevo.clave;
                        cManual = ca;
                        concesionarios.InOrden(introducirAutomovilManual);
                        cMostrar.automoviles.borrarNodo(ca);

                        cout << "El coche " << bastidorCoche << " se ha añadido correctamente" << endl;
                        insertar = true;
                    }else{
                        cout<<"No se ha encontrado el concesionario nuevo. "<<endl;

                    }
                }else{
                    cout<<"No se ha encontrado el concesionario. "<<endl;

                }
                if(!insertar){
                    cout<<"El coche "<<bastidorCoche<<" No se ha movido correctamente"<<endl;

                }else{
                    cout<<"El coche "<<bastidorCoche<<" Se ha movido al concesionario: "<<cNuevo.clave<<endl;

                }
                almacenDistribucion.esPrimero();
                generarCabezeraAD();
                almacenDistribucion.recorrerLista(0);
                cout<<endl;

                generarCuerpoConc();
                concesionarios.InOrden(MostrarConcesionarioCoches);
                dia++;
                break;
            }
            case 9:{

                file.open("D:/Pablo/Escritorio/eedd.txt");
                file<<setw(16)<<"|Bastidor|"<<setw(12)<<"|Modelo|"<<setw(12)<<"|Color|"<<setw(20)<<"|clave|"<<setw(20)<<"|concesionario|"<<setw(20)<<"|Dia llegada|";

                file<<endl;

                for(int i = 0; i<103;i++){
                    file<<"-";
                }
                file<<endl;
                concesionarios.InOrden(MostrarConcesionarioCochesTxt);
                file.close();

                break;
            }
            case 0:
                cout << "¿Seguro que quieres salir?... SI o NO\n";
                cout << "\n 1-SI";
                cout << "\n 2-NO\n\n";
                cin >> b;
                if (b == 1) {
                    menu = false;

                }
                break;

            default:
                cout << "Debe de introducir 1,2,3\n";
                break;
        }


    }while (menu);

    return 0;
}
