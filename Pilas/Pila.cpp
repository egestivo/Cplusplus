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

//TODO: Inicio de funciones
void agregarPila(Nodo *&pila, int n){
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->siguiente = pila;
    pila = nuevo;
    cout<<"Elemento "<< n <<" agregado a la pila";
}