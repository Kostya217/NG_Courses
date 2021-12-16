#include <iostream>
#include "fighter.h"
#include "space_cruiser.h"
#include "flagship.h"

using namespace std;
int main()
{
	Fighter *fighter = new Fighter(10, 5, 6);
	Fighter* fighter1 = new Fighter(25, 10, 3);

	SpaceCruiser *cruiserOne = new SpaceCruiser(100, 10, 100, 20);
	SpaceCruiser *cruiserTwo = new SpaceCruiser(100, 500, 100, 10);

	cruiserOne->AddFighter(*fighter);
	cruiserOne->AddFighter(*fighter1);

	cout << "Free Place in cruiser : " << cruiserOne->GetFreePlaces() << endl;

	cout << "Overall Assessment Of Combat Strength is : " << cruiserOne->OverallAssessmentOfCombatStrength() << endl;
	cout << "Grade speed cruiser :  " << cruiserOne->GradeSpeed() << endl;

	Flagship* flagship = new Flagship(40, 100, 20);

	flagship->AddCruiser(*cruiserOne);
	flagship->AddCruiser(*cruiserTwo);

	cout << "Speed fleet : " << flagship->GetSpeedFleet();
	return 0;
}

