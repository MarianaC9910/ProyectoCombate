#ifndef Balas_hpp
#define Balas_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

using namespace std;
using namespace sf;

class Bala{
  private:
    int posx,posy;
    int speed;
    bool dir;//0 para Jugador, 1 para enemigos
    bool estado;//estado==true cuando la bala no ha salido del mapa o intersectado con un personaje

    public: 

    Sprite bullet;

    Bala(float startX, float startY, bool direc);
      
    void draw(RenderWindow& window);
    void mover(RenderWindow& window, Keyboard::Key key);
    void aparecer(int x, int y);
    void setSize(float width, float height);
};

#endif
