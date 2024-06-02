#include "Balas.hpp"
using namespace std;
Bala::Bala(float startX, float startY, bool direc){
    this->posy=startX;
    this->posx=startY;
    this->dir=direc;
    this->speed=rand()%10+20;
    bullet.setPosition(posx, posy);
};
      
void Bala::draw(RenderWindow& window){
    if(this->estado==true){
        window.draw(bullet);
    }
}
void Bala::mover(RenderWindow& window, Keyboard::Key key){
    if(this->dir==0){
        this->posx+=speed;
    }else{
        this->posx-=speed;
    }
}
void Bala::aparecer(int x, int y){
    posx = x;
    posy = y;
    bullet.setPosition(posx, posy);
}
void Bala::setSize(float width, float height){
    bullet.setScale(width/bullet.getLocalBounds().width, height/bullet.getLocalBounds().height);
}

