#ifndef Jugador_hpp
#define Jugador_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;
class Jugador{
    private:
    string nombre;
    int vida;
    int danio;
    int posx,posy;
    Sprite persona;
    static Texture tex; 

    public: 
    Jugador();
    Jugador(string nom);
    Jugador(string nom, int vid);
    Jugador(string nom,int vid, int dan);

    static void cargarTextura(const string& archivo);
    void draw(RenderWindow& window);
    void mover();
    void aparecer(int x, int y);
    void atacar();

};

#endif