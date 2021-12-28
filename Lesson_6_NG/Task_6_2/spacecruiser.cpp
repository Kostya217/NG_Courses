#include "spacecruiser.h"

SpaceCruiser::SpaceCruiser(int armor, int freePlaces, int health, int speed)
{
    this->armor = armor;
    this->health = health;
    this->speed = speed;
    this->freePlaces = freePlaces;
}

void SpaceCruiser::AddFighter(Fighter fighter) {
    this->fighter.push_back(fighter);
    freePlaces--;
}

int SpaceCruiser::OverallAssessmentOfCombatStrength() {
    int totalDamage = 0;
    for (int i = 0; i < indexFighter; i++)
    {
        totalDamage += fighter[i].GetDamage();
    }
    return totalDamage;
}

int SpaceCruiser::GradeSpeed() {
    int gradeSpeed = fighter[0].GetSpeed();
    for (int i = 0; i < indexFighter; i++)
    {
        if (fighter[i].GetSpeed() < gradeSpeed){
            gradeSpeed = fighter[i].GetSpeed();
        }
    }
    return gradeSpeed;
}
