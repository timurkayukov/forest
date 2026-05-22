#include "Flower.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Flower::texture = NULL;
int Flower::instances = 0;

Flower::Flower()
{
    instances++;
    bloom = false;
}

Flower::Flower(double m): Plant(m)
{
    instances++;
    bloom = false;
}

Flower::Flower(double m, int _x, int _y): Plant(m, _x, _y)
{
    instances++;
    bloom = false;
}

Flower::~Flower()
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

// Flowers listen to the blowing wind.
// Try asking cats about this part.

void Flower::setSprite()
{
    delete s;
    s = NULL;
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/flower.png"))
            cout <<"Flower went wrong" <<endl;
    }
    s = new sf::Sprite(*texture);
    s->setTexture(*texture);
}
