#include "Jugador.hpp"

Jugador::Jugador()
{
    this->nombre = "nameless";
    this->vida = 100;
    this->danio = 10; 
    this->posx=100;
    this->posy=100;
    persona.setPosition(posx, posy);
};

Jugador::Jugador(string nom, float startX, float startY)
{

    this->nombre = nom;
    this->vida = 100;
    this->danio = 10; 
    posx = startX;
    posy = startY;
    persona.setPosition(posx, posy);
    
}
Jugador::Jugador(string nom, int vid,float startX, float startY)
{
    this->nombre = nom;
    this->vida = vid;
    this->danio=10;
    posx = startX;
    posy = startY;
    persona.setPosition(posx, posy);
    persona.setPosition(posx, posy);
}
Jugador::Jugador(string nom, int vid, int dan, float startX, float startY)
{
    this->nombre = nom;
    this->vida = vid;
    this->danio = dan;
    posx = startX;
    posy = startY;
    persona.setPosition(posx, posy);
}

void Jugador::draw(RenderWindow &window)
{
    window.draw(persona);
}

void Jugador::mover(RenderWindow &window, Keyboard::Key key)
{

    // la diferencia entre Vector2u y 2f es que el 2f usa valores float que pueden ser negativos y el 2u solo usa enteros sin signos negativos

    Vector2u ventanaSize = window.getSize(); // obtenemos las medidas de la ventana que se va a mostrar

    int speed=5;

    int windowWidth = ventanaSize.x;  // obtenemos el ancho de la ventana
    int windowHeight = ventanaSize.y; // obtenemos el alto de la ventana

    switch (key)
    {
    case Keyboard::W:
        if (posy > 0)
            posy-=speed;
        break;
    case Keyboard::A:
        if (posx > 0)
            posx-=speed;
        break;
    case Keyboard::D:
        if (posx < windowWidth - persona.getGlobalBounds().width)
            posx+=speed;
        break;
    case Keyboard::S:
        if (posy < windowHeight - persona.getGlobalBounds().height)
            posy+=speed;
        break;
    case Keyboard::E:
        atacar();
    }

    persona.setPosition(posx, posy);
}

void Jugador::aparecer(int x, int y)
{
    posx = x;
    posy = y;
    persona.setPosition(posx, posy);
}
void Jugador::atacar()
{
}

void Jugador::apuntar(RenderWindow &window, const Vector2i& mousePos, Texture& texDerecha, Texture& texIzquierda, Texture& texArriba, Texture& texAbajo){
    
    //obtenemos la posicion del jugador
    Vector2f playerPos = persona.getPosition();
    FloatRect bounds = persona.getGlobalBounds(); //limites del sprite del jugador

    //obtenemos el centro del sprite
    float centerX = playerPos.x + bounds.width / 2;
    float centerY = playerPos.y + bounds.height / 2;

    float dx = mousePos.x - centerX;    //diferencia entre la pos del mouse y el centro del sprite
    float dy = mousePos.y - centerY;

    if (abs(dx) > abs(dy)) { //mouse esta mas desplazado en la direccion horizontal
        if (dx > 0) { 
            persona.setTexture(texDerecha); // Derecha
        } else {
            persona.setTexture(texIzquierda); // Izquierda
        }
    } else {    //mouse esta mas desplazado en la direccion vertical
        if (dy > 0) {
            persona.setTexture(texAbajo); // Abajo
        } else {
            persona.setTexture(texArriba); // Arriba
        }
    }

}

void Jugador::setSize(float width, float height){
    persona.setScale(width/persona.getLocalBounds().width, height/persona.getLocalBounds().height);
};