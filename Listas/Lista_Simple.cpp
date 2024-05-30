/*
 *UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 *Ejemplo de Recursividad directa
 *Autor: Estiven Oña
 *Fecha de creación: 29/05/2024
 *Fecha de modificación: 29/05/2024
*/

#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Prototipo de función
void insertarLista(Nodo *&, int);
void menu();
//declaramos el Nodo como global
Nodo *lista = NULL;

int main(){
    menu();
    return 0;
}

void insertarLista(Nodo *&lista, int n){
    //Creación de un nuevo nodo, reservando memoria
    Nodo *nuevo_nodo = new Nodo();
    //Asignar el valor de n al campo dato del nodo
    nuevo_nodo->dato = n;
    //designamos auxiliares, aux1 para recorrer la lista y aux2 para guardar el nodo anterior
    Nodo *aux1 = lista;
    Nodo *aux2;
    //Recorrer la lista, comprobando dos situaciones..
    //*1. Si la lista está vacia Y 2. Si el elemento a insertar es menor al primer elemento de la lista
    while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    //Al salir del while, significa que encontramos la posición donde insertar el nuevo nodo
    if(lista == aux1){
        //Si la lista está vacía, el nuevo nodo será el primero
        lista = nuevo_nodo;
    }else{
        //Si no está vacía, el nuevo nodo se enlaza al nodo anterior
        aux2->siguiente = nuevo_nodo;
    }
    //El nuevo nodo se enlaza al nodo siguiente, apuntando a NULL
    nuevo_nodo->siguiente = aux1;
    cout<<"\t Elemento "<<n<<" Insertado a la lista correctamente!\n";
}

void mostrarLista(Nodo *lista){
    //Paso uno, crear un nodo actual
    Nodo *actual = new Nodo();
    //Pasar el valor al que apunta lista, en este caso, el primero
    actual = lista;
    //Comprobar que el elemento actual no sea el último, es decir NULL
    while(actual != NULL){
        cout<<actual->dato<<" ->";
        actual = actual->siguiente;
    }
}

void menu(){
    //dato a ingresar a la lista
    int dato, opcion;
    do{
        cout<<"|-----MENÚ PRINCIPAL-----|\n";
        cout<<"1. Insertar elementos a la lista\n";
        cout<<"2. Mostrar elementos de la lista\n";
        cout<<"3. Salir\n";
        cout<<"Ingrese una opción: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"Ingrese un número: ";
                cin>>dato;
                insertarLista(lista, dato);
                cout<<"\n";
                break;
            case 2:
                mostrarLista(lista);
                cout<<"\n";
                break;
            case 3:
                break;
            default:
                cout<<"Opción no válida\n";
        } 
        
    }while(opcion != 3);
}