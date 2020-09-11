#include <iostream>
#include <string>
#include "ville.h"
#include "effet.h"

using namespace std;

class Action
{
protected:

    int cout;

    string nom;

    Effet* effet;

    Effet* prerequis;


public:

    //constructeur
    Action();

    //constructeur
    Action(const int cout, const string nom, Effet* effet, Effet* unePrecondition);

    //getteur effet
    Effet* getEffet() const;

    //getteur cout
    unsigned int getCout() const;

    //getteur nom
    string getNom() const;

    //getteur nom
    Effet* getPrerequis() const;

    //destructeur
    ~Action();


};

