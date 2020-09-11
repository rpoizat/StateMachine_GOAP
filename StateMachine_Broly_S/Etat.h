#pragma once
#ifndef ETAT_H
#define ETAT_H

#include <vector>
#include <string>
#include "Transition.h"
#include "Data.h"

using namespace std;


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

	virtual void Effet(Data* b);
};

class Etat_neutral : public Etat
{
public:

	Etat_neutral();
	Etat_neutral(const string n, const unsigned int nb);
	void Effet(Data* b);
};

class Etat_combo : public Etat
{
public:

	Etat_combo() {}
	Etat_combo(const string n, const unsigned int nb);
	void Effet(Data* b);
};

class Etat_punish : public Etat
{
public:

	Etat_punish(){}
	Etat_punish(const string n, const unsigned int nb);
	void Effet(Data* b);
};

class Etat_avancer : public Etat
{
public:

	Etat_avancer(){}
	Etat_avancer(const string n, const unsigned int nb);
	void Effet(Data* b);
};

class Etat_zoning : public Etat
{
public:

	Etat_zoning(){}
	Etat_zoning(const string n, const unsigned int nb);
	void Effet(Data* b);
};

#endif // ETAT_H
