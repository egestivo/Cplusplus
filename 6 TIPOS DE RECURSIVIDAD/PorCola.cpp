/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Ejemplo de Recursividad por cola
 * Autor: Estiven Oña
 * Fecha de creación: 29/05/2024
 * Fecha de modificación: 29/05/2024
*/
#include <iostream>
using namespace std;

/**
 * Calculates the power of a number using recursion.
 * 
 * @param base The base number.
 * @param exponente The exponent.
 * @return The result of the power calculation.
 */

int potencia(int base, int exponente){
    if(exponente == 0){
        return 1;
    }else if(exponente == 1){
        return base;
    }else{
        return base * potencia(base, exponente-1);
    }
}

int main(){
    int numero, pow;
    printf("Ingrese el numero base: "); 
    scanf("%d", &numero);
    printf("Ingrese el exponente: ");
    scanf("%d", &pow);
    std::cout<<"El resultado de la potencia es: "<<potencia(numero, pow)<<std::endl;
    return 0;
}
