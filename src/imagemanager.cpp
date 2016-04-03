#include "imagemanager.h"

ImageManager::ImageManager()
{
    this->textureFiles.emplace("start_screen",START_SCREEN);
}

void ImageManager::loadTexture(std::string textureType)
{

    this->textureType = textureType;

    if(!this->texture.loadFromFile(this->textureFiles[textureType]))
        std::cerr<<"Unable to load the texture "<<textureType<<std::endl;

}

void ImageManager::makeSprites()
{

    this->listeSprites.clear();

    switch(this->textureType)
    {
        //standard grass, TODO
        case "standard_grass":
        this->listeSprites.resize(1);
        this->size= 1;
        this->listeSprites[0].second.x=0;
        this->listeSprites[0].second.y=0;
        this->listeSprites[0].second.width=0;
        this->listeSprites[0].second.length=0;
        break;
    }

    for(int i=0;i<this->size;i++)
    {
        this->listeSprites[i].first.setTextureRect(sf::IntRect(this->listeSprites[i].second.x,
                                                         this->listeSprites[i].second.y,
                                                         this->listeSprites[i].second.width,
                                                         this->listeSprites[i].second.length));
    }

}

void ImageManager::getSprites(std::string textureType, std::vector<sf::Sprite> &sprites)
{
    this->loadTexture(textureType);
    this->makeSprites();


    sprites.resize(this->size);

    for(int i=0;i<this->size;i++)
    {
        sprites[0] = this->listeSprites[i].first;
    }
}

ImageManager::~ImageManager()
{

}

