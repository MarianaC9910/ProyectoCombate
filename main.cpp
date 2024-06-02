#include <iostream>
#include <SFML/Graphics.hpp>
// #include "rlutil.h"
using namespace sf;
using namespace std;
#include "Jugador.hpp"
#include "Enemigos.hpp"
#include <vector>
//#include "Balas.hpp"

bool juegoTerminado = false;

int main()
{
    vector<Enemigo>enemigos;
    int killCount=0;
    int eVivos=1;

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

    Texture monster_up;
    monster_up.loadFromFile("texturas/monster_up.png"); 

    Texture monster_down; 
    monster_down.loadFromFile("texturas/monster_down.png"); 

    Texture monster_der; 
    monster_der.loadFromFile("texturas/monster_der.png"); 

    Texture monster_izq; 
    monster_izq.loadFromFile("texturas/monster_izq.png"); 

    Jugador jugador("Player1", 100, 10);
    jugador.persona.setTexture(tex);

    jugador.setSize(120, 120);

    Vector2u windowSize = window.getSize();
    float startX = windowSize.x / 2.0f - jugador.persona.getGlobalBounds().width / 2.0f;
    float startY = windowSize.y / 2.0f - jugador.persona.getGlobalBounds().height / 2.0f;
    jugador.aparecer(startX, startY);

    float startXE, startYE;
    for(int i=0;i<4;i++){
        Enemigo enemigo(50, 50, i+1);
        switch(enemigo.tipo){
            case 1://arriba
                startXE = windowSize.x / 2.0f - enemigo.mounstruo.getGlobalBounds().width / 2.0f;
                startYE = windowSize.y / 2.0f - enemigo.mounstruo.getGlobalBounds().height / 2.0f-380.0f;
                enemigo.mounstruo.setTexture(monster_down);
            break;
            case 2://derecha
                startXE = windowSize.x / 2.0f - enemigo.mounstruo.getGlobalBounds().width / 2.0f+300.0f;
                startYE = windowSize.y / 2.0f - enemigo.mounstruo.getGlobalBounds().height / 2.0f;
                enemigo.mounstruo.setTexture(monster_izq);
            break;
            case 3://abajo
                startXE = windowSize.x / 2.0f - enemigo.mounstruo.getGlobalBounds().width / 2.0f+100.0f;
                startYE = windowSize.y / 2.0f - enemigo.mounstruo.getGlobalBounds().height / 2.0f+300.0f;
                enemigo.mounstruo.setTexture(monster_up);
            break;
            case 4://izquierda
                startXE = windowSize.x / 2.0f - enemigo.mounstruo.getGlobalBounds().width / 2.0f-380.0f;
                startYE = windowSize.y / 2.0f - enemigo.mounstruo.getGlobalBounds().height / 2.0f+100.0f;
                enemigo.mounstruo.setTexture(monster_der);
            break;
            default:
            break;
        }
        enemigo.setSize(100, 100);
        enemigo.aparecer(startXE,startYE);
        enemigos.push_back(enemigo);
    }
    

    while (window.isOpen())
    {
        while(juegoTerminado==false){
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
        if (Keyboard::isKeyPressed(Keyboard::E))
        {
            jugador.mover(window, Keyboard::E);
        }

        Vector2i mousePos = Mouse::getPosition(window);
        jugador.apuntar(window, mousePos, der, izq, frente, atras);
        for(int i=0;i<enemigos.size(); i++){
            enemigos[i].mover(window, jugador);
        }


        window.clear();
        window.draw(fondo);
        jugador.draw(window);
        for(int i=0;i<enemigos.size();i++){
            enemigos[i].draw(window);
        }
        window.display();
        }
    }

    return 0;
}
