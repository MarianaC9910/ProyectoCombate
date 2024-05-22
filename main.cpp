#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(400, 400), "SFML works!");
    Texture fondoprueba;

     if(!fondoprueba.loadFromFile("texturas/fondoprueba.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    fondoprueba.setRepeated(true);

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

        window.clear();
        window.draw(fondo);
        window.display();
    }

    return 0;
}