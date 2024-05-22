#include "Enemigos.hpp"

Enemigo::Enemigo(int hp, int dmg){
    this->vida=hp;
    this->danio=dmg;
}

void Enemigo::atacar(){

}

void Enemigo::mover(){
    if(this->posy!=jugador.posy){
        if(this->posy<jugador.posx){
            this->posy++;
        }else if(this->posy>jugador.posx){
            this->posy--;
        }
    }
}