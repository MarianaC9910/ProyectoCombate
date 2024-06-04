#include "Balas.hpp"

Bala::Bala(float startX, float startY, int direc){
    this->posy=startX;
    this->posx=startY;
    this->dir=direc;
    this->speed=1;
    this->estado=true;
    bullet.setPosition(posx, posy);
};
      
void Bala::draw(RenderWindow& window){
    if(this->estado==true){
        window.draw(bullet);
    }
}
void Bala::mover(RenderWindow& window){
    switch(this->dir){
        case 1:
            this->posy+=this->speed;
            break;
        case 2:
            this->posx-=this->speed;
            break;
        case 3:
            this->posy-=this->speed;
            break;
        case 4:
            this->posx+=this->speed;
            break;
        default:
        break;
    }
    bullet.setPosition(posx, posy);
}
void Bala::aparecer(int x, int y){
    posx = x;
    posy = y;
    bullet.setPosition(posx, posy);
}
void Bala::setSize(float width, float height){
    bullet.setScale(width/bullet.getLocalBounds().width, height/bullet.getLocalBounds().height);
    this->ancho=width/bullet.getLocalBounds().width;
    this->alto=height/bullet.getLocalBounds().height;
}

