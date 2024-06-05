#include <iostream>
#include <SFML/Graphics.hpp>
// #include "rlutil.h"
using namespace sf;
using namespace std;
#include "Jugador.hpp"
#include "Enemigos.hpp"
#include <vector>
#include "Balas.hpp"

Texture bulletv;
Texture bulleth;    

vector<Enemigo>enemigos;
RenderWindow window(VideoMode(800, 800), "SFML works!");
Texture monster_down, monster_izq, monster_der, monster_up;
Vector2u windowSize = window.getSize();
bool juegoTerminado = false;
void generarEnemigos(int cant);
bool intersectaJ(Jugador player, Bala disp);
bool intersectaE(Enemigo enemy, Bala disp);
void reiniciarPartida(Jugador player);

    int killCount=0;
    int oActual=2;
    int sobrevivientes= 0;
    int partidas = 1;

int main()
{
    
    window.setFramerateLimit(60);

    Texture fondoprueba;
    fondoprueba.loadFromFile("texturas/bc1.png");
    Sprite fondo;
    fondo.setTexture(fondoprueba);
    fondo.setTextureRect(IntRect(0, 0, 800, 800));

    Texture bulletv;
    bulletv.loadFromFile("texturas/bullet_v.png");

    Texture bulleth;
    bulleth.loadFromFile("texturas/bullet_h.png");

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
        if(sobrevivientes<=0&&juegoTerminado==false){
            oActual++;
            sobrevivientes=0;
            jugador.reiniciar();
            generarEnemigos(oActual);
        }

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
            if(jugador.disparos[i].estado==true){
                jugador.disparos[i].mover(window);
                for(int j=0;j<enemigos.size();j++){
                    if(intersectaE(enemigos[j], jugador.disparos[i])==true){
                        enemigos[j].vivo=false;
                        jugador.disparos[i].estado=false;
                    }
                }
            }
        }
        /*for(int i=0;i<jugador.disparos.size();i++){
            jugador.disparos.erase(jugador.disparos.begin()+i);
        }*/
        for(int i=0;i<enemigos.size();i++){
            if(enemigos[i].vivo==false){
                enemigos.erase(enemigos.begin()+i);
                sobrevivientes--;
                killCount++;
            }
        }
        for(int i=0;i<enemigos.size(); i++){
            if(enemigos[i].vivo=true){
                enemigos[i].mover(window, jugador);
                for(int j=0;j<enemigos[i].disparos.size();j++){
                    if(enemigos[i].disparos[j].estado==true){
                        enemigos[i].disparos[j].mover(window);
                        if(intersectaJ(jugador, enemigos[i].disparos[j]) == true){
                            jugador.atacado();
                            enemigos[i].disparos[j].estado=false;
                            //enemigos[i].disparos.erase(enemigos[i].disparos.begin()+i);
                            if(jugador.getVida()<=0){
                                juegoTerminado=true;
                            }
                        }

                    }
                }
            }
            
        }
        

        
        window.clear();
        window.draw(fondo);
        jugador.draw(window);
        for(int i=0;i<jugador.disparos.size();i++){
            if(jugador.disparos[i].estado==true)
                jugador.disparos[i].draw(window);
        }
        for(int i=0;i<enemigos.size();i++){
            if(enemigos[i].vivo==true){
                enemigos[i].draw(window);
                for(int j=0;j<enemigos[i].disparos.size();j++){
                    if(enemigos[i].disparos[j].estado==true)
                        enemigos[i].disparos[j].draw(window);
                }
            }
        }
        window.display();
        
        if(juegoTerminado==true){
            reiniciarPartida(jugador);
        }; 
    }
    cout<<"Resultados"<<endl;
    cout<<"Partidas jugadas: "<<partidas<<endl;
    cout<<"total de enemigos eliminados: "<<killCount<<endl;

    return 0;
}

void generarEnemigos(int cant){
    float startXE, startYE;
    for(int i=0;i<cant;i++){
        Enemigo enemigo(50, 50, i%5);
        inicio:
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
                enemigo.tipo=1;
                goto inicio;
            break;
        }
        sobrevivientes++;
        enemigo.setSize(100, 100);
        enemigo.aparecer(startXE,startYE);
        enemigos.push_back(enemigo);
    }
}
bool intersectaJ(Jugador player, Bala disp){
    bool interX=false;
    bool interY=false;
    int x1,x2,x3,x4,y1,y2,y3,y4;
    x1=player.posx+25.0f;
    y1=player.posy;    
    x2=player.posx+72.0f;
    y2=player.posy+120.0f;
    
    x3=disp.posx;
    x4=disp.posx+disp.ancho;
    y3=disp.posy;
    y4=disp.posy+disp.alto;

    if((x3>=x1&&x3<=x2)||(x4>=x1&&x4<=x2)){
        interX=true;
    }
    if((y3>=y1&&y3<=y2)||(y4>=y1&&y4<=y2)){
        interY=true;
    }
    if(interX==true&&interY==true){
        return true;
    }else{
        return false;
    }
}
bool intersectaE(Enemigo enemy, Bala disp){
    bool interX=false;
    bool interY=false;
    int x1,x2,x3,x4,y1,y2,y3,y4;
    switch(enemy.tipo){
        case 1:
            x1=enemy.posx+20.0f;
            y1=enemy.posy+20.0f;    
            x2=enemy.posx+75.0f;
            y2=enemy.posy+85.0f;
        break;
        case 2:
            x1=enemy.posx+15.0f;
            y1=enemy.posy+15.0f;    
            x2=enemy.posx+60.0f;
            y2=enemy.posy+75.0f;
        break;
        case 3:
            x1=enemy.posx+20.0f;
            y1=enemy.posy+5.0f;    
            x2=enemy.posx+80.0f;
            y2=enemy.posy+60.0f;
        break;
        case 4:
            x1=enemy.posx+25.0f;
            y1=enemy.posy+10.0f;    
            x2=enemy.posx+75.0f;
            y2=enemy.posy+75.0f;
        break;
        default:
        break;
    }
    
    
    x3=disp.posx;
    x4=disp.posx+disp.ancho;
    y3=disp.posy;
    y4=disp.posy+disp.alto;

    if((x3>=x1&&x3<=x2)||(x4>=x1&&x4<=x2)){
        interX=true;
    }
    if((y3>=y1&&y3<=y2)||(y4>=y1&&y4<=y2)){
        interY=true;
    }
    if(interX==true&&interY==true){
        disp.estado=false;
        return true;
    }else{
        return false;
    }
}
void reiniciarPartida(Jugador player){
    oActual=1;
    sobrevivientes=0;
    killCount=0;
    float startX = windowSize.x / 2.0f - player.persona.getGlobalBounds().width / 2.0f;
    float startY = windowSize.y / 2.0f - player.persona.getGlobalBounds().height / 2.0f;
    player.aparecer(startX, startY);
    enemigos.clear();
    player.reiniciar();
    juegoTerminado=false;
    partidas++;
}
