#ifndef Jugador_hpp
#define Jugador_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

using namespace std;
using namespace sf;
class Jugador{
    private:
    string nombre;
    int vida;
    int danio;
    int posx,posy;

    public: 

    static Texture tex; 
    static Texture textura_derecha;
    static Texture textura_izquierda;

    static Texture textura_arriba;
    static Texture textura_arriba_d;
    static Texture textura_arriba_i;

    static Texture textura_abajo;
    static Texture textura_abajo_d;
    static Texture textura_abajo_i;

    Sprite persona;

    Jugador();
    Jugador(string nom);
    Jugador(string nom, int vid);
    Jugador(string nom,int vid, int dan);

    static void cargarTexturas();
    void draw(RenderWindow& window);
    void mover();
    void aparecer(int x, int y);
    void atacar();
    void apuntar(RenderWindow& window);

};

#endif