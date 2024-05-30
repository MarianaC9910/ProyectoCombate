#include "Jugador.hpp"
#include <conio.h>
// #include "rlutil.h"

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

// void Jugador::apuntar(RenderWindow &window)
// {

//     // posición del mouse en relación con la ventana
//     Vector2i mousePos = Mouse::getPosition(window);

//     // posición del jugador en relación con la ventana
//     Vector2f jugadorPos = persona.getPosition();

//     // diferencia entre la posición del mouse y la posición del jugador
//     float dx = mousePos.x - jugadorPos.x;
//     float dy = mousePos.y - jugadorPos.y;

//     // Calcular el ángulo entre la posición del jugador y la posición del mouse
//     float angle = std::atan2(dy, dx) * (180.0f / M_PI); // esto es como una manera de escribir pi

//     // Redondear el ángulo a múltiplos de 45 grados porque solo tendremos 8 direcciones posibles en las que mire el personaje
//     angle = round(angle / 45.0f) * 45.0f;

//     // Girar el sprite del jugador según el ángulo calculado
//     persona.setRotation(angle);

//     if (angle == 0.0f)
//         persona.setTexture(textura_derecha);

//     else if (angle == 45.0f)
//         persona.setTexture(textura_arriba_d);

//     else if (angle == 90.0f)
//         persona.setTexture(textura_arriba);

//     else if (angle == 135.0f)
//         persona.setTexture(textura_arriba_i);

//     else if (angle == 180.0f || angle == -180.0f)
//         persona.setTexture(textura_izquierda);

//     else if (angle == -135.0f)
//         persona.setTexture(textura_abajo_i);

//     else if (angle == -90.0f)
//         persona.setTexture(textura_abajo);

//     else if (angle == -45.0f)
//         persona.setTexture(textura_abajo_d);
// }

void Jugador::setSize(float width, float height){
    persona.setScale(width/persona.getLocalBounds().width, height/persona.getLocalBounds().height);
};