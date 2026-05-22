#include "Mushroom.h"
#include "Forest.h"

#include<iostream>
#include <SFML/Graphics.hpp>

#define R 2

using namespace std;

vector <Mushroom*> Mushroom::Mycellium = vector<Mushroom*>();
int Mushroom::Mycellium_state = 0;
sf::Texture* Mushroom::texturedown = NULL;
sf::Texture* Mushroom::textureup = NULL;
int Mushroom::instances = 0;

Mushroom::Mushroom(): state(true)
{
    instances++;
    Mycellium.push_back(this);
    mNumber = Mycellium.size() - 1;
}

Mushroom::Mushroom(double m) : Plant(m), state(true)
{
    instances++;
    Mycellium.push_back(this);
    mNumber = Mycellium.size() - 1;
}
Mushroom::Mushroom(double m, int _x, int _y): Plant(m, _x, _y), state(true)
{
    instances++;
    Mycellium.push_back(this);
    mNumber = Mycellium.size() - 1;
}

Mushroom::~Mushroom()
{
    delete s;
    s = NULL;
    for (int i = 0; i < Mycellium.size(); i++)
    {
        if(Mycellium[i] == this) {
            Mycellium.erase(Mycellium.begin() + i);
            break;
        }
    }
    instances--;
    if (instances == 0)
    {
        delete textureup;
        delete texturedown;
        textureup = NULL;
        texturedown = NULL;
    }
}

void Mushroom::setSprite()
{
    delete s;
    s = NULL;
    if (!textureup)
    {
        textureup = new sf::Texture;
        if(!(textureup->loadFromFile("res/mushrooms/Mushroom_up.png")))
            cout << "Mushroom went wrong" << endl;
    }

        if (!texturedown)
    {
        texturedown = new sf::Texture;
        if(!(texturedown->loadFromFile("res/mushrooms/Mushroom_down.png")))
            cout << "Mushroom went wrong" << endl;
    }
    s = new sf::Sprite(*textureup);
    s->setTexture(*textureup);
}

void Mushroom::grow(Forest* f) {
    int _x = x;
    int _y = y;
    for(int i = 0 - R; i < 1 + R; i++)
        for (int j = 0 - R; j < 1 + R; j++)
            if ( (j||i) && !(f->checkAnimals(_x + i, _y + j)) ) {
                s->setTexture(*texturedown);
                state=false;
                return;
            }
    if(!state) {
        s->setTexture(*textureup);
        state = true;
    }

}
