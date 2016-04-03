#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <map.h>

#include <coordinates.h>

#define START_SCREEN "ressources/images/menus/StartScreen.jpg" // to be modified, not a sprite, this is an example

class ImageManager
{
private:

    std::string textureType;
    int size;
    std::vector <std::string> textureFiles; //erase
    std::map<std::string,std::string> textureFiles;
    sf::Texture texture;
    std::vector <std::pair <sf::Sprite, Coordinates> > listeSprites;

public:

    ImageManager();

    void loadTexture(std::string textureType);
    void makeSprites();
    void getSprites(std::string textureType, std::vector <sf::Sprite> sprites);
    ~ImageManager();
};

#endif // IMAGEMANAGER_H
