#include <iostream>
#include <ctime>

using namespace std;

// Función para trasponer una matriz recursivamente
void trasponerMatriz(int** matriz, int** resultado, int filas, int columnas, int i, int j) {
    // Caso base: cuando hemos recorrido toda la matriz
    if (i == filas) {
        return;
    }

    // Copiar el elemento actual en la posición traslapada
    resultado[j][i] = matriz[i][j];

    // Mover al siguiente elemento de la matriz original
    if (j == columnas - 1) {
        // Si hemos llegado al final de la fila, avanzar a la siguiente fila y reiniciar j
        trasponerMatriz(matriz, resultado, filas, columnas, i + 1, 0);
    } else {
        // Si no, solo incrementar j
        trasponerMatriz(matriz, resultado, filas, columnas, i, j + 1);
    }
}

int main() {
    int filas, columnas;
    srand(time(NULL));
    // Solicitar al usuario el tamaño de la matriz
    cout << "Ingrese el número de filas de la matriz: ";
    cin >> filas;
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> columnas;

    // Crear la matriz y reservar memoria
    int** matriz = new int*[filas];
    int** matrizTranspuesta = new int*[columnas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
        matrizTranspuesta[i] = new int[filas];
    }

    // Ingresar elementos de la matriz
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 10; // Generar números aleatorios entre 0 y 9
        }
    }
    // Mostrar matriz original
    cout << "La matriz original es:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Trasponer la matriz
    trasponerMatriz(matriz, matrizTranspuesta, filas, columnas, 0, 0);

    // Imprimir la matriz transpuesta
    cout << "La matriz transpuesta es:" << endl;
    for (int i = 0; i < columnas; ++i) {
        for (int j = 0; j < filas; ++j) {
            cout << matrizTranspuesta[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
        delete[] matrizTranspuesta[i];
    }
    delete[] matriz;
    delete[] matrizTranspuesta;

    return 0;
}
