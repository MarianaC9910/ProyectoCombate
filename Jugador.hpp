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

    // Texture tex; 
    // Texture textura_derecha;
    // Texture textura_izquierda;

    //  Texture textura_arriba;
    //  Texture textura_arriba_d;
    //  Texture textura_arriba_i;

    //  Texture textura_abajo;
    //  Texture textura_abajo_d;
    //  Texture textura_abajo_i;

    Sprite persona;

    Jugador();
    Jugador(string nom, float startX, float startY);
    Jugador(string nom, int vid, float startX, float startY);
    Jugador(string nom,int vid, int dan, float startX, float startY);

    void draw(RenderWindow& window);
    void mover(RenderWindow& window, Keyboard::Key key);
    void aparecer(int x, int y);
    void atacar();
    void apuntar(RenderWindow &window, const Vector2i& mousePos, Texture& texDerecha, Texture& texIzquierda, Texture& texArriba, Texture& texAbajo);
    void setSize(float width, float height);

};

#endif