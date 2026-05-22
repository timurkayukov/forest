#include "Cow.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


sf::Texture* Cow::texture = NULL;
int Cow::instances = 0;

Cow::Cow()
{
    instances++;
}

Cow::Cow(double m, double b) : Animal(m, b)
{
    instances++;
}


Cow::Cow(double m, double b, int _x, int _y) : Animal(m, b, _x, _y)
{
    instances++;
}

Cow::~Cow()
{
    // This is a very thin place of the Forest.
    // Mind that if any Cow will be politely deleted she will be bully enough
    // to take the cowkind common face with her.

    delete s;
    s = NULL;
    instances--;
    if (instances == 0 && texture)
    {
        delete texture;
        texture = NULL;
    }
}

void Cow::talk()
{
    cout <<"Moo" <<endl;
}

// Cows have a lot in common with cats.
// But cats are smarter.
// Better ask cats.

void Cow::setSprite()
{
    delete s;
    s = NULL;
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/cow.png"))
            cout <<"Cow went wrong" <<endl;
    }
    s = new sf::Sprite(*texture);
    s->setTexture(*texture);
}
