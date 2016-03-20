#include "imagemanager.h"

ImageManager::ImageManager()
{
    this->textureFiles.resize(1);

    //define the different textures
    //standard grass
    this->textureFiles[0] = "Images/Game/Terrain/standard_grass.png";
}

void ImageManager::loadTexture(int type)
{

    this->type = type;

    if(!this->texture.loadFromFile(this->textureFiles[type]))
        std::cerr<<"Unable to load the texture "<<type<<std::endl;

}

void ImageManager::makeSprites()
{

    this->listeSprites.clear();

    switch(this->type)
    {
        //standard grass
        case 0:
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

void ImageManager::getSprites(int type, std::vector<sf::Sprite> sprites)
{
    this->loadTexture(type);
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

