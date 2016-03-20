#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

#include <coordinates.h>

class ImageManager
{
private:

    int type;
    int size;
    std::vector <std::string> textureFiles;
    sf::Texture texture;
    std::vector <std::pair <sf::Sprite, Coordinates> > listeSprites;

public:

    ImageManager();

    void loadTexture(int type);
    void makeSprites();
    void getSprites(int type, std::vector <sf::Sprite> sprites);
    ~ImageManager();
};

#endif // IMAGEMANAGER_H
