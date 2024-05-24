#include "Jugador.hpp"
#include <conio.h>

Jugador::Jugador()
{
    persona.setTexture(tex);
};

Jugador::Jugador(string nom)
{
    this->nombre = nom;
    persona.setTexture(tex);
}
Jugador::Jugador(string nom, int vid)
{
    this->nombre = nom;
    this->vida = vid;
    persona.setTexture(tex);
}
Jugador::Jugador(string nom, int vid, int dan)
{
    this->nombre = nom;
    this->vida = vid;
    this->danio = dan;
    persona.setTexture(tex);
}

void Jugador::draw(RenderWindow &window)
{
    window.draw(persona);
}

void Jugador::mover()
{

    // la diferencia entre Vector2u y 2f es que el 2f usa valores float que pueden ser negativos y el 2u solo usa enteros sin signos negativos

    Vector2u ventanaSize = RenderWindow().getSize(); // obtenemos las medidas de la ventana que se va a mostrar

    int windowWidth = ventanaSize.x;  // obtenemos el ancho de la ventana
    int windowHeight = ventanaSize.y; // obtenemos el alto de la ventana

    switch (_getch())
    {
    case 'w':
        if (posy > 0)
            posy--;
        break;
    case 'a':
        if (posx > 0)
            posx--;
        break;
    case 'd':
        if (posx < windowWidth - persona.getGlobalBounds().width)
            posx++;
        break;
    case 's':
        if (posy < windowHeight - persona.getGlobalBounds().height)
            posy++;
        break;
    case 'e':
        atacar();
    }

    persona.setPosition(posx, posy);
}

//no he hecho las texturas, pero creo q sirve - Mel

void Jugador::cargarTexturas()
{
    if (!tex.loadFromFile("texturas/circulov.jpg"))
    {
        cout << "Error al cargar la textura por defecto" << endl;
    }

    if (!textura_derecha.loadFromFile("texturas/der.jpg"))
    {
        cout << "Error al cargar la textura por defecto" << endl;
    }
    
    if (!textura_izquierda.loadFromFile("texturas/izq.jpg"))
    {
        cout << "Error al cargar la textura por defecto" << endl;
    }
    
    if (!textura_arriba.loadFromFile("texturas/arr.jpg"))
    {
        cout << "Error al cargar la textura por defecto" << endl;
    }
    
    if (!textura_arriba_d.loadFromFile("texturas/arrd.jpg"))
    {
        cout << "Error al cargar la textura por defecto" << endl;
    }
    
    if (!textura_arriba_i.loadFromFile("texturas/arri.jpg"))
    {
        cout << "Error al cargar la textura por defecto" << endl;
    }
    
    if (!textura_abajo.loadFromFile("texturas/ab.jpg"))
    {
        cout << "Error al cargar la textura por defecto" << endl;
    }
    
    if (!textura_abajo_d.loadFromFile("texturas/abd.jpg"))
    {
        cout << "Error al cargar la textura por defecto" << endl;
    }
    
    if (!textura_abajo_i.loadFromFile("texturas/abi.jpg"))
    {
        cout << "Error al cargar la textura por defecto" << endl;
    }
}

void Jugador::aparecer(int x, int y)
{
    persona.setPosition(x, y);
}
void Jugador::atacar()
{
}

void Jugador::apuntar(RenderWindow &window)
{

    // posición del mouse en relación con la ventana
    Vector2i mousePos = Mouse::getPosition(window);

    // posición del jugador en relación con la ventana
    Vector2f jugadorPos = persona.getPosition();

    // diferencia entre la posición del mouse y la posición del jugador
    float dx = mousePos.x - jugadorPos.x;
    float dy = mousePos.y - jugadorPos.y;

    // Calcular el ángulo entre la posición del jugador y la posición del mouse
    float angle = std::atan2(dy, dx) * (180.0f / M_PI); // esto es como una manera de escribir pi

    // Redondear el ángulo a múltiplos de 45 grados porque solo tendremos 8 direcciones posibles en las que mire el personaje
    angle = round(angle / 45.0f) * 45.0f;

    // Girar el sprite del jugador según el ángulo calculado
    persona.setRotation(angle);

    if (angle == 0.0f)
        persona.setTexture(textura_derecha);

    else if (angle == 45.0f)
        persona.setTexture(textura_arriba_d);

    else if (angle == 90.0f)
        persona.setTexture(textura_arriba);

    else if (angle == 135.0f)
        persona.setTexture(textura_arriba_i);

    else if (angle == 180.0f || angle == -180.0f)
        persona.setTexture(textura_izquierda);

    else if (angle == -135.0f)
        persona.setTexture(textura_abajo_i);

    else if (angle == -90.0f)
        persona.setTexture(textura_abajo);

    else if (angle == -45.0f)
        persona.setTexture(textura_abajo_d);
}
