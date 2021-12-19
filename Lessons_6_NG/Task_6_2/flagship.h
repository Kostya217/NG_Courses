#ifndef FLAGSHIP_H
#define FLAGSHIP_H
#include "spaceplane.h"
#include "spacecruiser.h"

class Flagship : public SpacePlane
{
public:

    Flagship() {}
    ~Flagship() {}
    Flagship(int health, int speed, int armor)
    {
        this->health = health;
        this->speed = speed;
        this->armor = armor;
    }
    void SetArmor(int armor) { this->armor = armor; }
    int GetArmor() { return armor; }

    void AddCruiser(SpaceCruiser cruiser) {
        flagshipComand[indexCruiser++] = cruiser;
    }

    int GetSpeedFleet() {
        speedFleet = flagshipComand[0].GetSpeed();
        for (int i = 0; i < indexCruiser; i++)
        {
            if (speedFleet > flagshipComand[i].GetSpeed()) speedFleet = flagshipComand[i].GetSpeed();
        }
        return speedFleet;
    }

private:
    int speedFleet = 0;
    int armor = 0;
    int indexCruiser = 0;
    SpaceCruiser* flagshipComand = new SpaceCruiser[0];

};
#endif // FLAGSHIP_H
