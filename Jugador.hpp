#ifndef Jugador_hpp
#define Jugador_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
using namespace sf;

class Bala;

class Jugador{
    private:
    string nombre;
    int vida;
    int danio;
    int posx,posy;
    vector<Bala>disparos

    public: 

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
