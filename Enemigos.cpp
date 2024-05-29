#include "Enemigos.hpp"
// #include "rlutil.h"

    Enemigo::Enemigo(){
        // enemigo.setTexture(this->mounstruo);
    }

    Enemigo::Enemigo(int vid){
        this->vida = vid;
        // enemigo.setTexture(mounstruo);
    }
    Enemigo::Enemigo(int vid, int dan){
        this->vida = vid;
        this->danio = dan;
        // enemigo.setTexture(mounstruo);
    }
    void Enemigo::cargarTexturas(){
        // if (!mounstruo.loadFromFile("texturas/tex.jpg"))
    {
        cout << "Error al cargar la textura" << endl;
    }

    // if (!textura_derecha.loadFromFile("texturas/der.jpg"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_izquierda.loadFromFile("texturas/izq.jpg"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_arriba.loadFromFile("texturas/frente.jpg"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_arriba_d.loadFromFile("texturas/diagonal_ad.jpg"))
    // {
    //     cout << "Error al cargar la textura" << endl;;
    // }
    
    // if (!textura_arriba_i.loadFromFile("texturas/diagonal_ai.jpg"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_abajo.loadFromFile("texturas/atras.jpg"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_abajo_d.loadFromFile("texturas/diagonal_atd.jpg"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    
    // if (!textura_abajo_i.loadFromFile("texturas/diagonal_ati.jpg"))
    // {
    //     cout << "Error al cargar la textura" << endl;
    // }
    }
    void draw(RenderWindow& window){

    }
    void mover(){}
    //revisa coordenadas del jugador y se mueve hacia ellas
    void aparecer(int x, int y){}
    void atacar(){}
    void apuntar(RenderWindow& window){}
    void setSize(float width, float height){}
