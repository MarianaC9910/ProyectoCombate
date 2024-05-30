#include <iostream>
#include <SFML/Graphics.hpp>
// #include "rlutil.h"
using namespace sf;
using namespace std;
#include "Jugador.hpp"

int main()
{
    RenderWindow window(VideoMode(800, 800), "SFML works!");
    window.setFramerateLimit(60);

    Texture fondoprueba;
    fondoprueba.loadFromFile("texturas/bc1.png");
    Sprite fondo;
    fondo.setTexture(fondoprueba);
    fondo.setTextureRect(IntRect(0, 0, 800, 800));

    Texture bulletv;
    bulletv.loadFromFile("texturas/bullet_v");

    Texture bulleth;
    bulleth.loadFromFile("texturas/bullet_h");

    Texture tex;
    tex.loadFromFile("texturas/tex.png");

    Texture der;
    der.loadFromFile("texturas/der.png");

    Texture izq;
    izq.loadFromFile("texturas/izq.png");

    Texture frente;
    frente.loadFromFile("texturas/frente.png");

    Texture atras;
    atras.loadFromFile("texturas/atras.png");

    Font font; 
    font.loadFromFile("ARCADECLASSIC.TTF"); 

    //contador de kills
    Text killcounter; 
    killcounter.setFont(font); 
    killcounter.setCharacterSize(10); 
    killcounter.setFillColor(Color::White);
    killcounter.setPosition(10,10);  


    Jugador jugador("Player1", 100, 10);
    jugador.persona.setTexture(tex);

    jugador.setSize(120, 120);

    Vector2u windowSize = window.getSize();
    float startX = windowSize.x / 2.0f - jugador.persona.getGlobalBounds().width / 2.0f;
    float startY = windowSize.y / 2.0f - jugador.persona.getGlobalBounds().height / 2.0f;
    jugador.aparecer(startX, startY);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            jugador.mover(window, Keyboard::A);
            jugador.persona.setTexture(izq);
        }

        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            jugador.mover(window, Keyboard::D);
            jugador.persona.setTexture(der);
        }

        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            jugador.mover(window, Keyboard::W);
            jugador.persona.setTexture(frente);
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            jugador.mover(window, Keyboard::S);
            jugador.persona.setTexture(atras);
        }

        Vector2i mousePos = Mouse::getPosition(window);
        jugador.apuntar(window, mousePos, der, izq, frente, atras);


        window.clear();
        window.draw(fondo);
        jugador.draw(window);
        window.draw(killcounter); 
        window.display();
    }

    return 0;
}
