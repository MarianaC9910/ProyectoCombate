#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include "Jugador.hpp"

int main()
{
    RenderWindow window(VideoMode(400, 400), "SFML works!");
    Texture fondoprueba;
    Jugador::cargarTextura("texturas/criculov.jpg"); //se carga la textura por defecto del jugador desde el inicio, como es una funcion estatica no ocupa de instancia de jugador


     if(!fondoprueba.loadFromFile("texturas/fondoprueba.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    fondoprueba.setRepeated(true);

    Sprite fondo;
    fondo.setTexture(fondoprueba);
    fondo.setTextureRect(IntRect(0,0,400,400));

  
    Jugador jugador("Player1", 100, 10);
   
    jugador.aparecer(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(fondo);
        jugador.draw(window);
        window.display();
    }

    return 0;
}