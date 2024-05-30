/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Ejemplo de Recursividad multiple
 * Autor: Estiven Oña
 * Fecha de creación: 29/05/2024
 * Fecha de modificación: 29/05/2024
*/

#include <iostream>
#include <ctime>
using namespace std;

/**
 * This function simulates a delivery process by a delivery person.
 * 
 * @param repartidor The name of the delivery person.
 * @param entregas The number of deliveries to be made.
 */
void delivery(string repartidor, int entregas){
    if(entregas == 0){
        cout << "Repartidor: " << repartidor << " ha terminado sus entregas" << endl;
    }else if(entregas > 10){

        cout << "Las " << entregas << " entregas están sobresaturadas, se necesita otro repartidor" << endl;
        delivery(repartidor, entregas/2);
        delivery(repartidor.append(" Reborn"), entregas/2);
    }else if(entregas > 0 || entregas <= 10){
        cout << "Repartidor: " << repartidor << " ha entregado un paquete" << endl;
        cout << "Quedan " << entregas << " por entregar" << endl;
        delivery(repartidor, entregas-1);
    }
}

int main(){
    string nombre;
    srand(time(NULL));
    int entregas = rand() % 20 + 7;
    cout<<"Ingrese un nombre: ";
    getline(cin, nombre);
    delivery(nombre, entregas);
    return 0; 
}
