#include "Enemigos.hpp"
#include <vector>
//#include "Globales.hpp"
#include "Balas.hpp"
Enemigo::Enemigo()
{
    this->vida = 10;
    this->danio = 10; 
    this->posx=100;
    this->posy=100;
    mounstruo.setPosition(posx, posy);
};

Enemigo::Enemigo(float startX, float startY, int type)
{
    this->vida = 10;
    this->danio = 10; 
    this->tipo = type;
    this->time=0;
    this->vivo = true;
    posx = startX;
    posy = startY;
    mounstruo.setPosition(posx, posy);
    
}
Enemigo::Enemigo(int vid,float startX, float startY, int type)
{
    this->vida = vid;
    this->danio=10;
    this->tipo=type;
    posx = startX;
    posy = startY;
    mounstruo.setPosition(posx, posy);
    mounstruo.setPosition(posx, posy);
}
Enemigo::Enemigo(int vid, int dan, float startX, float startY, int type)
{
    this->vida = vid;
    this->danio = dan;
    this->tipo = type;
    posx = startX;
    posy = startY;
    mounstruo.setPosition(posx, posy);
}

void Enemigo::draw(RenderWindow& window){
    window.draw(mounstruo);
}


void Enemigo::mover(RenderWindow& window, Jugador player){
    
    Vector2u ventanaSize = window.getSize(); 
    
    int windowWidth = ventanaSize.x;  // obtenemos el ancho de la ventana
    int windowHeight = ventanaSize.y; // obtenemos el alto de la ventana
    if(this->tipo%2==1){
        if(this->posx<player.posx){
            this->posx+=2;
        }else if(this->posx>player.posx){
            this->posx-=2;
        }else{
            if(this->time%100==0)
                atacar();
        }
    }else{
        if(this->posy<player.posy){
            this->posy+=2;
        }else if(this->posy>player.posy){
            this->posy-=2;
        }else{
            if(this->time%100==0)
                atacar();        
        }
    }
    this->time++;
    mounstruo.setPosition(posx, posy);
}
    //revisa coordenadas del jugador y se mueve hacia ellas 
void Enemigo::aparecer(int x, int y){
    posx = x;
    posy = y;
    mounstruo.setPosition(posx, posy);
}

void Enemigo::atacar(){
    Texture bulletv;
    Texture bulleth;

    bulletv.loadFromFile("texturas/bullet_v.png");
    bulleth.loadFromFile("texturas/bullet_h.png");

    float startXB, startYB;
    Bala disparo(50, 50, this->tipo);
    switch(disparo.dir){
        case 1://la bala va hacia abajo
            disparo.bullet.setTexture(bulletv);
            startXB = this->posx+50.0f;
            startYB = this->posy+80.0f;
        break;
        case 2://izquierda
            disparo.bullet.setTexture(bulleth);
            startXB = this->posx+20.0f;
            startYB = this->posy+50.0f;
        break;
        case 3://arriba
            disparo.bullet.setTexture(bulletv);
            startXB = this->posx+45.0f;
            startYB = this->posy+5.0f;
        break;
        case 4://derecha
            disparo.bullet.setTexture(bulleth);
            startXB = this->posx+80.0f;
            startYB = this->posy+45.0f;
        break;
        default:
        break;
    }

        disparo.setSize(10,10);
        disparo.aparecer(startXB,startYB);
        this->disparos.push_back(disparo);
}

void Enemigo::setSize(float width, float height){
    mounstruo.setScale(width/mounstruo.getLocalBounds().width, height/mounstruo.getLocalBounds().height);
}


void Enemigo::setSize(float width, float height){
    mounstruo.setScale(width/mounstruo.getLocalBounds().width, height/mounstruo.getLocalBounds().height);
}
