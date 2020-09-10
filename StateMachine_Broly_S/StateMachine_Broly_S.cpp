// StateMachine_Broly_S.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "StateMachine.hpp"



int main()
{
	//créer la state machine
	Smol_Brain broly;

	while (broly.GetState().GetNom() != "VICTOIRE" || broly.GetState().GetNom() != "DEFAITE")
	{
		broly.Next_State();
	}

	cout << "FIN" << endl;
}