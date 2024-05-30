/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Ejemplo de Recursividad indirecta
 * Autor: Estiven Oña
 * Fecha de creación: 29/05/2024
 * Fecha de modificación: 29/05/2024
*/
#include <iostream>
#include <ctime>
using namespace std;

enum class armas { a = 20, b = 40, c = 60 };
 /*
 * @brief Function to simulate a battle between a player and a boss.
 * 
 * @tparam W The type of weapon used by the player.
 * @param arma The weapon used by the player.
 * @param danio The damage inflicted by the player's weapon.
 * @param vidaJefe The boss's remaining health.
 * @param vida The player's remaining health.
 * @return True if the boss is defeated, false otherwise.
 */

template <class W>
bool luchar(W arma, int danio, int &vidaJefe, int &vida) {
    while (vidaJefe > 0 && vida > 0) {
        srand(time(NULL));
        vidaJefe -= danio;
        vida -= rand() % 25+20;
        cout << "Ataque! Vida del jefe: " << vidaJefe << ", tu vida: " << vida << endl;
        if (vidaJefe <= 0) {
            cout << "Jefe derrotado!" << endl;
            return true;
        }
        if (vida <= 0) {
            cout << "Has sido derrotado!" << endl;
            return false;
        }
    }
    return false;
}

template <class W, class X, class H>
void derrotarJefe(W arma, X &danio, H &vida) {
    int vidaJefe = 100;
    bool win = luchar(arma, danio, vidaJefe, vida);
    if (!win) {
        cout << "Mejora tus armas para derrotarlo!" << endl;
        upgradeWeapon(arma, danio, vida);
    }
}

template <class T>
void upgradeWeapon(T &arma, int &danio, int &vida) {
    vida = 100;
    arma = armas::c;
    danio = static_cast<int>(arma);
    cout << "Arma mejorada! Nuevo daño: " << danio << endl;
    derrotarJefe(arma, danio, vida);
}

int main() {
    int vida = 100;
    armas arma = armas::a;
    int danio = static_cast<int>(arma);
    derrotarJefe(arma, danio, vida);
    return 0;
}
