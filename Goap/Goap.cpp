// Goap.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Action.h"
#include <vector>

class GoapPlanner {

	private:

		vector<Action> listeActions;

	public:


		vector<Action> proceder(string objectif, Ville uneVille) {

			int tailleListe = listeActions.size();

			int i = 0;
			bool drap = false;

			/*while (i < tailleListe && !drap) {

				if (listeActions[i].getPrerequis() == objectif) {

				}

			}*/

		}







};

int main()
{

	Effet* effetallumerFeu = new Effet(ALLUMERFEU);
	Effet* effetcreerVillageois = new Effet(CREERVILLAGEOIS);
	Effet* effetassigneraubois = new Effet(ASSIGNERAUBOIS);
	effetCouperBois* effetcouperBois = new effetCouperBois(COUPERBOIS);

	Action actionCouperBois(1, "coupe pour 50 de bois", effetcouperBois, effetcouperBois);

	Action actionAllumerFeu(1, "Allume un feu", effetallumerFeu, effetallumerFeu);




}


