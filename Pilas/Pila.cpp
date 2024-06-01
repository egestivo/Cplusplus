#include <iostream>
#include <stdlib.h>
using namespace std;

//Struct Nodo
struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Prototipo de función
void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int&);
void mostrarPila(Nodo*);


//Nodo pila global para el menú
Nodo *pila = NULL;

int main(){

    int n1;
    char eleccion;
    do{
    cout<<"Digite un número: ";
    cin>>n1;
    agregarPila(pila, n1);
    cout<<"Desea ingresar otro número? (s/n): ";
    cin>>eleccion;
    }while(toupper(eleccion) == 'S');
    return 0;
}

//TODO: Inicio de funciones
void agregarPila(Nodo *&pila, int n){
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->siguiente = pila;
    pila = nuevo;
    cout<<"Elemento "<< n <<" agregado a la pila";
}

void sacarPila(Nodo *&pila, int &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

void mostrarPila(Nodo *pila){
    while(pila != NULL){
        cout<<pila->dato<<endl;
        pila = pila->siguiente;
    }
}

void menu(){
    char eleccion;
    int dato;
    do{

        cout<<"|||--------------MENÚ PRINCIPAL--------------|||\n";
        cout<<"1. Agregar elementos a la pila\n";
        cout<<"2. Sacar elementos de la pila\n";
        cout<<"3. Mostrar elementos de la pila\n";
        cout<<"4. Salir\n";
        cout<<"|||-------------------------------------------|||\n";
        cout<<"Digite su opción: ";
        cin>>eleccion;
        switch(eleccion){
            case '1':
                cout<<"Digite un número: ";
                cin>>dato;
                agregarPila(pila, dato);
                break;
            case '2':
                cout<<"Sacando elementos de la pila: ";
                while(pila != NULL){
                    sacarPila(pila, dato);
                    if(pila != NULL){
                        cout<<dato<<" , ";
                    }else{
                        cout<<dato<<".";
                    }
                }
                cout<<"\n";
                break;
            case '3':
                cout<<"Mostrando Pila\n";
                mostrarPila(pila);
                break;
            case '4':
                cout<<"Saliendo del programa...\n";
                break;
            default:
                cout<<"Opción no válida\n";
                break;
        }
    }while(eleccion != 3);
}