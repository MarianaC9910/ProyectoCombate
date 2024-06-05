#ifndef Jugador_hpp
#define Jugador_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <vector>
#include "Balas.hpp"

using namespace std;
using namespace sf;
class Bala;
class Jugador{
    private:
    string nombre;
    int vida;
    int danio;

    public: 
    int posx,posy;
    Sprite persona;
    vector<Bala> disparos;
    int vista;//Hacia donde esta apuntando  Derecha:1, abajo:2, arriba:3, Izquierda:4;

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
    void atacado();
    int getVida();
    void reiniciar();
};

#endif
