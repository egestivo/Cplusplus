/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Ejemplo de Recursividad por cabeza
 * Autor: Estiven Oña
 * Fecha de creación: 29/05/2024
 * Fecha de modificación: 29/05/2024
*/

#include <iostream>
using namespace std;

/**
 * Calculates the sum of numbers from 1 to n using recursion.
 * @param n The number up to which the sum is calculated.
 * @return The sum of numbers from 1 to n.
 */

int suma(int n){
    if(n == 0){
        return 0;
    }else{
        return n + suma(n-1);
    }
}
int main(){
    int n;
    cout<<"Ingrese un numero: ";
    cin>>n;
    cout<<"La suma de los numeros hasta "<<n<<" es: "<<suma(n)<<endl;
    return 0;
}