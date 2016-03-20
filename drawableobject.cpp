#include "drawableobject.h"

void DrawableObject::draw(sf::RenderWindow &app)
{
    //app.draw(this->sprite);
}

void DrawableObject::setPosition(int x, int y)
{
    this->setPosition(x,y);
    //this->sprite.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f DrawableObject::getPosition()
{
    return this->getPosition();
}

int DrawableObject::getType()
{
    return this->type;
}
