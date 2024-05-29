#include "Jugador.hpp"
#include <conio.h>
// #include "rlutil.h"

Jugador::Jugador()
{
    if (!tex.loadFromFile("texturas/tex.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }

     if (!textura_derecha.loadFromFile("texturas/der.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_izquierda.loadFromFile("texturas/izq.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_arriba.loadFromFile("texturas/frente.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_arriba_d.loadFromFile("texturas/diagonal_ad.png"))
     {
         cout << "Error al cargar la textura" << endl;;
     }
    
     if (!textura_arriba_i.loadFromFile("texturas/diagonal_ai.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo.loadFromFile("texturas/atras.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo_d.loadFromFile("texturas/diagonal_atd.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo_i.loadFromFile("texturas/diagonal_ati.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    persona.setTexture(tex);
};

Jugador::Jugador(string nom)
{
    if (!tex.loadFromFile("texturas/tex.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }

     if (!textura_derecha.loadFromFile("texturas/der.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_izquierda.loadFromFile("texturas/izq.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_arriba.loadFromFile("texturas/frente.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_arriba_d.loadFromFile("texturas/diagonal_ad.png"))
     {
         cout << "Error al cargar la textura" << endl;;
     }
    
     if (!textura_arriba_i.loadFromFile("texturas/diagonal_ai.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo.loadFromFile("texturas/atras.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo_d.loadFromFile("texturas/diagonal_atd.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo_i.loadFromFile("texturas/diagonal_ati.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    this->nombre = nom;
    persona.setTexture(tex);
}
Jugador::Jugador(string nom, int vid)
{
    if (!tex.loadFromFile("texturas/tex.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }

     if (!textura_derecha.loadFromFile("texturas/der.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_izquierda.loadFromFile("texturas/izq.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_arriba.loadFromFile("texturas/frente.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_arriba_d.loadFromFile("texturas/diagonal_ad.png"))
     {
         cout << "Error al cargar la textura" << endl;;
     }
    
     if (!textura_arriba_i.loadFromFile("texturas/diagonal_ai.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo.loadFromFile("texturas/atras.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo_d.loadFromFile("texturas/diagonal_atd.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo_i.loadFromFile("texturas/diagonal_ati.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    this->nombre = nom;
    this->vida = vid;
    persona.setTexture(tex);
}
Jugador::Jugador(string nom, int vid, int dan)
{
    if (!tex.loadFromFile("texturas/tex.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }

     if (!textura_derecha.loadFromFile("texturas/der.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_izquierda.loadFromFile("texturas/izq.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_arriba.loadFromFile("texturas/frente.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_arriba_d.loadFromFile("texturas/diagonal_ad.png"))
     {
         cout << "Error al cargar la textura" << endl;;
     }
    
     if (!textura_arriba_i.loadFromFile("texturas/diagonal_ai.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo.loadFromFile("texturas/atras.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo_d.loadFromFile("texturas/diagonal_atd.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }
    
     if (!textura_abajo_i.loadFromFile("texturas/diagonal_ati.png"))
     {
         cout << "Error al cargar la textura" << endl;
     }

    this->nombre = nom;
    this->vida = vid;
    this->danio = dan;
    persona.setTexture(tex);
}

void Jugador::draw(RenderWindow &window)
{
    window.draw(persona);
}

void Jugador::mover(RenderWindow &window, Keyboard::Key key)
{

    // la diferencia entre Vector2u y 2f es que el 2f usa valores float que pueden ser negativos y el 2u solo usa enteros sin signos negativos

    Vector2u ventanaSize = window.getSize(); // obtenemos las medidas de la ventana que se va a mostrar

    int windowWidth = ventanaSize.x;  // obtenemos el ancho de la ventana
    int windowHeight = ventanaSize.y; // obtenemos el alto de la ventana

    switch (key)
    {
    case Keyboard::W:
        if (posy > 0)
            posy--;
        break;
    case Keyboard::A:
        if (posx > 0)
            posx--;
        break;
    case Keyboard::D:
        if (posx < windowWidth - persona.getGlobalBounds().width)
            posx++;
        break;
    case Keyboard::S:
        if (posy < windowHeight - persona.getGlobalBounds().height)
            posy++;
        break;
    case Keyboard::E:
        atacar();
    }

    persona.setPosition(posx, posy);
}

void Jugador::cargarTexturas()
{
    // if (!tex.loadFromFile("texturas/tex.png"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }

    // if (!textura_derecha.loadFromFile("texturas/der.png"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_izquierda.loadFromFile("texturas/izq.png"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_arriba.loadFromFile("texturas/frente.png"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_arriba_d.loadFromFile("texturas/diagonal_ad.png"))
    // {
    //     cout << "Error al cargar la textura" << endl;;
    // }
    
    // if (!textura_arriba_i.loadFromFile("texturas/diagonal_ai.png"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_abajo.loadFromFile("texturas/atras.png"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_abajo_d.loadFromFile("texturas/diagonal_atd.png"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_abajo_i.loadFromFile("texturas/diagonal_ati.png"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
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

void Jugador::setSize(float width, float height){
    persona.setScale(width/persona.getLocalBounds().width, height/persona.getLocalBounds().height);
};