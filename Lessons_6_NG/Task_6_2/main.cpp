#include <iostream>
#include "fighter.h"
#include "spacecruiser.h"
#include "flagship.h"

using namespace std;
int main()
{
    Fighter* fighterOne = new Fighter(10, 5, 6);
    Fighter* fighterTwo = new Fighter(25, 10, 3);

    SpaceCruiser* cruiserOne = new SpaceCruiser(100, 10, 100, 20);
    SpaceCruiser* cruiserTwo = new SpaceCruiser(100, 500, 100, 10);

    cruiserOne->AddFighter(*fighterOne);
    cruiserOne->AddFighter(*fighterTwo);

    cout << "Free Place in cruiser : " << cruiserOne->GetFreePlaces() << endl;
    cout << "Overall Assessment Of Combat Strength is : " << cruiserOne->OverallAssessmentOfCombatStrength() << endl;
    cout << "Grade speed cruiser :  " << cruiserOne->GradeSpeed() << endl;

    Flagship* flagship = new Flagship(40, 100, 20);

    flagship->AddCruiser(*cruiserOne);
    flagship->AddCruiser(*cruiserTwo);

    cout << "Speed fleet : " << flagship->GetSpeedFleet();

    return 0;
}

