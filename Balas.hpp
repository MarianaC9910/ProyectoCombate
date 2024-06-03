#ifndef Balas_hpp
#define Balas_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
//#include "Globales.hpp"
#include "Enemigos.hpp"

using namespace std;
using namespace sf;



class Bala{
  private:
    int speed;
    bool estado;//estado==true cuando la bala no ha salido del mapa o intersectado con un personaje

    public: 
    int posx,posy;
    int dir;//1: abajo, 2:izquierda, 3:arriba, 4:derecha

    Sprite bullet;

    Bala(float startX, float startY, int direc);
      
    void draw(RenderWindow& window);
    void mover(RenderWindow& window);
    void aparecer(int x, int y);
    void setSize(float width, float height);
};

#endif
