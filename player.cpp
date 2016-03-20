#include "player.h"

Player::Player(ImageManager imageManager, std::string name, int life, int level, int xp, Map map)
{
    this->type = 0;
    this->imageManager = imageManager;

    this->name = name;
    this->life = life;
    this->level = level;
    this->xp = xp;
    this->map = map;
}

void Player::move()
{

}

Player::~Player()
{

}

