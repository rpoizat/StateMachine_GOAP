#pragma once
#include "pch.h"
#include "StateMachine.h"
#include <iostream>

//constructeur
SmolBrain::SmolBrain()
{
	neutral_sol = new Etat_neutral("NEUTRAL", 3);
	avancer = new Etat_avancer("SUPER DASH", 3);
	zoning = new Etat_zoning("ZONING", 2);
	frappe_sol = new Etat("LA FRAPPE", 1);
	combo = new Etat_combo("COMBO", 2);
	super = new Etat("LV3", 1);
	punish = new Etat_punish("PUNISH", 2);
	victoire = new Etat("VICTOIRE", 0);
	mort = new Etat("MORT", 0);

	neutral_sol->AjoutTransition(new TransitionCheckDistance(1), frappe_sol);
	neutral_sol->AjoutTransition(new TransitionCheckDistance(8), avancer);
	neutral_sol->AjoutTransition(new TransitionCheckDistance(10), zoning);

	frappe_sol->AjoutTransition(new TransitionIsBlocked(), punish); //sinon combo
	frappe_sol->AjoutTransition(new TransitionCombo(), combo);
	combo->AjoutTransition(new TransitionMeter(), super); //sinon neutral
	combo->AjoutTransition(new TransitionIsAlive(), neutral_sol);
	punish->AjoutTransition(new TransitionIsAlive, neutral_sol); //sinon defaite
	punish->AjoutTransition(new TransitionMort(), mort);
	zoning->AjoutTransition(new TransitionIsBlocked(), punish); //sinon combo
	zoning->AjoutTransition(new TransitionCombo(), combo);

	super->AjoutTransition(new TransitionVictoire(), victoire);

	avancer->AjoutTransition(new TransitionCheckDistance(0), frappe_sol);
	avancer->AjoutTransition(new TransitionCheckDistance(8), avancer);
	avancer->AjoutTransition(new TransitionCheckDistance(10), zoning);

	//état de départ
	current_state = neutral_sol;

	donnees = Data();
}

//destructeur
SmolBrain::~SmolBrain()
{
	delete(neutral_sol);
	neutral_sol = nullptr;
	delete(avancer);
	avancer = nullptr;
	delete(super);
	super = nullptr;
	delete(zoning);
	zoning = nullptr;
	delete(combo);
	combo = nullptr;
	delete(frappe_sol);
	frappe_sol = nullptr;
	delete(punish);
	punish = nullptr;
	delete(victoire);
	victoire = nullptr;
	delete(mort);
	mort = nullptr;
}

//getteur sur les données
Data& SmolBrain::GetDataForEdit()
{
	return donnees;
}

//getteur sur l'état courant
string SmolBrain::GetState()
{
	return current_state->GetNom();
}

//choisir le prochain état
void SmolBrain::Next_State()
{
	unsigned int taille = current_state->GetNbTrans();

	string s = current_state->GetNom();
	

	//passer à l'état suivant
	for (unsigned int i = 0; i < taille; i++)
	{
		auto current_Trans = current_state->GetTrans(i);
		Transition* t = current_Trans.first;

		if (t->Process(donnees.GetPv(), donnees.GetMeter(), donnees.GetDistance()))
		{
			current_state = current_Trans.second;
			current_state->Effet(&donnees);
		}
	}
}