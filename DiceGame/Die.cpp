#include "Die.h";
#include <cstdlib>;
#include <ctime>;

Die::Die(int faces)
{
	size = faces;
	srand(time(0));
}

int Die::getRoll()
{
	return roll;
}

int Die::rollDie()
{
	
	roll = rand() % size + 1;
	return roll;
}