#include <iostream>
#include <SFML/Graphics.hpp>
// #include "rlutil.h"
using namespace sf;
using namespace std;
#include "Jugador.hpp"

int main()
{
    RenderWindow window(VideoMode(200, 200), "SFML works!");

    Texture fondoprueba;
    fondoprueba.loadFromFile("texturas/bc.png");
    Sprite fondo;
    fondo.setTexture(fondoprueba);
    fondo.setTextureRect(IntRect(0, 0, 200, 200));

    Texture tex;
    tex.loadFromFile("texturas/tex.png"); 
    


    // Jugador::cargarTexturas();
    // if(!fondoprueba.loadFromFile("texturas/bc.png"))
    //{
    //   cout << "Error al cargar imagen" << endl;
    //}

    Jugador jugador("Player1", 100, 10);
    jugador.persona.setTexture(tex); 
    // jugador.persona.setTexture(jugador.tex);

    jugador.setSize(100, 100);
    jugador.aparecer(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::A))
            jugador.mover(window, Keyboard::A);
            
        if (Keyboard::isKeyPressed(Keyboard::D))
            jugador.mover(window, Keyboard::D);

        if (Keyboard::isKeyPressed(Keyboard::W))
            jugador.mover(window, Keyboard::W);
        
        if (Keyboard::isKeyPressed(Keyboard::S))
            jugador.mover(window, Keyboard::S);
        
        if (Keyboard::isKeyPressed(Keyboard::A))
            jugador.mover(window, Keyboard::A);


        jugador.apuntar(window);

        window.clear();
        window.draw(fondo);
        jugador.draw(window);
        window.display();
    }

    return 0;
}
