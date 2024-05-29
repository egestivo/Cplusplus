#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 3

using namespace std;

// Función para multiplicar dos matrices
void multiplicarMatrices(int** A, int** B, int** C, int n) {
    // Inicializar la matriz C con ceros
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = 0;

    // Multiplicar matrices
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
}

// Función recursiva para elevar una matriz a una potencia
void potenciaMatriz(int** A, int** resultado, int n, int exponente) {
    if (exponente == 1) {
        // Copiar la matriz A a resultado
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                resultado[i][j] = A[i][j];
        return;
    }

    // Matriz temporal para almacenar el resultado intermedio
    int** temp = new int*[n];
    for (int i = 0; i < n; ++i)
        temp[i] = new int[n];

    if (exponente % 2 == 0) {
        // Exponente par
        potenciaMatriz(A, temp, n, exponente / 2);
        multiplicarMatrices(temp, temp, resultado, n);
    } else {
        // Exponente impar
        potenciaMatriz(A, temp, n, exponente - 1);
        multiplicarMatrices(A, temp, resultado, n);
    }

    // Liberar memoria temporal
    for (int i = 0; i < n; ++i)
        delete[] temp[i];
    delete[] temp;
}

int main() {
    srand(time(0));

    // Crear una matriz cuadrada de 3x3 y llenarla con números aleatorios
    int** matriz = new int*[MAX];
    int** resultado = new int*[MAX];
    for (int i = 0; i < MAX; ++i) {
        matriz[i] = new int[MAX];
        resultado[i] = new int[MAX];
    }

    cout << "Matriz generada aleatoriamente:" << endl;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            matriz[i][j] = rand() % 5; // Generar números aleatorios entre 0 y 5
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Solicitar al usuario el exponente
    int exponente;
    cout << "Ingrese el exponente: ";
    cin >> exponente;

    // Calcular la potencia de la matriz
    potenciaMatriz(matriz, resultado, MAX, exponente);

    // Imprimir el resultado
    cout << "La matriz elevada a la potencia " << exponente << " es:" << endl;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j)
            cout << resultado[i][j] << " ";
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < MAX; ++i) {
        delete[] matriz[i];
        delete[] resultado[i];
    }
    delete[] matriz;
    delete[] resultado;

    return 0;
}
