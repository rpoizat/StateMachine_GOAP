#include "Action.h"

Effet* Action::getEffet() const{

    return effet;

}

unsigned int Action::getCout() const {

    return cout;

}

string Action::getNom() const {

    return nom;

}

Effet* Action::getPrerequis() const {

    return prerequis;

}

//constructeur
Action::Action(const int cout, const string nom, Effet* effet, Effet* unePrecondition) {

    this->cout = cout;
    this->nom = nom;
    this->effet = effet;
    this->prerequis = unePrecondition;

}




