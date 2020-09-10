#pragma once
#include <string>
#include <vector>
#include "Transition.h"

using namespace std;

class Smol_Brain
{
	private:

		unsigned int pv = 10000;
		unsigned int meter = 0;
		unsigned int distance = 10;

		Etat current_state;

		Etat_neutral neutral_sol;
		Etat_avancer avancer;
		Etat_zoning zoning;
		Etat frappe_sol;
		Etat_combo combo;
		Etat super;
		Etat_punish punish;
		Etat victoire;
		Etat mort;

	public:

		//constructeur
		Smol_Brain();

		//gain de meter
		void AddMeter();

		//perte de point de vie
		void TakeDamage();

		void ReduceDistance(bool i);

		~Smol_Brain();

		//getteur sur l'état courant
		string GetState();

		//choisir le prochain état
		void Next_State();
};

class Etat
{
protected:

	string nom;

	vector<pair<Transition*, Etat*>> transitions;
	unsigned int nbTransition;

public:

	Etat();
	const unsigned int GetNbTrans() const;

	//getteur sur la transition
	pair<Transition*, Etat*> GetTrans(const unsigned int i);

	//constructeur
	Etat(const string n, const unsigned int nb_trans);

	//ajout d'une transition à l'état
	void AjoutTransition(Transition* t, Etat* e);

	//destructeur
	~Etat();

	//getteur du nom de l'etat
	const string GetNom() const;

	virtual void Effet(Smol_Brain* b);
};

class Etat_neutral : public Etat
{
public:

	Etat_neutral();
	Etat_neutral(const string n, const unsigned int nb);
	void Effet(Smol_Brain* b);
};

class Etat_combo : public Etat
{
public:

	Etat_combo(const string n, const unsigned int nb);
	void Effet(Smol_Brain* b);
};

class Etat_punish : public Etat
{
public:

	Etat_punish(const string n, const unsigned int nb);
	void Effet(Smol_Brain* b);
};

class Etat_avancer : public Etat
{
public:

	Etat_avancer(const string n, const unsigned int nb);
	void Effet(Smol_Brain* b);
};

class Etat_zoning : public Etat
{
public:

	Etat_zoning(const string n, const unsigned int nb);
	void Effet(Smol_Brain* b);
};

