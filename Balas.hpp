#ifndef Balas_hpp
#define Balas_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

using namespace std;
using namespace sf;

Class Bala{
  private:
    int posx,posy;
    

    public: 

    Sprite bullet;

    Bala();
    Bala(float startX, float startY);
      
    void draw(RenderWindow& window);
    void mover(RenderWindow& window, Keyboard::Key key);
    void aparecer(int x, int y);
    void setSize(float width, float height);
}
