#include "Penguin.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


sf::Texture* Penguin::texture = NULL;
int Penguin::instances = 0;

Penguin::Penguin()
{
    instances++;
}

Penguin::Penguin(double m, double b) : Animal(m, b)
{
    instances++;
}


Penguin::Penguin(double m, double b, int _x, int _y) : Animal(m, b, _x, _y)
{
    instances++;
}

Penguin::~Penguin()
{
    // This is a very thin place of the Forest.
    // Mind that if any Penguin will be politely deleted she will be bully enough
    // to take the Penguin kind common face with her.

    delete s;
    s = NULL;
    instances--;
    if (instances == 0 && texture)
    {
        delete texture;
        texture = NULL;
    }
}

void Penguin::talk()
{
    cout <<"Urrr-Urrr-Urrr" <<endl;
}

// Penguins have a lot in common with cats.
// But cats are smarter.
// Better ask cats.

void Penguin::setSprite()
{
    delete s;
    s = NULL;
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/Penguin.png"))
            cout <<"Penguin went wrong" <<endl;
    }
    s = new sf::Sprite(*texture);
    s->setTexture(*texture);
}
