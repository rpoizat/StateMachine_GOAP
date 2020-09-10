#include "Transition.h"
#include <iostream>
//condition sur le nombre de pv
bool TransitionIsAlive::Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
{
	if (pv > 0) return true;
	else return false;
}

//condition sur la barre de super
bool TransitionMeter::Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
{
	if (meter >= 3)
	{
		return true;
	}
	else return false;
}

//condition sur la garde de l'adversaire
bool TransitionIsBlocked::Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
{
	unsigned int r = rand() % 1;

	if (r == 1) return true;
	else
	{
		return false;
	}
}

//constructeur
TransitionCheckDistance::TransitionCheckDistance(unsigned int mi)
{
	min = mi;
}

//condition sur la distance qui sépare les joueurs
bool TransitionCheckDistance::Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
{
	if (distance <= min) return true;
	else return false;
}

//condition sur l'état Combo
bool TransitionCombo::Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
{
	return true;
}

bool TransitionMort::Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
{
	return true;
}

bool TransitionVictoire::Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
{
	return true;
}