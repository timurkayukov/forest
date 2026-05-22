#include "Fish.h"
#include "Forest.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

sf::Texture *Fish::texture = NULL;
int Fish::instances = 0;

Fish::Fish() : vx(1), vy(1) {
    instances++;
}

Fish::Fish(double m, double b) : Animal(m, b), vx(1), vy(1) {
    instances++;
}


Fish::Fish(double m, double b, int _x, int _y) : Animal(m, b, _x, _y), vx(1), vy(1) {
    instances++;
}

Fish::~Fish() {
    delete s;
    s = NULL;
    instances--;
    if (instances == 0 && texture) {
        delete texture;
        texture = NULL;
    }
}

void Fish::talk() {
    cout << "*Bubbles*" << endl; //Fish's underwater, what else can it say...
}

void Fish::setSprite() {
    delete s;
    s = NULL;
    if (!texture) {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/fish.png"))
            cout << "Fish went wrong" << endl;
    }
    s = new sf::Sprite(*texture);
    s->setTexture(*texture);
}

void Fish::walk(Forest *f) {
    if (!(f->check(x + vx, y))) { //Fish move in a specific way, not randomly. It swims from corner to corner, changing its direction if there's an obstacle
        vx *= -1;
    } else {
        x += vx;
        return;
    }
    if (!(f->check(x, y + vy))) {
        vy *= -1;
    }
    y += vy;
}
