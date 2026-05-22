#include "Sundew.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Sundew::texture = NULL;
int Sundew::instances = 0;

Sundew::Sundew()
{
    instances++;
}

Sundew::Sundew(double m): Plant(m)
{
    instances++;
}

Sundew::Sundew(double m, int _x, int _y): Plant(m, _x, _y)
{
    instances++;
}

Sundew::~Sundew()
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

// Sundews wait for insects but to no avail.
// They are angry and vicious and definitely not talkative.
// I asked the cats and they grudgingly agreed to help you.

void Sundew::setSprite()
{
    delete s;
    s = NULL;
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/sundew.png"))
            cout <<"Sundew went wrong" <<endl;
    }
    s = new sf::Sprite(*texture);
    s->setTexture(*texture);
}
