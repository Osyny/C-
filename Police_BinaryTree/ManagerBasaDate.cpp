#include "ManagerBasaDate.h"

void ManagerBasaDate::initDataBase(CarDataBase & dataBase)
{
	int numCars = rand() % 20 + 10;

	for (int i = 0; i < numCars; i++)
	{
		int carRandNumber = rand() % 1000 + 1;
		int numOffences = rand() % 7 + 3;
		for (int j = 0; j < numOffences; j++)
			dataBase.addOffence(carRandNumber, initRandOffence());
	}
}

const char * ManagerBasaDate::initRandOffence()
{
	int symb = 0;

	for (int i = 0; i < 5; i++)
	{
		symb = rand() % 4 + 1;
	}
	switch (symb)
	{
	case 1:
		return{ " Brove on the reed light.." };
		break;
	case 2:
		return{ " Stopped in the forbidden places." };
		break;
	case 3:
		return{ " Do not miss a pedestrian. " };
		break;
	case 4:
		return{ " Do not stop at stop sign. " };
		break;
	case 5:
		return{ " Crossed the double solid." };
		break;
	default:
		return{ "Undefined" };
		break;

	}
}
