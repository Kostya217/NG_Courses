#ifndef FIGHTER_H
#define FIGHTER_H
#include "spaceplane.h"

class Fighter : public SpacePlane
{
public:
    Fighter() {}
    Fighter(int damage, int health, int speed)
    {
        this->damage = damage;
        this->health = health;
        this->speed = speed;
    }
    ~Fighter(){}
    void SetDamage(int damage) { this->damage = damage; }
    int GetDamage() { return damage; }
private:
    int damage = 0;
};

#endif // FIGHTER_H
