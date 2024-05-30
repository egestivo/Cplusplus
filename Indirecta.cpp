/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Ejemplo de Recursividad simple
 * Autor: Estiven Oña
 * Fecha de creación: 29/05/2024
 * Fecha de modificación: 29/05/2024
*/
#include <iostream>
using namespace std;

enum class armas{a=20, b=40, c=60};
bool luchar(int arma, int danio, int &vidaJefe, int &vida);
void upgradeWeapon(int &arma, int &danio, int &vida);

template <class W>
bool luchar(W arma, int danio, int &vidaJefe, int &vida){
    do{
        vidaJefe -= danio;
        vida -= 10;
        if(vidaJefe > 0 && vida <= 0){
            cout<<"Has sido derrotado!"<<endl;
            return true;
            break;
        }else{
            return false;
            break;
        }
    }while(vidaJefe > 0 && vida > 0);
}

template <class W, class X, class H>
void derrotarJefe(W arma, X danio, H vida){
    int vidaJefe = 100;
    bool win = luchar(arma, danio, vidaJefe, vida);
    if(win==true){
        cout<<"Jefe derrotado!"<<endl;
        return;
    }else{
        cout<<"Mejora tus armas para derrotarlo! ";
        upgradeWeapon(arma, danio, vida);
    }
}


template <class T>
    void upgradeWeapon(T &arma, int &danio, int &vida){
        vida = 50;
        arma = armas::c;
        danio *= 2.5;
        cout<<"Arma mejorada!"<<endl;
        derrotarJefe(arma, danio, vida);
    }

int main(){
    int vida = 100;
    char arma = static_cast<char>(armas::a);
    int danio = static_cast<int>(arma); 
    derrotarJefe(arma, danio, vida);
    return 0;
}
