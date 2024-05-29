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
    //Jugador::cargarTexturas();


    if(!fondoprueba.loadFromFile("texturas/fondoprueba.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    fondoprueba.setRepeated(true);

    Sprite fondo;
    fondo.setTexture(fondoprueba);
    fondo.setTextureRect(IntRect(0,0,200,200));

  
    Jugador jugador("Player1", 100, 10);
    jugador.persona.setTexture(jugador.tex);

    jugador.setSize(100,100);
    jugador.aparecer(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        jugador.mover();
        jugador.apuntar(window);

        window.clear();
        window.draw(fondo);
        jugador.draw(window);
        window.display();
    }

    return 0;
}
