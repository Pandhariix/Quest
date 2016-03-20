#ifndef PLAYER_H
#define PLAYER_H

#include <character.h>

class Player : public Character
{
private:

    int xp;

public:

    Player(ImageManager imageManager, std::string name, int life, int level, int xp, Map map);
    void move();
    ~Player();
};

#endif // PLAYER_H
