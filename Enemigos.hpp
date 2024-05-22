#ifndef Enemigos_hpp
#define Enemigos_hpp
#include <iostream>
#include <string>

using namespace std;

class Enemigo{
    int vida;
    int danio;
    int posx, posy;


    Enemigo(int hp, int dmg);

    void mover();
    void atacar();
};





#endif