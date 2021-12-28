#ifndef FLAGSHIP_H
#define FLAGSHIP_H
#include "spaceplane.h"
#include "spacecruiser.h"
#include <vector>
using namespace std;

class Flagship : public SpacePlane
{
public:

    Flagship() {}
    Flagship(int health, int speed, int armor);
    void SetArmor(int armor) { this->armor = armor; }
    int GetArmor() { return armor; }

    void AddCruiser(SpaceCruiser cruiser);

    int GetSpeedFleet();

    ~Flagship() { flagshipComand.clear(); }

private:
    int speedFleet = 0;
    int armor = 0;
    int indexCruiser = 0;
    vector<SpaceCruiser> flagshipComand;
};
#endif // FLAGSHIP_H
