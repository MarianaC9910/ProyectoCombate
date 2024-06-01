#include "Enemigos.hpp"
// #include "rlutil.h"

Enemigo::Enemigo(){
    this->vida = rand()%20+71;
    this->danio = rand()%10+51; 
    this->posx=700;
    this->posy=rand()%801;
    enemigo.setPosition(posx, posy);
}
//vida, danio y posicion  aleatorios
Enemigo::Enemigo(int vid){
        this->vida = vid;
        this->danio = 10; 
        this->posx = 700;
        this->posy = rand()%801;
        enemigo.setPosition(posx, posy);
        // enemigo.setTexture(mounstruo);
}
Enemigo::Enemigo(int vid, int dan){
        this->vida = vid;
        this->danio = dan; 
        this->posx = 700;
        this->posy = rand()%801;
        enemigo.setPosition(posx, posy);
        // enemigo.setTexture(mounstruo);
}
void Enemigo::draw(RenderWindow& window){
        window.draw(enemigo);
}
void Enemigo::mover(int posActY){
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

    enemigo.setPosition(posx, posy);
}
    //revisa coordenadas del jugador y se mueve hacia ellas 
    void Enemigo::aparecer(int x, int y){
        posx = x;
        posy = y;
        enemigo.setPosition(posx, posy);
    }
    void Enemigo::atacar(){

    }
    void Enemigo::setSize(float width, float height){
        enemigo.setScale(width/enemigo.getLocalBounds().width, height/enemigo.getLocalBounds().height);
    }
