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
Jugador::void mover(){

}
Jugador::void aparecer(){

}
Jugador::void atacar(){

}