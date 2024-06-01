//* HACER UNA FUNCIÓN LAMBDA RECURSIVA QUE SUME LOS DIGITOS DE CADA NODO DE UNA LISTA
//* SIMPLE, A ESE RESULTADO CIFRARLO SUMANDO SUS CIFRAS Y AGREGARLO A UNA LISTA 2

#include <iostream>
#include <functional>
using namespace std;

/*
 * @File Prueba.cpp
 *This program allow the user to insert numbers in a Linked List, and cifrate 
 *the sum of it's digits passing the cifrated terms to another Linked List
 *Autor: @egestivo
*/

//Struct Nodo
struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Prototipo de función
void insertarLista(Nodo *&, int);
void menu();
void buscarLista(Nodo *, int);
void mostrarLista();
int sumarDigitosRecursivo(int);
int cifrarNumeroRecursivo(int);


//declaramos dos nodos como globales para las funciones
Nodo *lista = NULL;
Nodo *listaCifrada = NULL;

int main(){
    menu();
    return 0;
}

/**
 * Inserts a new node with the given value into a linked list.
 * 
 * @param lista A reference to the head of the linked list.
 * @param n The value to be inserted into the linked list.
 */

void insertarLista(Nodo *&lista, int n){
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
    //Paso uno, crear un nodo actual
    Nodo *actual = new Nodo();
    //Pasar el valor al que apunta lista, en este caso, el primero
    actual = lista;
    std::cout << "-----------------------------------\n";
    //Comprobar que el elemento actual no sea el último, es decir NULL
    while(actual != NULL){
        std::cout<<actual->dato<<" ->";
        actual = actual->siguiente;
    }
    std::cout<<"\n-------------------------------------\n";
}

int sumarDigitosRecursivo(int numero) {
    if (numero == 0) {
        return 0;
    } else {
        return (numero % 10) + sumarDigitosRecursivo(numero / 10);
    }
}

int cifrarNumeroRecursivo(int numero) {
    if (numero < 10) {
        return numero;
    } else {
        return cifrarNumeroRecursivo(sumarDigitosRecursivo(numero));
    }
}
auto sumarDigitos = [](Nodo *lista, Nodo *&lista2) {
    function<void(Nodo*)> sumaRecursiva = [&](Nodo *actual) {
        if (actual != nullptr) {
            // Usar la función recursiva para sumar los dígitos
            int suma = sumarDigitosRecursivo(actual->dato);
            // Usar la función recursiva para cifrar el resultado
            int cifrado = cifrarNumeroRecursivo(suma);
            // Llamar a la inserción en la lista2
            insertarLista(lista2, cifrado);
            // Llamada recursiva para el siguiente nodo
            sumaRecursiva(actual->siguiente);
        }
    };
    sumaRecursiva(lista);
};


void menu(){
    //dato a ingresar a la lista
    int dato, opcion;
    do{
        std::cout<<"|-----MENÚ PRINCIPAL-----|\n";
        std::cout<<"1. Insertar elementos a la lista\n";
        std::cout<<"2. Mostrar elementos de la lista\n";
        std::cout<<"3. Cifrar la lista\n";
        std::cout<<"4. Salir\n";
        std::cout<<"Ingrese una opción: ";
        std::cin>>opcion;
        switch(opcion){
            case 1:
                std::cout<<"Ingrese un número: ";
                std::cin>>dato;
                insertarLista(lista, dato);
                std::cout<<"\n";
                break;
            case 2:
                mostrarLista(lista);
                std::cout<<"\n";
                break;
            case 3:
                sumarDigitos(lista, listaCifrada);
                std::cout<<"La lista cifrada: \n";
                mostrarLista(listaCifrada);
                break;
                
            case 4:
                std::cout<<"Saliendo del programa...\n";
                break;
            default:
                std::cout<<"Opción no válida\n";
        } 
    }while(opcion != 4);
}