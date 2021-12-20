#ifndef SPACECRUISER_H
#define SPACECRUISER_H
#include "spaceplane.h"
#include "fighter.h"
#include <vector>

using namespace std;

class SpaceCruiser : public SpacePlane
{
public:
    SpaceCruiser() {}
    SpaceCruiser(int armor, int freePlaces, int health, int speed);
    void SetArmor(int armor) { this->armor = armor; }
    int GetArmor() { return armor; }

    void SetFreePlaces(int freePlaces) { this->freePlaces = freePlaces;}
    int GetFreePlaces() { return freePlaces; }

    void AddFighter(Fighter fighter);

    int OverallAssessmentOfCombatStrength();

    int GradeSpeed();
    ~SpaceCruiser(){ fighter.clear(); }
private:
    int armor = 0;
    int freePlaces = 0;
    vector<Fighter> fighter;
    int indexFighter = 0;
};

#endif // SPACECRUISER_H
