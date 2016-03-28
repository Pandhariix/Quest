#ifndef CHARACTER_H
#define CHARACTER_H

#include <drawableobject.h>

class Character : public DrawableObject
{
protected:
    std::string name;
    int life;
    int level;
    int speed;

public:
    Character();

    virtual void move()=0;

    ~Character();

};

#endif // CHARACTER_H
