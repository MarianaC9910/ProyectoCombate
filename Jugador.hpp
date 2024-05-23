#ifndef Jugador_hpp
#define Jugador_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;
class Jugador{
    public: 
    string nombre;
    int vida;
    int danio;
    int posx,posy;
    Texture tex; 

    Jugador(Texture t);
    Jugador(string nom, Texture t);
    Jugador(string nom, Texture t, int vid);
    Jugador(string nom, Texture t, int vid, int dan);
    void mover();
    void aparecer();
    void atacar();
};

#endif