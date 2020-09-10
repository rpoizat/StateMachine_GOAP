#pragma once
#include "pch.h"
#include "StateMachine.h"


//constructeur
Etat::Etat()
{
	nbTransition = 0;
	nom = "";
}

//constructeur
Etat::Etat(const string n, const unsigned int nb_trans)
{
	nom = n;
	transitions.resize(nb_trans);
	nbTransition = nb_trans;
}

//destructeur
Etat::~Etat()
{
	for (unsigned int i = 0; i < nbTransition; i++)
	{
		delete(&transitions);
	}
}

//getteur sur le nombre de transition
const unsigned int Etat::GetNbTrans() const
{
	return nbTransition;
}

//getteur sur la transition
pair<Transition*, Etat*> Etat::GetTrans(const unsigned int i)
{
	return transitions[i];
}

//getteur sur la transition
pair<Transition*, Etat*> Etat::GetTrans(const unsigned int i)
{
	return transitions[i];
}

//ajout d'une transition à l'état
void Etat::AjoutTransition(Transition* t, Etat* e)
{
	transitions.push_back(make_pair(t, e));
}

//getteur du nom de l'etat
const string Etat::GetNom() const
{
	return nom;
}

void Etat::Effet(Smol_Brain* b)
{

}

Etat_neutral::Etat_neutral()
{
	nom = "Neutral";
	nbTransition = 0;
}

//constructeur neutral
Etat_neutral::Etat_neutral(string n, unsigned int nb)
{
	nom = n;
	nbTransition = nb;
}

void Etat_neutral::Effet(Smol_Brain* b)
{

}

//constructeur combo
Etat_combo::Etat_combo(const string n, const unsigned int nb)
{
	nom = n;
	nbTransition = nb;
}

void Etat_combo::Effet(Smol_Brain* b)
{
	//gain de meter
	b->AddMeter();
}

//constructeur punish
Etat_punish::Etat_punish(const string n, const unsigned int nb)
{
	nom = n;
	nbTransition = nb;
}

void Etat_punish::Effet(Smol_Brain* b)
{
	//perte de point de vies
	b->TakeDamage();
}

//constructeur avancer
Etat_avancer::Etat_avancer(const string n, const unsigned int nb)
{
	nom = n;
	nbTransition = nb;
}

void Etat_avancer::Effet(Smol_Brain* b)
{
	//gain de meter
	b->ReduceDistance(true);
}

//constructeur zoning
Etat_zoning::Etat_zoning(const string n, const unsigned int nb)
{
	nom = n;
	nbTransition = nb;
}

void Etat_zoning::Effet(Smol_Brain* b)
{
	//gain de meter
	b->ReduceDistance(false);
}