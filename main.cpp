#include <iostream>
#include <SFML/Graphics.hpp>
// #include "rlutil.h"
using namespace sf;
using namespace std;
#include "Jugador.hpp"
#include "Enemigos.hpp"
#include <vector>
//#include "Balas.hpp"
vector<Enemigo>enemigos;
RenderWindow window(VideoMode(800, 800), "SFML works!");
Texture monster_down, monster_izq, monster_der, monster_up;
Vector2u windowSize = window.getSize();
bool juegoTerminado = false;
void generarEnemigos(int cant);
bool intersectaJ(Jugador player, Bala disp);
bool intersectaE(Enemigo enemy, Bala disp);

int main()
{
    int killCount=0;
    int oActual=4;
    
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

    monster_up.loadFromFile("texturas/monster_up.png"); 
    monster_down.loadFromFile("texturas/monster_down.png"); 
    monster_der.loadFromFile("texturas/monster_der.png"); 
    monster_izq.loadFromFile("texturas/monster_izq.png"); 

    Jugador jugador("Player1", 100, 10);
    jugador.persona.setTexture(tex);

    jugador.setSize(120, 120);

    float startX = windowSize.x / 2.0f - jugador.persona.getGlobalBounds().width / 2.0f;
    float startY = windowSize.y / 2.0f - jugador.persona.getGlobalBounds().height / 2.0f;
    jugador.aparecer(startX, startY);

    generarEnemigos(oActual);

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
        for(int i=0;i<jugador.disparos.size();i++){
            jugador.disparos[i].mover(window);
        }
        for(int i=0;i<enemigos.size(); i++){
            enemigos[i].mover(window, jugador);
            for(int j=0;j<enemigos[i].disparos.size();j++){
                enemigos[i].disparos[j].mover(window);
                if(intersectaJ(jugador, enemigos[i].disparos[j]) == true){
                    jugador.atacado();
                    enemigos[i].disparos.erase(enemigos[i].disparos.begin()+i);
                    if(jugador.getVida()<=0){
                        juegoTerminado=true;
                    }
                }
            }
        }
        

        
        window.clear();
        window.draw(fondo);
        jugador.draw(window);
        for(int i=0;i<jugador.disparos.size();i++){
            jugador.disparos[i].draw(window);
        }
        for(int i=0;i<enemigos.size();i++){
            enemigos[i].draw(window);
            for(int j=0;j<enemigos[i].disparos.size();j++){
                enemigos[i].disparos[j].draw(window);
            }
        }
        window.display();
        }
    }

    return 0;
}

void generarEnemigos(int cant){
    float startXE, startYE;
    for(int i=0;i<cant;i++){
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
}
bool intersectaJ(Jugador player, Bala disp){
    bool interX, interY;
    if(disp.posx>=player.posx&&disp.posx<=player.posx+120.0f){
        bool interX=true;
    }else if(disp.posx+10.0f>=player.posx&&disp.posx+10.0f<=player.posx+120.0f){
        bool interX=true;
    }else{
        bool interX=false;
    }
    if(disp.posy>=player.posy&&disp.posy<=player.posy+120.0f){
        bool interY=true;
    }else if(disp.posy+10.0f>=player.posy&&disp.posy+10.0f<=player.posy+120.0f){
        bool interY=true;
    }else{
        bool interY=false;
    }
    if(interX==true&&interY==true){
        return true;
    }else{
        return false;
    }
}
bool intersectaE(Enemigo enemy, Bala disp){
    bool interX, interY;
    if(disp.posx>=enemy.posx&&disp.posx<=enemy.posx+100.0f){
        bool interX=true;
    }else if(disp.posx+10.0f>=enemy.posx&&disp.posx+10.0f<=enemy.posx+100.0f){
        bool interX=true;
    }else{
        bool interX=false;
    }
    if(disp.posy>=enemy.posy&&disp.posy<=enemy.posy+100.0f){
        bool interY=true;
    }else if(disp.posy+10.0f>=enemy.posy&&disp.posy+10.0f<=enemy.posy+100.0f){
        bool interY=true;
    }else{
        bool interY=false;
    }
    if(interX==true&&interY==true){
        return true;
    }else{
        return false;
    }
}
