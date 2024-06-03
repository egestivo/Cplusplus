/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Problema:
 * USANDO LISTAS DOBLEMENTE ENLAZADAS
 * INGRESAR DOS NOMBRES, APELLIDOS Y HACER UN MÉTODO QUE:
 * Tome el primer caracter de cada nombre, y con un apellido haga un correo agregando @espe.edu.ec
 * Por ejemplo: Primer nombre, segundo nombre: Juan Carlos
 * Apellido: Pérez Ortiz
 * Correo generado: jcperez@espe.edu.ec
 * En caso de que se repita el correo, se debe agregar un número antes de @espe.edu.ec
 * Por ejemplo: jcperez1@espe.edu.ec, y en caso de existir otro jcperez1, se debe incrementar el número.
 * Guardar en un archivo plano .txt
 * Autores: Estiven Oña - David Ramos - Carlos Carrasco
 * NRC: 16426
 * Fecha de creación: 03/06/2024;
 * Fecha de modificación: 03/06/2024;
*/
//listas doblemente enlazadas
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct Nodo{
    string nombre;
    string apellido;
    Nodo *siguiente;
    Nodo *anterior;
};

//prototipos de funciones
void insertarLista(Nodo *&, Nodo *&, string, string);
void mostrarLista(Nodo *, Nodo *, Nodo*);
void generarCorreo(Nodo *, Nodo *&);
void guardarArchivo(Nodo *, Nodo *);
void menu();

//variables globales, en este caso las listas correspondientes
Nodo *nombreApellido = NULL;
Nodo *correos = NULL;

//Función insertar lista
void insertarLista(Nodo *&nombres, string nombre, string apellido){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombre = nombre;
    nuevo_nodo->apellido = apellido;
    Nodo *aux1 = nombres;
    if(nombres == NULL){
        nombres = nuevo_nodo;
        nombres->siguiente = NULL;
        nombres->anterior = NULL;
    }else{
        while(aux1->siguiente != NULL){
            aux1 = aux1->siguiente;
        }

        aux1->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = aux1;
    }
    fflush(stdin);
}

//Función mostrar lista
void mostrarLista(Nodo *correos,Nodo *nombres, Nodo *ultimo){
    Nodo *actual = correos;
    if(correos != NULL){
        while(actual != NULL){
            cout << "Nombres: " << nombres->nombre << " Apellidos: " << nombres->apellido << endl;
            cout << "Correo: " << actual->nombre << endl;
            nombres = nombres->siguiente;
            actual = actual->siguiente;
        }
    }else{
        cout << "La lista esta vacia" << endl;
    }
}

//Funcion generar correo, de manera que cumpla con los requerimientos
//Si el correo antes de @espe.edu.ec ya existe, se le agrega un número
void generarCorreo(Nodo *nombres, Nodo *&correos) {
    Nodo *actual = nombres;
    
    while (actual != NULL) {
        string correo;
        correo = tolower(actual->nombre[0]);
        
        if (actual->nombre.find(' ') != string::npos) {
            correo += tolower(actual->nombre[actual->nombre.find(' ') + 1]);
        }
        
        correo += tolower(actual->apellido[0]);
        correo += actual->apellido.substr(1, actual->apellido.find(' ')-1);
        string baseCorreo = correo + "@espe.edu.ec";
        string correoFinal = baseCorreo;
        int contador = 1;
        
        //Comprobar que el correo no exista
        Nodo *aux = correos;
        bool existe = false;
        
        while (aux != NULL) {
            if (aux->nombre == correoFinal) {
                existe = true;
                correoFinal = correo + to_string(contador) + "@espe.edu.ec";
                contador++;
                aux = correos;
            } else {
                aux = aux->siguiente;
            }
        }
        
        insertarLista(correos, correoFinal, "");
        
        actual = actual->siguiente;
    }
}
//Función guardar archivo
void guardarArchivo(Nodo *nombres, Nodo *correos){
    Nodo *actual = nombres;
    Nodo *aux = correos;
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo: ";
    cin.ignore();
    getline(cin, nombreArchivo);
    nombreArchivo += ".txt";
    FILE *archivo;
    archivo = fopen(nombreArchivo.c_str(), "w");
    if(archivo == NULL){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }else{
        while(actual != NULL){
            fprintf(archivo, "%s %s\n", actual->nombre.c_str(), actual->apellido.c_str());
            actual = actual->siguiente;
            fprintf(archivo, "%s\n", aux->nombre.c_str());
            aux = aux->siguiente;
        }
        cout << "Archivo guardado correctamente" << endl;
    }
    fclose(archivo);
}

//Función para mostrar el menú
void menu(){
    string nombre, apellido;
    int opcion;
    do{
        cout << "\n1. Ingresar nombres y apellidos" << endl;
        cout << "2. Generar correos" << endl;
        cout << "3. Mostrar correos" << endl;
        cout << "4. Guardar en archivo" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                cout << "Ingrese nombres: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese apellidos: ";
                getline(cin, apellido);
                insertarLista(nombreApellido, nombre, apellido);
                break;
            case 2:
                generarCorreo(nombreApellido, correos);
                break;
            case 3:
                mostrarLista(correos,nombreApellido, NULL);
                break;
            case 4:
                guardarArchivo(nombreApellido, correos);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(opcion != 5);
    fflush(stdin);
}
