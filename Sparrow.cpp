#include "Sparrow.h"

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Sparrow::texture = NULL;
int Sparrow::instances = 0;

Sparrow::Sparrow() {
    instances++;

}

Sparrow::Sparrow(double m, double b) : Animal(m, b) {
    instances++;
}


Sparrow::Sparrow(double m, double b, int _x, int _y) : Animal(m, b, _x, _y) {
    instances++;
}

Sparrow::~Sparrow() {
    delete s;
    s = NULL;
    instances--;
    if (instances == 0 && texture)
    {
        delete texture;
        texture = NULL;
    }
}

void Sparrow::talk() {
    cout <<"Chirick chirick chirick" <<endl;
}

void Sparrow::setSprite() {
    delete s;
    s = NULL;
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/sparrow.png"))
            cout <<"Sparrow fly wrong" <<endl;
    }
    s = new sf::Sprite(*texture);
    s->setTexture(*texture);
}
