#include <iostream>
#include <string>
#include <cctype>

bool validarCedula(const std::string& cedula) {
    // Verificar long
    if (cedula.length() != 10) {
        return false;
    }

    // Verificar que todos los caracteres sean dígitos
    for (char c : cedula) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

std::string ingresarCedula() {
    std::string cedula;
    bool cedulaValida = false;

    while (!cedulaValida) {
        std::cout << "Ingrese su número de cédula: ";
        std::cin >> cedula;

        if (validarCedula(cedula)) {
            cedulaValida = true;
        } else {
            std::cout << "Número de cédula inválido. Asegúrese de ingresar 10 dígitos.\n";
        }
    }

    return cedula;
}

