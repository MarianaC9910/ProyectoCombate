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

Enemigo::Enemigo(float startX, float startY, int type)
{
    this->vida = 20;
    this->danio = 10; 
    this->tipo = type;
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
    int speed=10+rand()%10;
    
    int windowWidth = ventanaSize.x;  // obtenemos el ancho de la ventana
    int windowHeight = ventanaSize.y; // obtenemos el alto de la ventana
    if(this->tipo%2==1){
        if(this->posx<player.posx){
            if(this->posx+speed>=windowWidth||this->posx<windowWidth-1||this->posx+speed>player.posx){
                this->posx++;
            }else{
                this->posx+=speed;
            }
        }else if(this->posx>player.posx){
            if(this->posx-speed<=0||this->posx<2&&this->posx-speed<player.posx){
                this->posx--;
            }else{
                this->posx-=speed;
            }
        }else{
            atacar();
        }
    }else{
        if(this->posy<player.posy){
            if(this->posy+speed>=windowHeight||this->posy<windowHeight-1||this->posy+speed>player.posy){
                this->posy++;
            }else{
                this->posy+=speed;
            }
        }else if(this->posy>player.posy){
            if(this->posy-speed<=0||this->posy<2&&this->posy-speed<player.posy){
                this->posy--;
            }else{
                this->posy-=speed;
            }
        }else{
            atacar();
        }
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
