/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Ejemplo de Lista Simple
 * Autor: Estiven Oña
 * Fecha de creación: 29/05/2024
 * Fecha de modificación: 29/05/2024
*/
#include <iostream>
using namespace std;

//struct Nodo
struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Plantillas de función
void ingresarLista(Nodo *&, int);

void mostrarLista(Nodo *);
float calcularProm(Nodo *);

int main(){
    Nodo *lista = NULL;
    int dato;
    char seleccion;
    do{
        cout<<"Ingrese un número: ";
        cin>>dato;
        ingresarLista(lista, dato);
        cout<<"Desea ingresar otro número? (s/n): ";
        cin>>seleccion;
    }while(toupper(seleccion) == 'S');
    cout<<"Elementos de la lista: \n--------------------------";
    mostrarLista(lista);
    cout<<"El promedio de la lista ingresada es de: "<<calcularProm(lista)<<endl;
    return 0;
}

void ingresarLista(Nodo *&lista, int n){
    Nodo *nuevo = new Nodo();
    Nodo *aux;
    nuevo->dato = n;
    nuevo->siguiente = NULL;

    if(lista == NULL){
        lista = nuevo;
    }else{
        aux = lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    cout<<"Elemento "<< n <<" agregado a la lista por la cola";
}

void mostrarLista(Nodo *lista){
    while(lista != NULL){
        cout<<lista -> dato<<" || ";
        lista = lista ->siguiente;
    }
}

float calcularProm(Nodo *lista){
    int suma=0, contador=0;
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        suma += actual -> dato;
        actual = actual -> siguiente;
        contador++;
    }
    return (float)suma/(float)contador;
}