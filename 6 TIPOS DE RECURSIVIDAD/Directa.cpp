/*
 *UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 *Ejemplo de Recursividad directa
 *Autor: Estiven Oña
 *Fecha de creación: 29/05/2024
 *Fecha de modificación: 29/05/2024
*/

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

/**
 * @brief A class for checking if a given array is a palindrome.
 * 
 * This class provides a method to check if a given array is a palindrome using recursion.
 * 
 * @tparam T The type of elements in the array.
 */

template <class T>
class palíndromo{
    public:
        /**
         * @brief Check if the given array is a palindrome.
         * 
         * This method checks if the given array is a palindrome using recursion.
         * 
         * @param palabra The array to be checked.
         * @param inicio The starting index of the array.
         * @param fin The ending index of the array.
         * @return true if the array is a palindrome, false otherwise.
         */
        bool palindromo(T* palabra, int inicio, int fin) {
            if (inicio >= fin) {
                return true;
            }
            
            if (palabra[inicio] != palabra[fin]) {
                return false;
            }
            
            return palindromo(palabra, inicio + 1, fin - 1);
        }
};

int main(){
    palíndromo<char> p;
    char *palabra = new char[20];
    cout<<"Ingrese la palabra: ";
    cin.getline(palabra, 20);
    int inicio = 0;
    int fin = strlen(palabra) - 1;
    
    if (p.palindromo(palabra, inicio, fin)) {
        cout << "Es palíndromo" << endl;
    } else {
        cout << "No es palíndromo" << endl;
    }
    
    return 0;
}