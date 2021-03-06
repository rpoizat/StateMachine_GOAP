#pragma once
#include "pch.h"
#include "Transition.h"
#include <iostream>
//condition sur le nombre de pv
bool TransitionIsAlive::Process(const unsigned int pv, const unsigned short int meter, const unsigned short int distance)
{
	if (pv > 0) return true;
	else return false;
}

//condition sur la barre de super
bool TransitionMeter::Process(const unsigned int pv, const unsigned short int meter, const unsigned short int distance)
{
	if (meter >= 3)
	{
		return true;
	}
	else return false;
}

//condition sur la garde de l'adversaire
bool TransitionIsBlocked::Process(const unsigned int pv, const unsigned short int meter, const unsigned short int distance)
{
	unsigned int r = std::rand() / ((RAND_MAX + 1u) / 1);

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

//condition sur la distance qui s�pare les joueurs
bool TransitionCheckDistance::Process(const unsigned int pv, const unsigned short int meter, const unsigned short int distance)
{
	if (distance <= min) return true;
	else return false;
}

//condition sur l'�tat Combo
bool TransitionCombo::Process(const unsigned int pv, const unsigned short int meter, const unsigned short int distance)
{
	return true;
}

bool TransitionMort::Process(const unsigned int pv, const unsigned short int meter, const unsigned short int distance)
{
	return true;
}

bool TransitionVictoire::Process(const unsigned int pv, const unsigned short int meter, const unsigned short int distance)
{
	return true;
}