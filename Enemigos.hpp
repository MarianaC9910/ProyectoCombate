#ifndef Enemigos.hpp
#define Enemigos.hpp

class Enemigo{
    int vida;
    int danio;
    int posx, posy;


    Enemigo(int hp, int dmg);

    void mover();
    void atacar();
};





#endif