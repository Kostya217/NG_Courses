#ifndef SPACECRUISER_H
#define SPACECRUISER_H
#include "spaceplane.h"
#include "fighter.h"

class SpaceCruiser : public SpacePlane
{
public:
    SpaceCruiser() {}
    SpaceCruiser(int armor, int freePlaces, int health, int speed)
    {
        this->armor = armor;
        this->health = health;
        this->speed = speed;
        this->freePlaces = freePlaces;
        fighter = new Fighter[freePlaces];
    }
    void SetArmor(int armor) { this->armor = armor; }
    int GetArmor() { return armor; }

    void SetFreePlaces(int freePlaces) { this->freePlaces = freePlaces; }
    int GetFreePlaces() { return freePlaces; }

    void AddFighter(Fighter fighter) {
        this->fighter[indexFighter++] = fighter;
        freePlaces--;
    }

    int OverallAssessmentOfCombatStrength() {
        int totalDamage = 0;
        for (int i = 0; i < indexFighter; i++)
        {
            totalDamage += fighter[i].GetDamage();
        }
        return totalDamage;
    }

    int GradeSpeed() {
        int gradeSpeed = fighter[0].GetSpeed();
        for (int i = 0; i < indexFighter; i++)
        {
            if (fighter[i].GetSpeed() < gradeSpeed) gradeSpeed = fighter[i].GetSpeed();
        }
        return gradeSpeed;
    }
private:
    int armor = 0;
    int freePlaces = 0;
    Fighter* fighter = 0;
    int indexFighter = 0;
};

#endif // SPACECRUISER_H
