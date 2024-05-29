#ifndef Enemigos_hpp
#define Enemigos_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
using namespace std;
using namespace sf;
class Enemigo{
private:
    int vida;
    int danio;
    int posx,posy;
public: 
     Texture mounstruo; 

    Sprite enemigo;

    Enemigo();
    Enemigo(int vid);
    Enemigo(int vid, int dan);

     void cargarTexturas();
    void draw(RenderWindow& window);
    void mover();//revisa coordenadas del jugador y se mueve hacia ellas 
    void aparecer(int x, int y);
    void atacar();
    void apuntar(RenderWindow& window);
    void setSize(float width, float height);
};





#endif