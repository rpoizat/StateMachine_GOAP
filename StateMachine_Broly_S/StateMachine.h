#pragma once

#include <string>
#include <vector>
#include "Etat.h"

using namespace std;

class SmolBrain
{
private:

	Etat *current_state;

	Etat_neutral* neutral_sol;
	Etat_avancer* avancer;
	Etat_zoning* zoning;
	Etat* frappe_sol;
	Etat_combo* combo;
	Etat* super;
	Etat_punish* punish;
	Etat* victoire;
	Etat* mort;

	Data donnees;

public:

	//constructeur
	SmolBrain();

	~SmolBrain();

	//getteur sur l'état courant
	string GetState();

	//choisir le prochain état
	void Next_State();

	Data& GetDataForEdit();
};
