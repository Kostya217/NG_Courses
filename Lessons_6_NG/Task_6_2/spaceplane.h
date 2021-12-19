#ifndef SPACEPLANE_H
#define SPACEPLANE_H


class SpacePlane
{
public:
    SpacePlane() {}
    ~SpacePlane(){}
    SpacePlane(int health, int speed)
    {
        this->health = health;
        this->speed = speed;
    }

    void SetHealth(int health) { this->health = health; }
    int GetHealth() { return health; }

    void SetSpeed(int speed) { this->speed = speed; }
    int GetSpeed() { return speed; }

protected:
    int health = 0;
    int speed = 0;
};

#endif // SPACEPLANE_H
