#include "flagship.h"

Flagship::Flagship(int health, int speed, int armor)
{
    this->health = health;
    this->speed = speed;
    this->armor = armor;
}

void Flagship::AddCruiser(SpaceCruiser cruiser) {
    flagshipComand.push_back(cruiser);
}

int Flagship::GetSpeedFleet() {
    speedFleet = flagshipComand[0].GetSpeed();
    for (int i = 0; i < indexCruiser; i++)
    {
        if (speedFleet > flagshipComand[i].GetSpeed()) {
            speedFleet = flagshipComand[i].GetSpeed();
        }
    }
    return speedFleet;
}
