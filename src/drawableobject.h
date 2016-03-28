#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <SFML/Graphics.hpp>
#include <imagemanager.h>
#include <map.h>

#include <string>
#include <iostream>

class DrawableObject
{
protected:
    int type;
    int x;
    int y;
    std::vector <sf::Sprite> sprite;
    ImageManager imageManager;
    Map map;

public:

    void draw(sf::RenderWindow &app);
    void setPosition(int x, int y);
    sf::Vector2f getPosition();
    int getType();

};

#endif // DRAWABLEOBJECT_H
