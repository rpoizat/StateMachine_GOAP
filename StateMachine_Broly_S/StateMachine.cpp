#include "StateMachine.h"
#include "pch.h"
#include <iostream>

//constructeur
Smol_Brain::Smol_Brain()
{
	neutral_sol = Etat_neutral("NEUTRAL", 3);
	avancer = Etat_avancer("SUPER DASH", 3);
	zoning = Etat_zoning("ZONING", 2);
	frappe_sol = Etat("AUTO COMBO", 1);
	combo = Etat_combo("COMBO", 2);
	super = Etat("LV3", 1);
	punish = Etat_punish("PUNISH", 2);
	victoire = Etat("VICTOIRE", 0);
	mort = Etat("MORT", 0);

	neutral_sol.AjoutTransition(new TransitionCheckDistance(0), &frappe_sol);
	neutral_sol.AjoutTransition(new TransitionCheckDistance(8), &avancer);
	neutral_sol.AjoutTransition(new TransitionCheckDistance(10), &zoning);

	frappe_sol.AjoutTransition(new TransitionIsBlocked(), &punish); //sinon combo
	frappe_sol.AjoutTransition(new TransitionCombo(), &combo);
	combo.AjoutTransition(new TransitionMeter(), &super); //sinon neutral
	combo.AjoutTransition(new TransitionIsAlive(), &neutral_sol);
	punish.AjoutTransition(new TransitionIsAlive, &neutral_sol); //sinon defaite
	punish.AjoutTransition(new TransitionMort(), &mort);
	zoning.AjoutTransition(new TransitionIsBlocked(), &punish); //sinon combo
	zoning.AjoutTransition(new TransitionCombo(), &combo);

	super.AjoutTransition(new TransitionVictoire(), &victoire);

	avancer.AjoutTransition(new TransitionCheckDistance(0), &frappe_sol);
	avancer.AjoutTransition(new TransitionCheckDistance(8), &avancer);
	avancer.AjoutTransition(new TransitionCheckDistance(10), &zoning);

	//état de départ
	current_state = neutral_sol;
}

//destructeur
Smol_Brain::~Smol_Brain()
{

}

//gain de meter
void Smol_Brain::AddMeter()
{
	meter++;
}

//perte de point de vie
void Smol_Brain::TakeDamage()
{
	pv -= 2500;
}

//réduction de la distance
void Smol_Brain::ReduceDistance(bool i)
{
	if (i) distance = 0;
	else distance -= rand() % distance;
}

//getteur sur l'état courant
string Smol_Brain::GetState()
{
	return current_state->GetNom();
}

//choisir le prochain état
void Smol_Brain::Next_State()
{
	unsigned int taille = current_state->GetNbTrans();

	string s = current_state->GetNom();
	cout << "ETAT : " << s << endl;

	//passer à l'état suivant
	for (unsigned int i = 0; i < taille; i++)
	{
		auto current_Trans = current_state->GetTrans(i);
		Transition* t = current_Trans.first;

		if (t->Process(pv, meter, distance))
		{
			current_state = current_Trans.second;
			current_state->Effet(this);
		}
	}
}