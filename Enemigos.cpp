#include "Enemigos.hpp"
#include <vector>
Enemigo::Enemigo()
{
    this->vida = 20;
    this->danio = 10; 
    this->posx=100;
    this->posy=100;
    mounstruo.setPosition(posx, posy);
};

Enemigo::Enemigo(float startX, float startY)
{
    this->vida = 20;
    this->danio = 10; 
    posx = startX;
    posy = startY;
    mounstruo.setPosition(posx, posy);
    
}
Enemigo::Enemigo(int vid,float startX, float startY)
{
    this->vida = vid;
    this->danio=10;
    posx = startX;
    posy = startY;
    mounstruo.setPosition(posx, posy);
    mounstruo.setPosition(posx, posy);
}
Enemigo::Enemigo(int vid, int dan, float startX, float startY)
{
    this->vida = vid;
    this->danio = dan;
    posx = startX;
    posy = startY;
    mounstruo.setPosition(posx, posy);
}

void Enemigo::draw(RenderWindow& window){
    window.draw(mounstruo);
}


void Enemigo::mover(RenderWindow& window, int posActY){
    Vector2u ventanaSize = window.getSize(); 
    int speed=rand()%12;
    
    int windowWidth = ventanaSize.x;  // obtenemos el ancho de la ventana
    int windowHeight = ventanaSize.y; // obtenemos el alto de la ventana

    if(posActY<this->posy){
        if(this->posy-speed<=0&&this->posy>1&&this->posy-speed<posActY){
            this->posy--;
        }else{
            this->posy-=speed;
        }
    }else if(posActY>this->posy){
        if(this->posy+speed>=800&&this->posy<799&&this->posy+speed>posActY){
            this->posy++;
        }else{
            this->posy-=speed;
        }
    }else{
        atacar();
    }

    mounstruo.setPosition(posx, posy);
}
    //revisa coordenadas del jugador y se mueve hacia ellas 
void Enemigo::aparecer(int x, int y){
    posx = x;
    posy = y;
    mounstruo.setPosition(posx, posy);
}

void Enemigo::atacar(){
   //disparos.push_back(posx);     
}
void Enemigo::setSize(float width, float height){
    mounstruo.setScale(width/mounstruo.getLocalBounds().width, height/mounstruo.getLocalBounds().height);
}
