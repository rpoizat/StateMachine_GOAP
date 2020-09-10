#pragma once

#include <iostream>
#include "pch.h"
#include <vector>
#include "Transition.hpp"

using namespace std;

class Etat
{
	protected: 

		string nom;

		vector<pair<Transition*, Etat*>> transitions;
		unsigned int nbTransition;

	public:

		Etat()
		{
			nbTransition = 0;
			nom = "";
		}

		unsigned int GetNbTrans()
		{
			return nbTransition;
		}

		//getteur sur la transition
		pair<Transition*, Etat*> GetTrans(unsigned int i)
		{
			return transitions[i];
		}

		//constructeur
		Etat(string n, unsigned int nb_trans)
		{
			nom = n;
			transitions.resize(nb_trans);
			nbTransition = nb_trans;
		}

		//ajout d'une transition à l'état
		void AjoutTransition(Transition* t, Etat* e)
		{
			transitions.push_back(make_pair(t, e));
		}

		//destructeur
		~Etat()
		{
			for (unsigned int i = 0; i < nbTransition; i++)
			{
				delete(&transitions);
			}
		}

		//getteur du nom de l'etat
		string GetNom() const
		{
			return nom;
		}

		virtual void Effet(Smol_Brain b) {};
};

class Etat_neutral : public Etat
{
public:

	Etat_neutral(string n, unsigned int nb)
	{
		nom = n;
		nbTransition = nb;
	}
	void Effet(Smol_Brain b) {};
};

class Etat_combo : public Etat
{
public:

	Etat_combo(string n, unsigned int nb)
	{
		nom = n;
		nbTransition = nb;
	}

	void Effet(Smol_Brain b)
	{
		//gain de meter
		b.AddMeter();
	}
};

class Etat_punish : public Etat
{
public:

	Etat_punish(string n, unsigned int nb)
	{
		nom = n;
		nbTransition = nb;
	}

	void Effet(Smol_Brain b)
	{
		//gain de meter
		b.TakeDamage();
	}
};

class Etat_avancer : public Etat
{
public:

	Etat_avancer(string n, unsigned int nb)
	{
		nom = n;
		nbTransition = nb;
	}

	void Effet(Smol_Brain b)
	{
		//gain de meter
		b.ReduceDistance(true);
	}
};

class Etat_zoning : public Etat
{
public:

	Etat_zoning(string n, unsigned int nb)
	{
		nom = n;
		nbTransition = nb;
	}

	void Effet(Smol_Brain b)
	{
		//gain de meter
		b.ReduceDistance(false);
	}
};