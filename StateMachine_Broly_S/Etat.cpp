#pragma once
#include "pch.h"
#include "Etat.h"
#include <iostream>

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

void Etat::Effet(Data* b)
{
	std::cout << nom << endl;
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

void Etat_neutral::Effet(Data* b)
{
	std::cout << "NEUTRAL distance : " << b->GetDistance() << std::endl;
}

//constructeur combo
Etat_combo::Etat_combo(const string n, const unsigned int nb)
{
	nom = n;
	nbTransition = nb;
}

void Etat_combo::Effet(Data* b)
{
	//gain de meter
	b->AddMeter();
	std::cout << " Combo Hit +1 Meter : " << b->GetMeter() << " de Meter" << std::endl;
}

//constructeur punish
Etat_punish::Etat_punish(const string n, const unsigned int nb)
{
	nom = n;
	nbTransition = nb;
}

void Etat_punish::Effet(Data* b)
{
	//perte de point de vies
	b->TakeDamage();
	std::cout << " Perte de 2500 PV : " << b->GetPv() << "pv restants" << std::endl;
}

//constructeur avancer
Etat_avancer::Etat_avancer(const string n, const unsigned int nb)
{
	nom = n;
	nbTransition = nb;
}

void Etat_avancer::Effet(Data* b)
{
	//gain de meter
	std::cout << " SUPER DASH ! ";
	b->ReduceDistance(true);
}

//constructeur zoning
Etat_zoning::Etat_zoning(const string n, const unsigned int nb)
{
	nom = n;
	nbTransition = nb;
}

void Etat_zoning::Effet(Data* b)
{
	//gain de meter
	std::cout << "ZONING ! ";
	b->ReduceDistance(false);
}