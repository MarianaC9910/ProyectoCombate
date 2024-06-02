#ifndef Enemigos_hpp
#define Enemigos_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
using namespace sf;
class Bala;
class Jugador;
class Enemigo{
private:
    int vida;
    int danio;
    int posx,posy;
    //vector<Bala>disparos;
public: 
    Sprite mounstruo;

    Enemigo();
    Enemigo(float startX, float startY);
    Enemigo(int vid, float startX, float startY);
    Enemigo(int vid, int dan, float startX, float startY);

    void draw(RenderWindow& window);
    void mover(RenderWindow& window, int posActY);//revisa coordenadas del jugador y se mueve hacia ellas 
    void aparecer(int x, int y);
    void atacar();
    void setSize(float width, float height);
};

#endif
