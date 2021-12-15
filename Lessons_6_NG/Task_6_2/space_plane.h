#pragma once
#ifndef Space_Plane_H
#define Space_Plane_H

class SpacePlane
{
public : 
	SpacePlane(){}
	SpacePlane(int health, int speed)
	{
		this->health = health;
		this->speed = speed;
	}

	void SetHealth(int health) { this->health = health; }
	int GetHealth() { return health; }

	void SetSpeed(int speed) { this->speed = speed; }
	int GetSpeed() { return speed; }

protected : 
	int health = 0;
	int speed = 0;
};
#endif 



