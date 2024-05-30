/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Ejemplo de Recursividad simple
 * Autor: Estiven Oña
 * Fecha de creación: 29/05/2024
 * Fecha de modificación: 29/05/2024
*/
#include <iostream>

/**
 * Recursively charges the battery until it reaches a certain threshold.
 * 
 * @param carga The current battery charge level.
 */

void baterry(double carga){
    if(carga > 50 || carga == 100){
        std::cout<<"Bateria cargada al máximo"<<std::endl;
    }
    else{
        std::cout<<"Cargando bateria desde "<<carga<<"%"<<std::endl;
        std::cout<<". . . . . .\n";
        std::cout<<". . . . . .\n";
        baterry(carga+(double)25);
    }
}

int main() {
    double restante;
    do{

        std::cout<<"Ingrese la carga de la bateria: ";
        std::cin>>restante;
        if(restante < 0 || restante> 100){
            std::cout<<"Ingrese un valor entre 0 y 100!"<<std::endl;
        }
    }while(restante < 0 || restante > 100);
    baterry(restante);
}