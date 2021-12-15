#ifndef Fighter_H
#define Fighter_H
#include "space_plane.h"
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
    void SetDamage(int damage) { this->damage = damage; }
    int GetDamage() { return damage; }
private:
    int damage = 0;
};
#endif 


