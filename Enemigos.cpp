#include "Enemigos.hpp"
#include "rlutil.h"

    Enemigo::Enemigo(){
        enemigo.setTexture(mounstruo);
    }

    Enemigo::Enemigo(int vid){
        this->vida = vid;
        enemigo.setTexture(mounstruo);
    }
    Enemigo::Enemigo(int vid, int dan){
        this->vida = vid;
        this->danio = dan;
        enemigo.setTexture(mounstruo);
    }

    static void cargarTexturas();
    void draw(RenderWindow& window);
    void mover();//revisa coordenadas del jugador y se mueve hacia ellas
    void aparecer(int x, int y);
    void atacar();
    void apuntar(RenderWindow& window);
    void setSize(float width, float height);
