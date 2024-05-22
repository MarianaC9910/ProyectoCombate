#ifndef Jugador_hpp
#define Jugador_hpp
#include <iostream>
#include <string>

using namespace std;
class Jugador{
    string nombre;
    int vida;
    int danio;
    int posx,posy;
    Jugador();
    Jugador(string nom);
    Jugador(string nom, int vid);
    Jugador(string nom, int vid, int dan);
    void mover();
    void aparecer();
    void atacar();
};

#endif