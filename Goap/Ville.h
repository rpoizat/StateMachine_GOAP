#pragma once
class Ville
{

	private:

		int nombreVillageoisTotaux;
		int nombreVillageoisLibre;
		int nombreVillageoisBois;
		int boisTotal;

	public:

		Ville();

		Ville(int nombreVillageoisTotaux, int nombreVillageoisBois, int boisTotal);

		int getNombreVillageoisTotaux() const;
		int getNombreVillageoisLibre() const;
		int getNombreVillageoisBois() const;
		int getBoisTotal() const;

		void setNombreVillageoisTotaux(int unNombreDeVillageois);
		void setNombreVillageoisBois(int unNombreDeVillageois);
		void setNombreVillageoisLibre(int unNombreDeVillageois);
		void setBoisTotal(int unNombreDeRessource);

		void addNombreVillageoisTotaux(int unNombreDeVillageois);
		void addNombreVillageoisBois(int unNombreDeVillageois);
		void addNombreVillageoisLibre(int unNombreDeVillageois);
		void addBoisTotal(int unNombreDeRessource);




};

