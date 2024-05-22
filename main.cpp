#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(400, 400), "SFML works!");
    Texture fondoprueba;

     if(!fondoprueba.loadFromFile("teturas/fondoprueba.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    Sprite fondo;
    fondo.setTexture(fondoprueba);
    fondo.setTextureRect(IntRect(0,0,400,400));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(51,51,51));
        window.draw(fondoprueba);
        window.display();
    }

    return 0;
}