// StateMachine_Broly_S.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "pch.h"
#include <iostream>
#include "StateMachine.h"

int main()
{
	//créer la state machine
	SmolBrain broly;

	cout << broly.GetState() << " distance : " << broly.GetDataForEdit().GetDistance() << endl;

	while (broly.GetState() != "VICTOIRE" && broly.GetState() != "DEFAITE")
	{
		broly.Next_State();
	}
	cout << "FIN" << endl;
}