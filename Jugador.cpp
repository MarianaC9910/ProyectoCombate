#include "Jugador.hpp"
#include <conio.h>
 

Jugador::Jugador(Texture t){

    this->tex=t;

    if(!tex.loadFromFile("texturas/criculov.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    tex.setRepeated(true);

    Sprite jugador; 

    jugador.setTexture(tex);
};

Jugador::Jugador(string nom, Texture t){
    this->nombre=nom;
}
Jugador::Jugador(string nom,Texture t,  int vid){
    this->nombre=nom;
    this->vida=vid;
}
Jugador::Jugador(string nom, Texture t, int vid, int dan){
    this->nombre=nom;
    this->vida=vid;
    this->danio=dan;
}
void Jugador:: mover(){
    switch(_getch()) 
    {
        case 'w':
            this->posy--;
            break;
        case 'a':
            this->posx--;
            break;
        case 'd':
            this->posx++;
            break;
        case 's':
            this->posy++;
            break;
        case 'e':
            jugador.atacar();  
    }
}
void Jugador:: aparecer(){

}
void Jugador:: atacar(){

}