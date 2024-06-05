#ifndef Enemigos_hpp
#define Enemigos_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <vector>
//#include "Globales.hpp"
#include "Jugador.hpp"
#include "Balas.hpp"

using namespace std;
using namespace sf;


class Bala;
class Jugador;
class Enemigo{
private:
    int vida;
    int danio;
    int time;
    int speed;
public:
    int posx,posy;
    bool vivo; 
    int tipo;//Segun el lugar donde aparezcan arriba:1, derecha:2, abajo:3, izquierda:4
    vector<Bala>disparos;
    Sprite mounstruo;

    Enemigo();
    Enemigo(float startX, float startY, int type);
    Enemigo(int vid, float startX, float startY, int type);
    Enemigo(int vid, int dan, float startX, float startY, int type);

    void draw(RenderWindow& window);
    void mover(RenderWindow& window, Jugador player);//revisa coordenadas del jugador y se mueve hacia ellas 
    void aparecer(int x, int y);
    void atacar();
    void setSize(float width, float height);
};

#endif
