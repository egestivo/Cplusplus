/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Ejemplo de Lista Simple
 * Autor: Estiven Oña
 * Fecha de creación: 29/05/2024
 * Fecha de modificación: 29/05/2024
*/
#include <iostream>
using namespace std;

template <typename T>
struct Nodo{
    T dato;
    Nodo *siguiente;
};
//Prototipo de función
template <typename T>
void ingresarLista(Nodo<T> *&, T);
template <typename T>
void mostrarLista(Nodo<T> *);
template <typename T>
void calcularMayorMenor(Nodo<T> *);



int main(){
    int dato;
    char respuesta;
    Nodo<int> *lista = NULL;

    do{
        cout<<"Digite un número: ";
        cin>>dato;
        ingresarLista<int>(lista, dato);
        cout<<"Desea agregar otro nodo? (s/n): ";
        cin>>respuesta;
    }while((toupper(respuesta)=='S'));
    mostrarLista<int>(lista);
    calcularMayorMenor<int>(lista);
}

template <typename T>
void ingresarLista(Nodo<T> *&lista, T n){
    Nodo<T> *nuevo = new Nodo<T>();
    Nodo<T> *aux;
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
template <typename T>
void mostrarLista(Nodo<T> *lista){
    Nodo<T> *actual = new Nodo<T>();
    actual = lista;
    while(actual != NULL){
        cout<<actual->dato<<" -> ";
        actual = actual->siguiente;
    }
}
template <typename T>
void calcularMayorMenor(Nodo<T> *lista){
    int mayor=0, menor=999999;
    while(lista != NULL){
        if(lista->dato > mayor){
            mayor = lista->dato;
        }else if(lista->dato < menor){
            menor = lista->dato;
        }
        lista = lista->siguiente;
    }
    cout<<"El mayor elemento es: "<<mayor<<endl;
    cout<<"El menor elemento es: "<<menor<<endl; 
}

