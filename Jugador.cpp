#include "Jugador.hpp"
#include <conio.h>

Texture Jugador::tex; //se inicia la textura para el jugador, q siempre es la misma

Jugador::Jugador(){
    persona.setTexture(tex);
};

Jugador::Jugador(string nom){
    this->nombre=nom;
    persona.setTexture(tex);
}
Jugador::Jugador(string nom, int vid){
    this->nombre=nom;
    this->vida=vid;
    persona.setTexture(tex);
}
Jugador::Jugador(string nom, int vid, int dan){
    this->nombre=nom;
    this->vida=vid;
    this->danio=dan;
    persona.setTexture(tex);
}

void Jugador::draw(RenderWindow& window) {
    window.draw(persona);
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
            atacar();  
    }
    persona.setPosition(posx, posy); 
}


void Jugador::cargarTextura(const string& archivo) { //se carga la textura por default
    if (!tex.loadFromFile(archivo)) {
        cout << "Error al cargar la textura por defecto" << endl;
    }
}

void Jugador:: aparecer(int x, int y){
    persona.setPosition(x, y);
}
void Jugador:: atacar(){

}