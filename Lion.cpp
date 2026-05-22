#include "Lion.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Lion::texture = NULL;
int Lion::instances = 0;

Lion::Lion()
{
    instances++;
}

Lion::Lion(double m, double b) : Animal(m, b)
{
    instances++;
}


Lion::Lion(double m, double b, int _x, int _y) : Animal(m, b, _x, _y)
{
    instances++;
}

Lion::~Lion()
{
    delete s;
    s = NULL;
    instances--;
    if (instances == 0 && texture)
    {
        delete texture;
        texture = NULL;
    }
}

void Lion::talk()
{
    cout <<"Arrrrrr!" <<endl;
}

// Lion have a lot in common with cats.
// But cats are smarter.
// Better ask cats.

void Lion::setSprite()
{
    delete s;
    s = NULL;
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/lion.png"))
            cout <<"Lion went wrong" <<endl;
    }
    s = new sf::Sprite(*texture);
    s->setTexture(*texture);
}
