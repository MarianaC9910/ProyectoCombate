#include "Jugador.hpp"
Jugador::Jugador(){
}
Jugador::Jugador(string nom){
    this->nombre=nom;
}
Jugador::Jugador(string nom, int vid){
    this->nombre=nom;
    this->vida=vid;
}
Jugador::Jugador(string nom, int vid, int dan){
    this->nombre=nom;
    this->vida=vid;
    this->danio=dan;
}
void Jugador::mover(){
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
void Jugador::aparecer(){

}
void Jugador::atacar(){

}