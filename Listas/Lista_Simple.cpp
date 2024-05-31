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
void buscarLista(Nodo *, int);
void eliminarTodo(Nodo *&, int&);
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
    std::cout<<"\t Elemento "<<n<<" Insertado a la lista correctamente!\n";
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
    std::cout<<"-------------------------------------\n";
}

void buscarLista(Nodo *Lista, int n){
    Nodo *actual = new Nodo();
    actual = lista;
    bool bandera = false;
    while((actual != NULL)&&(actual -> dato <= n)){
        if(actual -> dato == n){
            bandera = true;
        }
        actual = actual -> siguiente;
    }
    if(bandera){
        std::cout<<"Elemento: " << n <<" ha sido encontrado en la lista!"<<endl;;
    }else{
        std::cout << "Elemento: " << n << " no existe en la lista!"<<endl;;
    }
}


void eliminarTodo(Nodo *&lista, int &n){
    Nodo *aux = lista;
    n = aux->dato;
    lista = aux->siguiente;
    delete aux;
}

void eliminarElemento(Nodo *&lista, int n){
    if(lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;
        //* Entramos al bucle si hay un elemento y si es distinto del elemento a eliminar
        while((aux_borrar != NULL)&&(aux_borrar->dato != n)){
            //* aux borrar lo asignas a anterior que sería el primer lugar
            anterior = aux_borrar;
            //*aux borrar se mueve al siguiente puntero del sig. nodo
            aux_borrar = aux_borrar->siguiente;
        }
        //* si el puntero al final es null entonces no existe
        if(aux_borrar == NULL){
            std::cout << "No existe tal elemento!" << endl;
        }
        //* Si se halla el elemento a eliminar
            else if(anterior == NULL){
            lista = lista -> siguiente;
            delete aux_borrar;
        }
        //* Si el elemento a eliminar está en la lista pero no es el primer nodo
        else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}

void menu(){
    //dato a ingresar a la lista
    int dato, opcion;
    do{
        std::cout<<"|-----MENÚ PRINCIPAL-----|\n";
        std::cout<<"1. Insertar elementos a la lista\n";
        std::cout<<"2. Mostrar elementos de la lista\n";
        std::cout<<"3. Buscar un elemento de la lista\n";
        std::cout<<"4. Eliminar un elemento de la lista\n";
        std::cout<<"5. Eliminar todos los elementos de la lista\n";
        std::cout<<"6. Salir\n";
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
                std::cout<<"Ingrese un número a buscar: ";
                std::cin>>dato;
                buscarLista(lista, dato);
                std::cout<<"\n";
                break;
            case 4:
                std::cout<<"Ingrese el número a eliminar: ";
                std::cin>>dato;
                eliminarElemento(lista, dato);
                std::cout<<"\n";
                break;
            case 5:
                while(lista != NULL){
                    eliminarTodo(lista, dato);
                    std::cout<<"\n";
                    std::cout<<dato<<" ha sido eliminado de la lista!\n";
                }
                std::cout<<"Todos los elementos han sido eliminados de la lista!\n";
                break;
            case 6:
                std::cout<<"Saliendo del programa...\n";
                break;
            default:
                std::cout<<"Opción no válida\n";
        } 
    }while(opcion != 6);
}